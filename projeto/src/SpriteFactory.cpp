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

#include "SpriteFactory.h"

namespace GBF {

namespace Grafico {

//Destrutor
SpriteFactory::~SpriteFactory() 
{
}
GBF::Grafico::Sprite::SpriteItem * SpriteFactory::criarSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate) 
{
    Sprite::SpriteItem *sprite = new Sprite::SpriteItem();
    sprite->criar(left,top,largura,altura,frameTotal,frameRate,gsiBuffer);

    return sprite;
}
GBF::Grafico::Sprite::SpritePersonagem * SpriteFactory::criarSpritePersonagem(int left, int top, int largura, int altura, int frameTotal, int frameRate) 
{
    Sprite::SpritePersonagem *sprite = new Sprite::SpritePersonagem();
    sprite->criar(left,top,largura,altura,frameTotal,frameRate,gsiBuffer);

    return sprite;
}
GBF::Grafico::Layer::FrameLayer * SpriteFactory::criarFrameLayer(int left, int top, int largura, int altura) 
{
    Layer::FrameLayer *sprite = new Layer::FrameLayer();
    sprite->criar(left,top,largura,altura,gsiBuffer);

    return sprite;
}
//Construtor
SpriteFactory::SpriteFactory(GBF::Kernel::Graphic::ImageBuffer * gsiBuffer) 
{
    SpriteFactory::gsiBuffer=gsiBuffer;
}

} // namespace GBF::Grafico

} // namespace GBF
