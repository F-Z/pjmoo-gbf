/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "GraphicCore.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

/** Limpa a tela */
void GraphicCore::clear()
{
    SDL_FillRect(mode.getScreen(), NULL, 0);
}

/** Salva uma imagem da tela */
void GraphicCore::saveScreenshot(std::string fileName)
{
    SDL_SaveBMP(mode.getScreen(), fileName.c_str());
}

/** Destrutor */
GraphicCore::~GraphicCore()
{
//    UtilLog::sistema("Removendo GraphicSystem");

    delete(graphicSystem);
    delete(screen);


    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void GraphicCore::start()
{
    std::cout << "GBF::Kernel::Graphic::GraphicCore::start()" << std::endl;
    screen->setScreen(mode.getScreen());

    ImageBase::setGraphicSystemScreen(screen);
    GFX::setGraphicSystemScreen(screen);

    graphicSystem = GraphicSystem::getInstance();
    graphicSystem->gfx->start();
    GraphicSystemUtility::setGraphicSystem(graphicSystem);
}

/** Realiza o flip(troca) entre os buffers de vídeo */
void GraphicCore::flip()
{
    SDL_Flip(mode.getScreen());
}

/** Inicializa SubSistema de suporte a Video */
GraphicCore::GraphicCore()
{
    std::cout << "GBF::Kernel::Graphic::GraphicCore" << std::endl;

    const SDL_version *v = SDL_Linked_Version();
    std::cout << "\tSDL version: " << (int) v->major << "." << (int) v->minor << "." << (int) v->patch << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
        exit(-1);
    } else {
        char videodriver[10];
        SDL_VideoDriverName(videodriver, 10);
        std::cout << "\tSDL video driver: " << videodriver << std::endl;

        const char * videoCentred = "SDL_VIDEO_CENTERED=true\0";
        SDL_putenv((char*)videoCentred);
        std::cout << "\tSDL options: " << videoCentred << std::endl;

        screen = new Screen();
    }
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
