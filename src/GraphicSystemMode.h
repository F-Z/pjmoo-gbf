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

//Informações da Configuração de Vídeo 
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

    //Coloca o vídeo em modo de tela cheia 
    void setModeFullScreen();

    //Coloca o vídeo em modo de janela 
    void setModeWindowScreen();

    //Retorna se o jogo esta rodando em modo de Tela Cheia 
    bool isFullScreen();

    //Configura a resolução do modo gráfico 
    void setConfig(VideoConfig config);

    //Pega a Configuração do modo gráfico 
    VideoConfig getConfig();

    //Retorna a Surface Primaria de Vídeo (framebuffer) 
    SDL_Surface * getScreen();


  protected:
    VideoConfig config;


  private:
    SDL_Surface * screen;

};
#endif
