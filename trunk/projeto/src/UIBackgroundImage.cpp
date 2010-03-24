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

#include "UIBackgroundImage.h"

namespace UserInterface {

namespace Look {

//Construtor
UIBackgroundImage::UIBackgroundImage() {
    tipoBackground = BACKGROUND_LINES;

    GBF::Image::SpriteFactory *spriteFactory = new GBF::Image::SpriteFactory("gbf-window-background");
    background = spriteFactory->createFrameLayer(0, 0, 10, 10);

    delete(spriteFactory);
}

//Destrutor
UIBackgroundImage::~UIBackgroundImage() {
    if (background) {
        delete(background);
    }
}

//Aplica o efeito visual
void UIBackgroundImage::aplicar(const GBF::Point & posicao, const GBF::Dimension & dimensao) {
    UIBackground::aplicar(posicao, dimensao);

    if (background != NULL) {
        background->setFrame(posicao.x, posicao.y, dimensao.w, dimensao.h);
        background->setTiles((dimensao.w / 10), (dimensao.h / 10));
        background->setPixelTile(10, 10);
        background->iniciarCom(tipoBackground);
    }
}

//Desenha o EstiloVisual do Componente

//Desenha o EstiloVisual do Componente
void UIBackgroundImage::desenhar()
{
    if (background != NULL) {
        background->draw();
    }

    graphicSystem->gfx->setColor(corBorda.r, corBorda.g, corBorda.b);

    graphicSystem->gfx->retangulo(posicao.x, posicao.y, dimensao.w, dimensao.h);
}

//Retorna uma copia do objeto
UIBackground * UIBackgroundImage::clone()
{
    UIBackgroundImage * uivImagem = new UIBackgroundImage();
    uivImagem->setCorBorda(corBorda.r, corBorda.g, corBorda.b);
    uivImagem->setTipoBackground(tipoBackground);

    return uivImagem;
}

//Define o estilo de background a ser utilizado

//Define o estilo de background a ser utilizado
void UIBackgroundImage::setTipoBackground(UIBackgroundImageType tipo) {
    tipoBackground = tipo;
}

} // namespace UserInterface::Visual

} // namespace UserInterface
