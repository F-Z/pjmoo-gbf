////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#include "UIVisualSolido.h"

namespace UserInterface {

namespace Visual {

//Construtor
UIVisualSolido::UIVisualSolido()
{
}
//Destrutor
UIVisualSolido::~UIVisualSolido()
{
}
void UIVisualSolido::setCorFundo(const GBF::Color::CorPaleta & r, const GBF::Color::CorPaleta & g, const GBF::Color::CorPaleta & b)
{
    corFundo.r=r;
    corFundo.g=g;
    corFundo.b=b;
}
//Desenha o EstiloVisual do Componente

//Desenha o EstiloVisual do Componente
void UIVisualSolido::desenhar()
{
    graphicSystem->gfx->setColor(corFundo.r,corFundo.g,corFundo.b);
    graphicSystem->gfx->retanguloPreenchido(posicao.x,posicao.y,dimensao.w,dimensao.h);

    graphicSystem->gfx->setColor(corBorda.r,corBorda.g,corBorda.b);
    graphicSystem->gfx->retangulo(posicao.x,posicao.y,dimensao.w,dimensao.h);
}
//Retorna uma copia do objeto
UIVisual * UIVisualSolido::clone()
{
    UIVisualSolido * uivSolido = new UIVisualSolido();
    uivSolido->setCorBorda(corBorda.r,corBorda.g,corBorda.b);
    uivSolido->setCorFundo(corFundo.r,corFundo.g,corFundo.b);

    return uivSolido;
}

} // namespace UserInterface::Visual

} // namespace UserInterface
