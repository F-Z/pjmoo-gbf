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

#include "Sprite.h"

namespace GBF
{

namespace Image {

namespace Sprite {

/** Destrutor */
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
/** Desenha o sprite na tela, com base na última posição informada ou desenhada */
void Sprite::draw(int x, int y)
{
    point.x = x;
    point.y = y;
    GBF::Area pontoCorte = tamanho;
    pontoCorte.left += animation.getFrameSize().left;

    image->draw(point, pontoCorte, animation.process());
}
/** Desenha o sprite na tela, com base na última posição informada ou desenhada */
void Sprite::draw()
{
    draw(point.x, point.y);
}

/** Retorna a dimensão do sprite 'width' e 'height' */
GBF::Dimension Sprite::getTamanho()
{
    Dimension dimensao;
    dimensao.w = tamanho.right;
    dimensao.h = tamanho.bottom;

    return  dimensao;
}

/** Colisão baseada no tamanho dos Sprites */
bool Sprite::isCollision(Sprite * sprite)
{
    if ((point.x + tamanho.right >= sprite->point.x) &&
            (point.x <= sprite->point.x + sprite->tamanho.right) &&
            (point.y + tamanho.bottom >= sprite->point.y) &&
            (point.y <= sprite->point.y + sprite->tamanho.bottom)) {
        return true;
    }
    else {
        return false;
    }
}

/** Posiciona o Sprite na tela */
void Sprite::setPoint(GBF::Point point)
{
    setPoint(point.x, point.y);
}

/** Posiciona o Sprite na tela */
void Sprite::setPoint(int x, int y)
{
    point.x = x;
    point.y = y;
}

/** Construtor */
Sprite::Sprite()
{
    tamanho.left = tamanho.top = tamanho.bottom = tamanho.right = 0;
    point.x = point.y = 0;

    animation.setAutomatic(true);
}

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF
