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

#include "UIVisualImagem.h"

namespace UserInterface {

namespace Visual {

//Construtor
UIVisualImagem::UIVisualImagem() {
    tipoBackground = BACKGROUND_LINES;

    GBF::Image::SpriteFactory *spriteFactory = new GBF::Image::SpriteFactory("gbf-window-background");
    background = spriteFactory->createFrameLayer(0, 0, 10, 10);

    delete(spriteFactory);
}

//Destrutor
UIVisualImagem::~UIVisualImagem() {
    if (background) {
        delete(background);
    }
}

//Aplica o efeito visual
void UIVisualImagem::aplicar(const GBF::Ponto & posicao, const GBF::Dimensao & dimensao) {
    UIVisual::aplicar(posicao, dimensao);

    if (background != NULL) {
        background->setFrame(posicao.x, posicao.y, dimensao.w, dimensao.h);
        background->setTiles((dimensao.w / 10), (dimensao.h / 10));
        background->setPixelTile(10, 10);
        background->iniciarCom(tipoBackground);
    }
}

//Desenha o EstiloVisual do Componente

//Desenha o EstiloVisual do Componente
void UIVisualImagem::desenhar() {
    if (background != NULL) {
        background->desenhar();
    }

    graphicSystem->gfx->setColor(corBorda.r, corBorda.g, corBorda.b);

    graphicSystem->gfx->retangulo(posicao.x, posicao.y, dimensao.w, dimensao.h);
}

//Retorna uma copia do objeto
UIVisual * UIVisualImagem::clone() {
    UIVisualImagem * uivImagem = new UIVisualImagem();
    uivImagem->setCorBorda(corBorda.r, corBorda.g, corBorda.b);
    uivImagem->setTipoBackground(tipoBackground);

    return uivImagem;
}

//Define o estilo de background a ser utilizado

//Define o estilo de background a ser utilizado
void UIVisualImagem::setTipoBackground(UIBackground tipo) {
    tipoBackground = tipo;
}

} // namespace UserInterface::Visual

} // namespace UserInterface
