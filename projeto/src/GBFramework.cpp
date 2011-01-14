/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#include "GBFramework.h"

namespace GBF
{

/** Destrutor */
GBFramework::~GBFramework()
{
    std::cout << "[END].[Game Space]" << std::endl;

    delete(fpsSystem);
    delete(writeSystem);
//    delete(GraphicSystemImageBufferManager::getInstance());
    delete(Image::Layer::LayerManager::getInstance());
    delete(graphicSystemCore);
    delete(soundSystemCore);
    delete(inputSystemCore);

    SDL_Quit();
}

/** Construtor */
GBFramework::GBFramework()
{
    screenShotCounter = 0;
    fps           = false;
}

/** Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick), desenha na tela o conteúdo do backbuffer */
void GBFramework::update()
{
    try {
        fpsSystem->update();

        if (isFPS()) {
            //writeSystem->getFonte(Kernel::Write::WriteManager::defaultFont)->setAlpha(180);
            writeSystem->write(Kernel::Write::WriteManager::defaultFont, 0, 0, "FPS: %d", fpsSystem->getValue());
            //writeSystem->escrever(Kernel::Write::WriteManager::defaultFont,0,0,"FPS: %d",fpsSystem->getFPS());
            //writeSystem->getFonte(Kernel::Write::WriteManager::defaultFont)->setAlpha(255);
        }

        internalControl();

        inputSystemCore->update();
        graphicSystemCore->flip();
    } catch (...) {
        std::cerr << " SDL Error catch  " << SDL_GetError() << std::endl;
    }
}

/** Retorna o diretório base da aplicação corrente */
std::string GBFramework::getPath()
{
    return Kernel::Util::Path::getPath();
}

/** Inicializa o Sistema, e configura o modo gráfico */
void GBFramework::start(int width, int height, int bpp_color, bool full, GBF::Kernel::FPS::FPSType fpsType)
{
    std::cout << "GBF::Kernel::GBFramework::start()" << std::endl;

    Kernel::Graphic::VideoConfig config;
    config.w     = width;
    config.h     = height;
    config.color = bpp_color;
    config.full  = full;
    graphicSystemCore->mode.setConfig(config);

    if (config.full) {
        graphicSystemCore->mode.setModeFullScreen();
    } else {
        graphicSystemCore->mode.setModeWindowScreen();
    }

    graphicSystemCore->start();

    inputSystemCore->start();

    soundSystemCore->start(22050, AUDIO_S16SYS, Kernel::Sound::CANAL_STEREO, 2048, 16);

    //input.mouse.Carregar(&pacote,"cursor.bmp");

    //Detecta o idioma padrão do ambiente (Sistema Operacional)
    writeSystem->language->autodetect();

    //FPS
    fpsSystem = Kernel::FPS::FPSFactory::create(fpsType);
    //FPS primeira chamada
    fpsSystem->start();


    //Carregando Fontes Padrões
    std::cout << "[*]Load Default" << std::endl;
    writeSystem->loadFromFile(Kernel::Write::WriteManager::defaultFont, "data//kernel//fonte//default.png");

    graphicSystemCore->graphicSystem->imageBufferManager->loadFromFile("gbf-window-background", "data//kernel//imagem//window-background.png");

    std::cout << "[BGN].[Game Space]" << std::endl;
}

/** Informa se o mostrador de FPS está ativo */
bool GBFramework::isFPS()
{
    return fps;
}

/** Pausa o Sistema */
void GBFramework::pause()
{
}

/** Mostra o Contador de FPS */
void GBFramework::setFPS(bool show)
{
    fps = show;
}

/** Informa o caminho do diretório base da aplicação corrente */
void GBFramework::setPath(char * fullPath)
{
    std::string pathBase = Kernel::Util::StringExtract::extractPath(fullPath);

    // if (isDefaultPath()){
    Kernel::Util::Path::setPath(pathBase);
    //UtilLog::setArquivo(fullPath);
    //Kernel::Graphic::ImageBufferManager::setPathBase(pathBase);
    //Kernel::Sound::SoundManagerAbstract::setPathBase(pathBase);
    //Kernel::Write::Idioma::setPathBase(pathBase);
    //}
}

/** Informação sobre o Autor e o Título da Aplicação.
Obs.: Usado para arquivo de log e título da janela */
void GBFramework::setTitle(std::string title, std::string autor)
{
    std::cout << "[GAME - INFO]=================================" << std::endl;
    std::cout << " Title: "   << title  << std::endl;
    std::cout << " By: "      << autor  << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "GBFramework < pjmoo-gbf.googlecode.com >" << std::endl;
    std::cout << " version : " << AutoVersion::FULLVERSION_STRING << "(" << AutoVersion::STATUS_SHORT << ")" << std::endl;
    std::cout << " svn revision: " << AutoVersion::SVN_REVISION << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    load();
    setTitle(title);
}

/** Prepara o Ambiente para ser inicializado */
void GBFramework::load()
{
    //Inicializando Gerador Randômico
    std::cout << "GBF::GBFramework::load()" << std::endl;
    std::cout << "\tCPP: srand" << std::endl;
    srand(time(NULL));


    //Inicializando Video
    std::cout << "GBF::Kernel::Graphic" << std::endl;
    graphicSystemCore = new Kernel::Graphic::GraphicCore();
    Image::Layer::LayerManager::getInstance();

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

/** Controle para ações internas */
void GBFramework::internalControl()
{
    if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F1)) {
        hookF1();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F2)) {
        hookF2();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F3)) {
        hookF3();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F4)) {
        hookF4();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F5)) {
        hookF5();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F6)) {
        hookF6();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F7)) {
        hookF7();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F8)) {
        hookF8();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F9)) {
        hookF9();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F10)) {
        hookF10();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F11)) {
        hookF11();
    } else if (inputSystemCore->inputSystem->keyboard->isKey(SDLK_F12)) {
        hookF12();
    }
}

/** Define o Título para Janela */
void GBFramework::setTitle(std::string title)
{
    SDL_WM_SetCaption(title.c_str(), NULL);
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF1()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF2()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF3()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF4()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF5()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF6()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF7()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF8()
{
    //not implemented. Free for your implementation.
}
/** Not implemented. Free for your implementation. */
void GBFramework::hookF9()
{
    //not implemented. Free for your implementation.
}
/** F10 = Alterna entre modo de controle de teclado e mouse exclusivo*/
void GBFramework::hookF10()
{
    inputSystemCore->alternarControleExclusivo();
}
/**F11 = Alterna entre modo tela Cheia e Janela */
void GBFramework::hookF11()
{
    if (SDL_WM_ToggleFullScreen(graphicSystemCore->mode.getScreen()) == 0) {
        std::cout << "SDL: SDL_WM_ToggleFullScreen not supported" << std::endl;
    }
}
/**F12 = Salva um screen do jogo */
void GBFramework::hookF12()
{
    char tela[255];
    screenShotCounter++;
    sprintf(tela, "%s//data//screen//screen%03d.bmp", getPath().c_str(), screenShotCounter);
    graphicSystemCore->saveScreenshot(tela);
}

} // namespace GBF
