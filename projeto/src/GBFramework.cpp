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
//    UtilLog::cabecalho("Finalizando Ambiente do Escopo do Jogo");
//    UtilLog::cabecalho("Descarregando Framework");

    delete(fpsSystem);
    delete(writeSystem);
//    delete(GraphicSystemImageBufferManager::getInstance());
    delete(Imagem::Layer::LayerManager::getInstance());
    delete(graphicSystemCore);
    delete(soundSystemCore);
    delete(inputSystemCore);

  //  UtilLog::sistema("Removendo SDL");
    SDL_Quit();

    //UtilLog::cabecalho("Descarregando Completo do Framework");
    //UtilLog::finalizar();
}
//Construtor
GBFramework::GBFramework() 
{
    numscreenshot = 0;
    pathBase      = "";
    fps           = true;
    setDefaultPath(true);
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
        //UtilLog::tracer("SDL: %s", SDL_GetError());
        //UtilLog::tracer("SDL_Image: %s", IMG_GetError());
        //UtilLog::tracer("SDL_Mixer: %s", Mix_GetError());
    }
}
//Retorna o diretório base da aplicação corrente
std::string GBFramework::getPath() 
{
    return pathBase;
}
//Inicializa o Sistema, e configura o modo gráfico
void GBFramework::iniciar(int width, int height, int bpp_color, bool full) 
{
    //UtilLog::cabecalho("Inicializando Framework");
   // UtilLog::tracer("Inicializando ModoGráfico");


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

    //Carregando Fontes Padrões
    //UtilLog::tracer("Carregando Fonte Padrão para FonteManager");
    writeSystem->carregar(Kernel::Write::WriteManager::defaultFont,getPath()+"data//kernel//fonte//default.png");

    //UtilLog::tracer("Carregando Padrões para Fundo de Janelas");
    graphicSystemCore->graphicSystem->imageBufferManager->carregar("gbf-window-background","data//kernel//imagem//window-background.png");

    //Detecta o idioma padrão do ambiente (Sistema Operacional)
    writeSystem->idioma->detectarIdioma();

    //FPSTimer primeira chamada
    fpsSystem->iniciar();

    //UtilLog::cabecalho("Iniciando Ambiente para Escopo do Jogo");
}
bool GBFramework::isDefaultPath() 
{
    return defaultPath;
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
void GBFramework::setDefaultPath(bool ativo) 
{
    defaultPath=ativo;
}
//Mostra o Contador de FPS
void GBFramework::setFPS(bool show) 
{
    fps=show;
}
//Informa o caminho do diretório base da aplicação corrente
void GBFramework::setPath(char * fullPath) 
{
    pathBase=Kernel::Util::StringExtract::extractPath(fullPath);

    if (isDefaultPath()){
        //UtilLog::setArquivo(fullPath);
        Kernel::Graphic::ImageBufferManager::setPathBase(pathBase);
        Kernel::Sound::SoundManagerAbstract::setPathBase(pathBase);
        Kernel::Write::Idioma::setPathBase(pathBase);
    }
}
//Informação sobre o Autor e o Título da Aplicação.
//Obs.: Usado para arquivo de log e título da janela
void GBFramework::setTitulo(std::string titulo, std::string autor) 
{
//    UtilLog::setAutor(autor);
//    UtilLog::setProjeto(titulo);
    carregar();
    setTitulo(titulo);
}
//Prepara o Ambiente para ser inicializado 
void GBFramework::carregar() 
{
    //Inicializando Log
//    UtilLog::iniciar();

    //Inicializando Gerador Randômico
   // UtilLog::sistema("Inicializando Gerador Randômico");
    srand(time(NULL));

    //Inicializando FPS do jogo
    fpsSystem = Kernel::Timer::FPSFactory::criar(Kernel::Timer::FPS_CONTADOR);

    //Inicializando Video
    graphicSystemCore = new Kernel::Graphic::GraphicCore();
    Imagem::Layer::LayerManager::getInstance();

    //Inicializando Gerenciador de Fontes
    writeSystem = Kernel::Write::WriteManager::getInstance();

    //Inicializando Input
    inputSystemCore = new Kernel::Input::InputCore();

    //Inicializando Audio
    soundSystemCore = new Kernel::Sound::SoundCore();

   // UtilLog::cabecalho("Carregamento Completo do Framework");
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
            //UtilLog::getInstance()->inicializando("GBF :: Aviso");
            //UtilLog::getInstance()->comentario("Sem Suporte a troca entre FullScreen e WindowScreen");
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
