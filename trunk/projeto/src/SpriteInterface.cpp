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
#include "SpriteInterface.h"

namespace GBF
{

namespace Image {

//Destrutor
SpriteInterface::~SpriteInterface()
{

}

void SpriteInterface::create(int left, int top, int largura, int altura, GBF::Kernel::Graphic::ImageBuffer * gsiBuffer)
{
    tamanho.right  = largura;
    tamanho.bottom = altura;
    tamanho.left   = left;
    tamanho.top    = top;

    image = gsiBuffer;

    animation.setFrameSize(tamanho);
}

//Construtor
SpriteInterface::SpriteInterface()
{
}

} // namespace GBF::Image

} // namespace GBF
