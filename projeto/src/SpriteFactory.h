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

#include <string>

#include "SpriteItem.h"
#include "SpriteCharacter.h"
#include "FrameLayer.h"
#include "ImageBuffer.h"
#include "GraphicSystem.h"

namespace GBF {

namespace Imagem {

class SpriteFactory
{
  public:
    //Construtor
    SpriteFactory(std::string nomeImageBuffer);

    //Destrutor
    virtual ~SpriteFactory();

    GBF::Imagem::Sprite::SpriteItem * criarSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

    GBF::Imagem::Sprite::SpriteCharacter * criarSpritePersonagem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

    GBF::Imagem::Layer::FrameLayer * criarFrameLayer(int left, int top, int largura, int altura);


  protected:
    GBF::Kernel::Graphic::ImageBuffer * imageBuffer;

};

} // namespace GBF::Imagem

} // namespace GBF
#endif
