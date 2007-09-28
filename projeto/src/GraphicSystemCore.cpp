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

#include "GraphicSystemCore.h"
#include "GraphicSystemUtility.h"

//Limpa a tela 
void GraphicSystemCore::clear() 
{
    SDL_FillRect(gsMode.getScreen(), NULL, 0);
}
//Salva uma imagem da tela 
void GraphicSystemCore::salvarScreenShot(std::string arquivo) 
{
    SDL_SaveBMP(gsMode.getScreen(),arquivo.c_str());
}
//Destrutor 
GraphicSystemCore::~GraphicSystemCore() 
{
    UtilLog::sistema("Removendo GraphicSystem");

    delete(graphicSystem);
    delete(gsScreen);


    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
void GraphicSystemCore::iniciar() 
{
    gsScreen->setScreen(gsMode.getScreen());

    GraphicSystemImage::setGraphicSystemScreen(gsScreen);
    GraphicSystemGFX::setGraphicSystemScreen(gsScreen);

    graphicSystem = GraphicSystem::getInstance();
    graphicSystem->gfx->inicializar();
    GraphicSystemUtility::setGraphicSystem(graphicSystem);
}
//Realiza o flip(troca) entre os buffers de vídeo 
void GraphicSystemCore::flip() 
{
    SDL_Flip(gsMode.getScreen());
}
//Inicializa SubSistema de suporte a Video 
GraphicSystemCore::GraphicSystemCore() 
{
    const SDL_version *v = SDL_Linked_Version();
    UtilLog::sistema("Instanciando SDL - versão %i.%i.%i",v->major,v->minor,v->patch);
    UtilLog::sistema("Instanciando GraphicSystem");

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        UtilLog::comentario("[Falhou] :: %s",SDL_GetError());
        exit(-1);
    } else {
        putenv("SDL_VIDEO_CENTERED=true");
        char videodriver[10];
        SDL_VideoDriverName(videodriver,10);
        UtilLog::comentario("Driver de Vídeo=%s : Centralizado=%s",videodriver,getenv("SDL_VIDEO_CENTERED"));

        gsScreen = new GraphicSystemScreen();
//        gsGFX    = GraphicSystemGFX::getInstance();
//        gsMode   = new GraphicSystemMode();
//        gsImageBufferManager = GraphicSystemImageBufferManager::getInstance();
    }
}
