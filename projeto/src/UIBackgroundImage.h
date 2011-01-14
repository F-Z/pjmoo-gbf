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
#ifndef _UIBACKGROUNDIMAGE_H
#define _UIBACKGROUNDIMAGE_H

#include "UIBackground.h"
#include "GBF.h"
#include "FrameLayer.h"
#include "SpriteFactory.h"

namespace UserInterface {

namespace Look {

enum UIBackgroundImageType
{
    BACKGROUND_LINES = 0,
    BACKGROUND_RINGS = 1,
    BACKGROUND_CHESS = 2,
    BACKGROUND_SQUARE = 3,
    BACKGROUND_LINES_BLACK = 4,
    BACKGROUND_CHESS_BLACK = 5
};

class UIBackgroundImage : public UIBackground
{

    public:
        /** Construtor */
        UIBackgroundImage();

        /** Destrutor */
        virtual ~UIBackgroundImage();

        /** Aplica o efeito visual */
        virtual void apply(const GBF::Point & point, const GBF::Dimension & dimension);

        /** Desenha o EstiloVisual do Componente */
        virtual void draw();

        /** Retorna uma copia do objeto */
        virtual UIBackground * clone();

        /** Define o estilo de background a ser utilizado */
        void setImageType(UIBackgroundImageType imageType);


    protected:
        GBF::Image::Layer::FrameLayer * background;

        UIBackgroundImageType imageType;

};

} // namespace UserInterface::Look

} // namespace UserInterface

#endif
