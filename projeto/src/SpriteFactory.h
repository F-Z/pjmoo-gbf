#ifndef _SPRITEFACTORY_H
#define _SPRITEFACTORY_H

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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "SpriteItem.h"
#include "SpritePersonagem.h"
#include "FrameLayer.h"
#include "GraphicSystemImageBuffer.h"

class SpriteFactory
{
  public:
    //Destrutor
    virtual ~SpriteFactory();

    SpriteItem * criarSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

    SpritePersonagem * criarSpritePersonagem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

    FrameLayer * criarFrameLayer(int left, int top, int largura, int altura);

    //Construtor
    SpriteFactory(GraphicSystemImageBuffer * gsiBuffer);


  protected:
    GraphicSystemImageBuffer * gsiBuffer;

};
#endif
