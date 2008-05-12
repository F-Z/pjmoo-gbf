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
#include "ImageBuffer.h"

namespace GBF {

namespace Grafico {

class SpriteFactory
{
  public:
    //Destrutor
    virtual ~SpriteFactory();

    GBF::Grafico::Sprite::SpriteItem * criarSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

    GBF::Grafico::Sprite::SpritePersonagem * criarSpritePersonagem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

    GBF::Grafico::Layer::FrameLayer * criarFrameLayer(int left, int top, int largura, int altura);

    //Construtor
    SpriteFactory(GBF::Kernel::Graphic::ImageBuffer * gsiBuffer);


  protected:
    GBF::Kernel::Graphic::ImageBuffer * gsiBuffer;

};

} // namespace GBF::Grafico

} // namespace GBF
#endif
