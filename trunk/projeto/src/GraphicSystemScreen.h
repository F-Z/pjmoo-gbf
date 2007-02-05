#ifndef _GRAPHICSYSTEMSCREEN_H
#define _GRAPHICSYSTEMSCREEN_H

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

//*
// * \class GraphicSystemScreen
// * \brief Representação do Buffer de Vídeo
// * \date 15/04/2005
// * \warning Classe Singleton

class GraphicSystemScreen
{
  public:
    //Destrutor
    virtual ~GraphicSystemScreen();

    //Desenha uma surface na surface de vídeo
    void blitSurface(SDL_Surface * origem, SDL_Rect * area, SDL_Rect * posicao);

    //Retorna ponteiro para a surface de vídeo 
    SDL_Surface * getScreen();

    //Trava a surface para desenhar
    bool travar();

    //Destrava a surface para desenhar
    void destravar();


  private:
    //Construtor 
    GraphicSystemScreen();

    SDL_Surface * pScreen;

    //Informa qual a surface a ser usada e a configuração
    void setScreen(SDL_Surface * surface);

  friend class GraphicSystem;
};
#endif
