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

#include "GraphicCore.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Limpa a tela 
void GraphicCore::clear() 
{
    SDL_FillRect(gsMode.getScreen(), NULL, 0);
}
//Salva uma imagem da tela 
void GraphicCore::salvarScreenShot(std::string arquivo) 
{
    SDL_SaveBMP(gsMode.getScreen(),arquivo.c_str());
}
//Destrutor 
GraphicCore::~GraphicCore() 
{
//    UtilLog::sistema("Removendo GraphicSystem");

    delete(graphicSystem);
    delete(gsScreen);


    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
void GraphicCore::iniciar() 
{
    std::cout << "GBF::Kernel::Graphic::GraphicCore::iniciar()" << std::endl;
    gsScreen->setScreen(gsMode.getScreen());

    ImageBase::setGraphicSystemScreen(gsScreen);
    GFX::setGraphicSystemScreen(gsScreen);

    graphicSystem = GraphicSystem::getInstance();
    graphicSystem->gfx->inicializar();
    GraphicSystemUtility::setGraphicSystem(graphicSystem);
}
//Realiza o flip(troca) entre os buffers de vídeo 
void GraphicCore::flip() 
{
    SDL_Flip(gsMode.getScreen());
}
//Inicializa SubSistema de suporte a Video 
GraphicCore::GraphicCore() 
{
    const SDL_version *v = SDL_Linked_Version();

    std::cout << "GBF::Kernel::Graphic::GraphicCore" << std::endl;

    std::cout << "\tSDL: " << (int) v->major << "." << (int) v->minor << "." << (int) v->patch << " version" << std::endl;


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
        exit(-1);
    } else {
        SDL_putenv("SDL_VIDEO_CENTERED=true");
        char videodriver[10];
        SDL_VideoDriverName(videodriver,10);

        std::cout << "\tSDL: driver " << videodriver << std::endl;

        gsScreen = new Screen();
    }
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
