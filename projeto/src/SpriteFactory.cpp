/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#include "SpriteFactory.h"

namespace GBF {

namespace Image {

//Construtor
SpriteFactory::SpriteFactory(std::string nomeImageBuffer) {
    GBF::Kernel::Graphic::GraphicSystem  *graphicSystem = GBF::Kernel::Graphic::GraphicSystem::getInstance();

    imageBuffer = graphicSystem->imageBufferManager->getImageBuffer(nomeImageBuffer);
}

//Destrutor
SpriteFactory::~SpriteFactory() {
}

GBF::Image::Sprite::SpriteItem * SpriteFactory::createSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate) {
    Sprite::SpriteItem *sprite = new Sprite::SpriteItem();
    sprite->create(left, top, largura, altura, frameTotal, frameRate, imageBuffer);

    return sprite;
}

GBF::Image::Sprite::SpriteCharacter * SpriteFactory::createSpriteCharacter(int left, int top, int largura, int altura, int frameTotal, int frameRate) {
    Sprite::SpriteCharacter *sprite = new Sprite::SpriteCharacter();
    sprite->create(left, top, largura, altura, frameTotal, frameRate, imageBuffer);

    return sprite;
}

GBF::Image::Layer::FrameLayer * SpriteFactory::createFrameLayer(int left, int top, int largura, int altura) {
    Layer::FrameLayer *sprite = new Layer::FrameLayer();
    sprite->create(left, top, largura, altura, imageBuffer);

    return sprite;
}

} // namespace GBF::Image

} // namespace GBF
