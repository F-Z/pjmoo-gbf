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

#ifndef _UIBACKGROUND_H
#define _UIBACKGROUND_H

#include "Color.h"
#include "GBF.h"
#include "GraphicSystemUtility.h"

namespace UserInterface {

namespace Look {

class UIBackground : public GBF::Kernel::Graphic::GraphicSystemUtility
{

    public:
        //Construtor
        UIBackground();

        //Destrutor
        virtual ~UIBackground();

        void setCorBorda(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b);

        //Aplica o efeito visual
        virtual void aplicar(const GBF::Point & posicao, const GBF::Dimension & dimensao);

        //Desenha o EstiloVisual do Componente
        virtual void desenhar() = 0;

        virtual UIBackground * clone() = 0;


    protected:
        GBF::Color::RGB corBorda;

        GBF::Point posicao;

        GBF::Dimension dimensao;

};

} // namespace UserInterface::Visual

} // namespace UserInterface

#endif
