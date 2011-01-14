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
#include "SpriteItem.h"

namespace GBF
{

namespace Image {

namespace Sprite {

//Construtor
SpriteItem::SpriteItem()
{
    animation.setAutomatic(false);
}

//Destrutor
SpriteItem::~SpriteItem()
{

}

void SpriteItem::draw(int x, int y)
{
    animation.cutSet(0, tamanho.right);

    Sprite::draw(x, y);
}

//Informa o quadro de animação
void SpriteItem::setFrame(int quadro)
{
    animation.setFrame(quadro);
}

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF
