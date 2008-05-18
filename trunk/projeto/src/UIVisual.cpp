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

#include "UIVisual.h"

namespace UserInterface {

namespace Visual {

//Construtor
UIVisual::UIVisual(){
}

//Destrutor
UIVisual::~UIVisual(){
}

void UIVisual::setCorBorda(const GBF::Cor::CorPaleta & r, const GBF::Cor::CorPaleta & g, const GBF::Cor::CorPaleta & b) 
{
    corBorda.r=r;
    corBorda.g=g;
    corBorda.b=b;
}
//Aplica o efeito visual

//Aplica o efeito visual
void UIVisual::aplicar(const GBF::Ponto & posicao, const GBF::Dimensao & dimensao) 
{
    this->dimensao=dimensao;
    this->posicao=posicao;
}

} // namespace UserInterface::Visual

} // namespace UserInterface
