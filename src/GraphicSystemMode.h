#ifndef _GRAPHICSYSTEMMODE_H
#define _GRAPHICSYSTEMMODE_H

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

#include "UtilLog.h"
#include "GBF_define.h"

//Informa��es da Configura��o de V�deo 
struct VideoConfig {
    int w;

    int h;

    int color;

    bool full;

};
class GraphicSystemMode {
  public:
    //Construtor 
    GraphicSystemMode();

    //Destrutor 
    ~GraphicSystemMode();

    //Coloca o v�deo em modo de tela cheia 
    void setModeFullScreen();

    //Coloca o v�deo em modo de janela 
    void setModeWindowScreen();

    //Retorna se o jogo esta rodando em modo de Tela Cheia 
    bool isFullScreen();

    //Configura a resolu��o do modo gr�fico 
    void setConfig(VideoConfig config);

    //Pega a Configura��o do modo gr�fico 
    VideoConfig getConfig();

    //Retorna a Surface Primaria de V�deo (framebuffer) 
    SDL_Surface * getScreen();


  protected:
    VideoConfig config;


  private:
    SDL_Surface * screen;

};
#endif
