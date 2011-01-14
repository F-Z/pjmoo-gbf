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
#ifndef _SPRITEFACTORY_H
#define _SPRITEFACTORY_H

#include <string>

#include "SpriteItem.h"
#include "SpriteCharacter.h"
#include "FrameLayer.h"
#include "ImageBuffer.h"
#include "GraphicSystem.h"

namespace GBF {

namespace Image {

class SpriteFactory {

    public:
        //Construtor
        SpriteFactory(std::string nomeImageBuffer);

        //Destrutor
        virtual ~SpriteFactory();

        GBF::Image::Sprite::SpriteItem * createSpriteItem(int left, int top, int largura, int altura, int frameTotal, int frameRate);

        GBF::Image::Sprite::SpriteCharacter * createSpriteCharacter(int left, int top, int largura, int altura, int frameTotal, int frameRate);

        GBF::Image::Layer::FrameLayer * createFrameLayer(int left, int top, int largura, int altura);


    protected:
        GBF::Kernel::Graphic::ImageBuffer * imageBuffer;

};

} // namespace GBF::Image

} // namespace GBF

#endif
