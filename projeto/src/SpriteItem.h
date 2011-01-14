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
#ifndef _SPRITEITEM_H
#define _SPRITEITEM_H

#include "Sprite.h"

namespace GBF
{

namespace Image {

namespace Sprite {

class SpriteItem : public Sprite
{
    public:
        //Construtor
        SpriteItem();

        //Destrutor
        virtual ~SpriteItem();

        virtual void draw(int x, int y);

        //Informa o quadro de animação
        void setFrame(int quadro);

};

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF
#endif
