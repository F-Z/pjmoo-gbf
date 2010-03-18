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

#ifndef _UIVISUALIMAGEM_H
#define _UIVISUALIMAGEM_H

#include "UIVisual.h"
#include "GBF.h"
#include "FrameLayer.h"
#include "SpriteFactory.h"

namespace UserInterface {

namespace Visual {

enum UIBackground {
    BACKGROUND_LINES = 0,
    BACKGROUND_RINGS = 1,
    BACKGROUND_CHESS = 2,
    BACKGROUND_SQUARE = 3
    ,
    BACKGROUND_LINES_BLACK = 4,
    BACKGROUND_CHESS_BLACK = 5
};

class UIVisualImagem : public UIVisual {
    public:
        //Construtor
        UIVisualImagem();

        //Destrutor
        virtual ~UIVisualImagem();

        //Aplica o efeito visual
        virtual void aplicar(const GBF::Point & posicao, const GBF::Dimension & dimensao);

        //Desenha o EstiloVisual do Componente
        virtual void desenhar();

        //Retorna uma copia do objeto
        virtual UIVisual * clone();

        //Define o estilo de background a ser utilizado
        void setTipoBackground(UIBackground tipo);


    protected:
        GBF::Image::Layer::FrameLayer * background;

        UIBackground tipoBackground;

};

} // namespace UserInterface::Visual

} // namespace UserInterface

#endif
