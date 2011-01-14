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
#include "ImageBuffer.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

/** Construtor */
ImageBuffer::ImageBuffer()
{
}

/** Destrutor */
ImageBuffer::~ImageBuffer()
{
    //UtilLog::getInstance()->status("[GraphicSystemImageBuffer Removido(a)]");
}

bool ImageBuffer::loadFromFile(std::string fileName)
{
    image = IMG_Load(fileName.c_str());

    if (image){
        convertSurface();
        setColorKey(255, 0, 255);
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;

        return false;
    }
}

/** Desenha um sprite simples na tela */
void ImageBuffer::draw(GBF::Point point)
{
    GBF::Area rect, pos;

    rect  = this->tamanho;
    pos.left   = point.x;
    pos.top    = point.y;
    pos.right  = 0;
    pos.bottom = 0;

   screen->blitSurface(image, rect, point);
}

/** Permite desenhar sprites animados */
void ImageBuffer::draw(GBF::Point POSICAO, GBF::Area TAMANHO, int FRAME)
{
    GBF::Area rect;

    rect.left   = (TAMANHO.left) + (FRAME * TAMANHO.right);
    rect.top    = TAMANHO.top;
    rect.bottom = TAMANHO.bottom;
    rect.right  = TAMANHO.right;

    screen->blitSurface(image, rect, POSICAO);
}

/** Permite desenhar sprites animados com corte */
void ImageBuffer::draw(GBF::Point POSICAO, GBF::Area TAMANHO, int FRAME, GBF::Area CORTE)
{
    GBF::Area rect;

    rect.left   = (TAMANHO.left) + (FRAME * TAMANHO.right);
    rect.top    = TAMANHO.top;
    rect.bottom = TAMANHO.bottom;
    rect.right  = TAMANHO.right;

    if (CORTE.left > 0){
        rect.left += CORTE.left;
    }

    if (CORTE.top > 0){
        rect.top = CORTE.top;
    }

    if (CORTE.right > 0){
        rect.right = CORTE.right;
    }

    if (CORTE.bottom > 0){
        rect.bottom = CORTE.bottom;
    }

    screen->blitSurface(image, rect, POSICAO);
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
