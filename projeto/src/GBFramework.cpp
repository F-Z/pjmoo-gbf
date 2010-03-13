////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#include "GBFramework.h"

namespace GBF {

//Destrutor
GBFramework::~GBFramework()
{
    std::cout << "[END].[Game Space]" << std::endl;

    delete(fpsSystem);
    delete(writeSystem);
//    delete(GraphicSystemImageBufferManager::getInstance());
    delete(Imagem::Layer::LayerManager::getInstance());
    delete(graphicSystemCore);
    delete(soundSystemCore);
    delete(inputSystemCore);

    SDL_Quit();
}
//Construtor
GBFramework::GBFramework()
{
    numscreenshot = 0;
    fps           = false;
}
//Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick),
//desenha na tela o conteúdo do backbuffer

void GBFramework::atualizar()
{
    try {
        fpsSystem->processar();

        if (isFPS()){
            //writeSystem->getFonte(Kernel::Write::WriteManager::defaultFont)->setAlpha(180);
            writeSystem->escrever(Kernel::Write::WriteManager::defaultFont,0,0,"FPS: %d",fpsSystem->getValor());
            //writeSystem->escrever(Kernel::Write::WriteManager::defaultFont,0,0,"FPS: %d",fpsSystem->getFPS());
            //writeSystem->getFonte(Kernel::Write::WriteManager::defaultFont)->setAlpha(255);
        }

        controleInterno();
        inputSystemCore->processar();
        graphicSystemCore->flip();
    } catch(...){
        std::cerr << " Error durante a execução do Jogo " << SDL_GetError() << std::endl;
    }
}
//Retorna o diretório base da aplicação corrente
std::string GBFramework::getPath()
{
    return Kernel::Util::Path::getPath();
}
//Inicializa o Sistema, e configura o modo gráfico
void GBFramework::iniciar(int width, int height, int bpp_color, bool full, GBF::Kernel::FPS::Tipo fps)
{
    std::cout << "GBF::Kernel::GBFramework::iniciar()" << std::endl;

    Kernel::Graphic::VideoConfig config;
    config.w     = width;
    config.h     = height;
    config.color = bpp_color;
    config.full  = full;
    graphicSystemCore->gsMode.setConfig(config);

    if (config.full){
        graphicSystemCore->gsMode.setModeFullScreen();
    } else {
        graphicSystemCore->gsMode.setModeWindowScreen();
    }

    graphicSystemCore->iniciar();

    inputSystemCore->iniciar();

    soundSystemCore->iniciar(22050,AUDIO_S16SYS,Kernel::Sound::CANAL_STEREO,2048,16);

    //input.mouse.Carregar(&pacote,"cursor.bmp");

    //Detecta o idioma padrão do ambiente (Sistema Operacional)
    writeSystem->idioma->autodetect();

    //FPS
    fpsSystem = Kernel::FPS::FPSFactory::criar(fps);
    //FPS primeira chamada
    fpsSystem->iniciar();


    //Carregando Fontes Padrões
    std::cout << "[*]Load Default" << std::endl;
    writeSystem->carregar(Kernel::Write::WriteManager::defaultFont,"data//kernel//fonte//default.png");

    graphicSystemCore->graphicSystem->imageBufferManager->loadFromFile("gbf-window-background","data//kernel//imagem//window-background.png");

    std::cout << "[BGN].[Game Space]" << std::endl;
}
//Informa se o mostrador de FPS está ativo
bool GBFramework::isFPS()
{
    return fps;
}
//Pausa o Sistema
void GBFramework::pausar()
{
}
//Mostra o Contador de FPS
void GBFramework::setFPS(bool show)
{
    fps=show;
}
//Informa o caminho do diretório base da aplicação corrente
void GBFramework::setPath(char * fullPath)
{
    std::string pathBase=Kernel::Util::StringExtract::extractPath(fullPath);

   // if (isDefaultPath()){
        Kernel::Util::Path::setPath(pathBase);
        //UtilLog::setArquivo(fullPath);
        //Kernel::Graphic::ImageBufferManager::setPathBase(pathBase);
        //Kernel::Sound::SoundManagerAbstract::setPathBase(pathBase);
        //Kernel::Write::Idioma::setPathBase(pathBase);
    //}
}
//Informação sobre o Autor e o Título da Aplicação.
//Obs.: Usado para arquivo de log e título da janela
void GBFramework::setTitulo(std::string titulo, std::string autor)
{
    std::cout << "[GAME - INFO]-------------------" << std::endl;
    std::cout << " Title: "   << titulo << std::endl;
    std::cout << " By: "      << autor  << std::endl;
    std::cout << "--------------------------------" << std::endl;

    carregar();
    setTitulo(titulo);
}
//Prepara o Ambiente para ser inicializado
void GBFramework::carregar()
{
    //Inicializando Gerador Randômico
    std::cout << "GBF::Kernel::GBFramework::carregar()" << std::endl;
    std::cout << "\tCPP: srand" << std::endl;
    srand(time(NULL));


    //Inicializando Video
    std::cout << "GBF::Kernel::Graphic" << std::endl;
    graphicSystemCore = new Kernel::Graphic::GraphicCore();
    Imagem::Layer::LayerManager::getInstance();

    //Inicializando Gerenciador de Fontes
    std::cout << "GBF::Kernel::Write" << std::endl;
    writeSystem = Kernel::Write::WriteManager::getInstance();

    //Inicializando Input
    std::cout << "GBF::Kernel::Input" << std::endl;
    inputSystemCore = new Kernel::Input::InputCore();

    //Inicializando Audio
    std::cout << "GBF::Kernel::Sound" << std::endl;
    soundSystemCore = new Kernel::Sound::SoundCore();
}
//Controle para ações internas
void GBFramework::controleInterno()
{
    //F10 = Alterna entre modo de controle exclusivo
    if (inputSystemCore->inputSystem->teclado->isKey(SDLK_F10)){
        inputSystemCore->alternarControleExclusivo();
    //F11 = Alterna entre modo tela Cheia e Janela
    } else if (inputSystemCore->inputSystem->teclado->isKey(SDLK_F11)){
        if (SDL_WM_ToggleFullScreen(graphicSystemCore->gsMode.getScreen())==0){
            std::cout << "SDL: SDL_WM_ToggleFullScreen nao suportado" << std::endl;
        }
    //F12 = Salva um screen do jogo
    } else if (inputSystemCore->inputSystem->teclado->isKey(SDLK_F12)){
        char tela[255];
        numscreenshot++;
        sprintf(tela,"%s//data//screen//screen%03d.bmp",getPath().c_str(),numscreenshot);
        graphicSystemCore->salvarScreenShot(tela);
    //F5 = Tira o Som
    } else if (inputSystemCore->inputSystem->teclado->isKey(SDLK_F5)){
        //audio.Mute();
    }
}
//Define o Título para Janela
void GBFramework::setTitulo(std::string titulo)
{
    SDL_WM_SetCaption(titulo.c_str(),NULL);
}

} // namespace GBF
