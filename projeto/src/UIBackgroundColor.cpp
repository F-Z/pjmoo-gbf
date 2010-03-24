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
#include "UIBackgroundColor.h"

namespace UserInterface {

namespace Look {

/** Construtor */
UIBackgroundColor::UIBackgroundColor()
{
}
/** Destrutor */
UIBackgroundColor::~UIBackgroundColor()
{
}
void UIBackgroundColor::setColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    color.r=r;
    color.g=g;
    color.b=b;
}
/** Desenha o EstiloVisual do Componente */
void UIBackgroundColor::draw()
{
    graphicSystem->gfx->setColor(color.r,color.g,color.b);
    graphicSystem->gfx->retanguloPreenchido(point.x,point.y,dimension.w,dimension.h);

    graphicSystem->gfx->setColor(borderColor.r,borderColor.g,borderColor.b);
    graphicSystem->gfx->retangulo(point.x,point.y,dimension.w,dimension.h);
}
/** Retorna uma cópia do objeto */
UIBackground * UIBackgroundColor::clone()
{
    UIBackgroundColor * clone = new UIBackgroundColor();
    clone->setBorderColor(borderColor.r,borderColor.g,borderColor.b);
    clone->setColor(color.r,color.g,color.b);

    return clone;
}

} // namespace UserInterface::Look

} // namespace UserInterface
