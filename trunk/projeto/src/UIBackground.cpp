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

#include "UIBackground.h"

namespace UserInterface {

namespace Look {

//Construtor
UIBackground::UIBackground(){
}

//Destrutor
UIBackground::~UIBackground(){
}

void UIBackground::setCorBorda(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corBorda.r = r;
    corBorda.g = g;
    corBorda.b = b;
}

//Aplica o efeito visual

//Aplica o efeito visual
void UIBackground::aplicar(const GBF::Point & posicao, const GBF::Dimension & dimensao)
{
    this->dimensao = dimensao;
    this->posicao = posicao;
}

} // namespace UserInterface::Visual

} // namespace UserInterface
