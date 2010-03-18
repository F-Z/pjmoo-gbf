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

#ifndef _UIVISUAL_H
#define _UIVISUAL_H

#include "Color.h"
#include "GBF.h"
#include "GraphicSystemUtility.h"

namespace UserInterface {

namespace Visual {

class UIVisual : public GBF::Kernel::Graphic::GraphicSystemUtility
{
  public:
    //Construtor
    UIVisual();

    //Destrutor
    virtual ~UIVisual();

    void setCorBorda(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b);

    //Aplica o efeito visual
    virtual void aplicar(const GBF::Point & posicao, const GBF::Dimension & dimensao);

    //Desenha o EstiloVisual do Componente
    virtual void desenhar() = 0;

    virtual UIVisual * clone() = 0;


  protected:
    GBF::Color::RGB corBorda;

    GBF::Point posicao;

    GBF::Dimension dimensao;

};

} // namespace UserInterface::Visual

} // namespace UserInterface
#endif
