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

//Destrutor
SpriteFactory::~SpriteFactory() 
{
}
SpriteItem * SpriteFactory::criarSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate) 
{
    SpriteItem *sprite = new SpriteItem();
    sprite->criar(left,top,largura,altura,frameTotal,frameRate,gsiBuffer);
    sprite->setQuadro(0);

    return sprite;
}
SpritePersonagem * SpriteFactory::criarSpritePersonagem(int left, int top, int largura, int altura, int frameTotal, int frameRate) 
{
    SpritePersonagem *sprite = new SpritePersonagem();
    sprite->criar(left,top,largura,altura,frameTotal,frameRate,gsiBuffer);

    return sprite;
}
FrameLayer * SpriteFactory::criarFrameLayer(int left, int top, int largura, int altura) 
{
    FrameLayer *sprite =new FrameLayer();
    sprite->criar(left,top,largura,altura,gsiBuffer);

    return sprite;
}
//Construtor
SpriteFactory::SpriteFactory(GraphicSystemImageBuffer * gsiBuffer) 
{
    SpriteFactory::gsiBuffer=gsiBuffer;
}
