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

#include "GraphicMode.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Construtor 
GraphicMode::GraphicMode() 
{
    screen = NULL;
}
//Destrutor 
GraphicMode::~GraphicMode() 
{
//    SDL_FreeSurface(screen);
}
//Coloca o vídeo em modo de tela cheia 
void GraphicMode::setModeFullScreen() 
{
    config.color = SDL_VideoModeOK(config.w,config.h,config.color, SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    screen       = SDL_SetVideoMode(config.w,config.h,config.color,SDL_SWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);

    if (screen==NULL){
       // UtilLog::tracer("GraphicSystem::setModeFullScreen=%s",SDL_GetError());
        exit(-1);
    } else {
        config.full=true;
        //UtilLog::tracer("GraphicSystem::setModeFullScreen Resolução:%ix%i %i Bits",config.w,config.h,config.color);
    }
}
//Coloca o vídeo em modo de janela 
void GraphicMode::setModeWindowScreen() 
{
    config.color = SDL_VideoModeOK(config.w,config.h,config.color, SDL_SWSURFACE|SDL_DOUBLEBUF);
    screen       = SDL_SetVideoMode(config.w,config.h,config.color,SDL_SWSURFACE|SDL_DOUBLEBUF);

    if (screen==NULL){
       // UtilLog::tracer("GraphicSystem::setModeWindowScreen=%s",SDL_GetError());
        exit(-1);
    } else {
        config.full=false;
        //UtilLog::tracer("GraphicSystem::setModeWindowScreen Resolução:%ix%i %i Bits",config.w,config.h,config.color);
    }
}
//Retorna se o jogo esta rodando em modo de Tela Cheia 
bool GraphicMode::isFullScreen() 
{
    return config.full;
}
//Configura a resolução do modo gráfico 
void GraphicMode::setConfig(VideoConfig config) 
{
    this->config=config;
}
//Pega a Configuração do modo gráfico 
VideoConfig GraphicMode::getConfig() 
{
    return config;
}
//Retorna a Surface Primaria de Vídeo (framebuffer) 
SDL_Surface * GraphicMode::getScreen() 
{
    return screen;
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
