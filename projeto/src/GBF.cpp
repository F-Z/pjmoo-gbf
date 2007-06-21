////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "GBF.h"

//Construtor
GBF::GBF() 
{
    numscreenshot = 0;
    pathBase      = "";
    fps           = true;
    setDefaultPath(true);
}
//Destrutor
GBF::~GBF() 
{
    UtilLog::cabecalho("Finalizando Ambiente do Escopo do Jogo");
    UtilLog::cabecalho("Descarregando Framework");

    delete(fpsSystem);
    delete(writeSystem);
    delete(GraphicSystemImageBufferManager::getInstance());
    delete(FrameLayerManager::getInstance());
    delete(graphicSystem);
    //delete(GraphicSystemScreen::getInstance());
    delete(soundSystem);
    delete(inputSystem);

    UtilLog::sistema("Removendo SDL");
    SDL_Quit();

    UtilLog::cabecalho("Descarregando Completo do Framework");
    UtilLog::finalizar();
}
//Informa��o sobre o Autor e o T�tulo da Aplica��o.
//Obs.: Usado para arquivo de log e t�tulo da janela
void GBF::setTitulo(std::string titulo, std::string autor) 
{
    UtilLog::setAutor(autor);
    UtilLog::setProjeto(titulo);
    carregar();
    setTitulo(titulo);
}
//Inicializa o Sistema, e configura o modo gr�fico
void GBF::iniciar(int width, int height, int bpp_color, bool full) 
{
    UtilLog::cabecalho("Inicializando Framework");
    UtilLog::tracer("Inicializando ModoGr�fico");

    VideoConfig config;
    config.w     = width;
    config.h     = height;
    config.color = bpp_color;
    config.full  = full;
    graphicSystem->gsMode->setConfig(config);

    if (config.full){
        graphicSystem->gsMode->setModeFullScreen();
    } else {
        graphicSystem->gsMode->setModeWindowScreen();
    }
    graphicSystem->sincronizar();

    //input.mouse.Carregar(&pacote,"cursor.bmp");

    //Inicializando Sistema de Audio
    soundSystem->iniciar(22050,AUDIO_S16SYS,CANAL_STEREO,2048,16);

    //Carregando Fontes Padr�es
    UtilLog::tracer("Carregando Fontes Padr�es para FonteManager");
    writeSystem->carregar(WriteSystemFontDefault::console,getPath()+"data//kernel//fonte//console.png");
    writeSystem->carregar(WriteSystemFontDefault::pumpdemi,getPath()+"data//kernel//fonte//pumpdemi.png");
    writeSystem->carregar(WriteSystemFontDefault::fixedsys,getPath()+"data//kernel//fonte//fixedsys.png");
    writeSystem->carregar(WriteSystemFontDefault::arial,getPath()+"data//kernel//fonte//arial.png");
    writeSystem->carregar(WriteSystemFontDefault::comic,getPath()+"data//kernel//fonte//comicsans.png");
    writeSystem->carregar(WriteSystemFontDefault::high,getPath()+"data//kernel//fonte//highlight.png");
    writeSystem->carregar(WriteSystemFontDefault::stac,getPath()+"data//kernel//fonte//staccato.png");

    //Detecta o idioma padr�o do ambiente (Sistema Operacional)
    writeSystem->uiTexto->detectarIdioma();

    //FPSTimer primeira chamada
    fpsSystem->start();

    UtilLog::cabecalho("Iniciando Ambiente para Escopo do Jogo");
}
//Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick),
//desenha na tela o conte�do do backbuffer
//Obs.: Deve ser usado na intera��o do loop principal do jogo
void GBF::atualizar() 
{
    try {
        fpsSystem->processar();
        /*
        if (isFPS()){
            writeSystem->getFonte("console")->setAlpha(180);
            writeSystem->escrever("console",5,0,"FPS: %i",fpsSystem->getFPS());
            writeSystem->getFonte("console")->setAlpha(255);
        }
        */
        controleInterno();
        inputSystem->processar();
        graphicSystem->flip();
    } catch(...){
        UtilLog::tracer("SDL: %s", SDL_GetError());
        UtilLog::tracer("SDL_Image: %s", IMG_GetError());
        UtilLog::tracer("SDL_Mixer: %s", Mix_GetError());
    }
}
//Pausa o Sistema
void GBF::pausar() 
{
}
//Mostra o Contador de FPS
void GBF::setFPS(bool show) 
{
    fps=show;
}
//Informa se o mostrador de FPS est� ativo
bool GBF::isFPS() 
{
    return fps;
}
//Informa o caminho do diret�rio base da aplica��o corrente
void GBF::setPath(char * fullPath) 
{
    pathBase=UtilExtract::extractPath(fullPath);

    if (isDefaultPath()){
        UtilLog::setArquivo(fullPath);
        GraphicSystemImageBufferManager::setPathBase(pathBase);
        SoundSystemInterfaceManager::setPathBase(pathBase);
        UserInterfaceTexto::setPathBase(pathBase);
    }
}
//Retorna o diret�rio base da aplica��o corrente
std::string GBF::getPath() 
{
    return pathBase;
}
bool GBF::isDefaultPath() 
{
    return defaultPath;
}
void GBF::setDefaultPath(bool ativo) 
{
    defaultPath=ativo;
}
//Controle para a��es internas
void GBF::controleInterno() 
{
    //F10 = Alterna entre modo de controle exclusivo
    if (inputSystem->teclado->isKey(SDLK_F10)){
        inputSystem->alternarControleExclusivo();
    //F11 = Alterna entre modo tela Cheia e Janela
    } else if (inputSystem->teclado->isKey(SDLK_F11)){
        if (SDL_WM_ToggleFullScreen(graphicSystem->gsMode->getScreen())==0){
            //UtilLog::getInstance()->inicializando("GBF :: Aviso");
            //UtilLog::getInstance()->comentario("Sem Suporte a troca entre FullScreen e WindowScreen");
        }
    //F12 = Salva um screen do jogo
    } else if (inputSystem->teclado->isKey(SDLK_F12)){
        char tela[255];
        numscreenshot++;
        sprintf(tela,"%s//data//screen//screen%03d.bmp",getPath().c_str(),numscreenshot);
        graphicSystem->salvarScreenShot(tela);
    //F5 = Tira o Som
    } else if (inputSystem->teclado->isKey(SDLK_F5)){
        //audio.Mute();
    }

}
//Prepara o Ambiente para ser inicializado 
void GBF::carregar() 
{
    //Inicializando Log
    UtilLog::iniciar();

    //Inicializando Gerador Rand�mico
    UtilLog::sistema("Inicializando Gerador Rand�mico");
    srand(time(NULL));

    //Inicializando FPS do jogo
    fpsSystem = new TimerSystemFPS();

    //Inicializando Video
    graphicSystem = GraphicSystem::getInstance();
    GraphicSystemImageBufferManager::getInstance();
    FrameLayerManager::getInstance();

    //Inicializando Gerenciador de Fontes
    writeSystem = WriteSystemManager::getInstance();

    //Inicializando Input
    inputSystem = InputSystem::getInstance();

    //Inicializando Audio
    soundSystem = SoundSystem::getInstance();

    UtilLog::cabecalho("Carregamento Completo do Framework");
}
//Define o T�tulo para Janela 
void GBF::setTitulo(std::string titulo) 
{
    SDL_WM_SetCaption(titulo.c_str(),NULL);
}
