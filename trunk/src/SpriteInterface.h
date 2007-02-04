#ifndef _SPRITEINTERFACE_H
#define _SPRITEINTERFACE_H

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

#include "GraphicSystemImageBuffer.h"
#include "GBF_define.h"

class SpriteInterface {
  public:
    //Destrutor
    virtual ~SpriteInterface();

    void criar(int left, int top, int largura, int altura, GraphicSystemImageBuffer * gsiBuffer);


  protected:
    //Construtor
    SpriteInterface();

    GraphicSystemImageBuffer * imagem;

    int frameAtual;

    int frameRateAtual;

    int frameTotal;

    int frameRate;

    bool automatico;

    SDL_Rect posicao;

    SDL_Rect tamanho;

    SDL_Rect quadro;

};
#endif
