/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _SPRITEINTERFACE_H
#define _SPRITEINTERFACE_H

#include "ImageBuffer.h"

#include "Animation.h"
#include "Object.h"

namespace GBF
{

namespace Image {

class SpriteInterface : public GBF::Object
{
    public:
        //Destrutor
        virtual ~SpriteInterface();

        void create(int left, int top, int largura, int altura, GBF::Kernel::Graphic::ImageBuffer * gsiBuffer);


    protected:
        //Construtor
        SpriteInterface();

        GBF::Kernel::Graphic::ImageBuffer * image;

        /** Posição do Sprite na Tela */
        GBF::Point point;
        /** Tamanho do Sprite */
        GBF::Area tamanho;


    public:
        GBF::Image::Sprite::Animation animation;

};

} // namespace GBF::Image

} // namespace GBF
#endif
