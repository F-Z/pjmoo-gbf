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
#include "Sprite.h"

namespace GBF {

namespace Image {

namespace Sprite {


Sprite::Sprite()
{
    tamanho.left = tamanho.top = tamanho.bottom = tamanho.right = 0;
    point.x = point.y = 0;

    animation.setAutomatic(true);
}

Sprite::~Sprite()
{
}

void Sprite::create(int left, int top, int largura, int altura, int quantitadeQuadro, int repeticaoQuadro, GBF::Kernel::Graphic::ImageBuffer * gsiBuffer)
{
    //chama o metodo criar da classe superclasse - SpriteInterface
    SpriteInterface::create(left, top, largura, altura, gsiBuffer);
    //configura as informações de animação
    animation.configuration(quantitadeQuadro, repeticaoQuadro);
}

void Sprite::draw(int x, int y)
{
    point.x = x;
    point.y = y;
    GBF::Area pontoCorte = tamanho;
    pontoCorte.left += animation.getFrameSize().left;

    image->draw(point, pontoCorte, animation.process());
}

void Sprite::draw()
{
    draw(point.x, point.y);
}


GBF::Dimension Sprite::getTamanho()
{
    Dimension dimensao;
    dimensao.w = tamanho.right;
    dimensao.h = tamanho.bottom;

    return  dimensao;
}


bool Sprite::isCollision(Sprite * sprite)
{
    if ((point.x + tamanho.right >= sprite->point.x) &&
            (point.x <= sprite->point.x + sprite->tamanho.right) &&
            (point.y + tamanho.bottom >= sprite->point.y) &&
            (point.y <= sprite->point.y + sprite->tamanho.bottom)) {
        return true;
    } else {
        return false;
    }
}

void Sprite::setPoint(GBF::Point point)
{
    setPoint(point.x, point.y);
}

void Sprite::setPoint(int x, int y)
{
    point.x = x;
    point.y = y;
}

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF
