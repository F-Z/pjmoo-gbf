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

//Construtor
UIBackgroundColor::UIBackgroundColor()
{
}
//Destrutor
UIBackgroundColor::~UIBackgroundColor()
{
}
void UIBackgroundColor::setCorFundo(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corFundo.r=r;
    corFundo.g=g;
    corFundo.b=b;
}
//Desenha o EstiloVisual do Componente

//Desenha o EstiloVisual do Componente
void UIBackgroundColor::desenhar()
{
    graphicSystem->gfx->setColor(corFundo.r,corFundo.g,corFundo.b);
    graphicSystem->gfx->retanguloPreenchido(posicao.x,posicao.y,dimensao.w,dimensao.h);

    graphicSystem->gfx->setColor(corBorda.r,corBorda.g,corBorda.b);
    graphicSystem->gfx->retangulo(posicao.x,posicao.y,dimensao.w,dimensao.h);
}
//Retorna uma copia do objeto
UIBackground * UIBackgroundColor::clone()
{
    UIBackgroundColor * uivSolido = new UIBackgroundColor();
    uivSolido->setCorBorda(corBorda.r,corBorda.g,corBorda.b);
    uivSolido->setCorFundo(corFundo.r,corFundo.g,corFundo.b);

    return uivSolido;
}

} // namespace UserInterface::Visual

} // namespace UserInterface
