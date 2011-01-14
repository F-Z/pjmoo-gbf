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
#ifndef _UIBACKGROUNDCOLOR_H
#define _UIBACKGROUNDCOLOR_H

#include "UIBackground.h"
#include "Color.h"

namespace UserInterface {

namespace Look {

class UIBackgroundColor : public UIBackground
{

    public:
        /** Construtor */
        UIBackgroundColor();

        /** Destrutor */
        virtual ~UIBackgroundColor();

        void setColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b);

        /** Desenha o EstiloVisual do Componente */
        virtual void draw();

        /** Retorna uma copia do objeto */
        virtual UIBackground * clone();


    protected:
        GBF::Color::RGB color;

};

} // namespace UserInterface::Look

} // namespace UserInterface

#endif
