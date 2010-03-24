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

/** Construtor */
UIBackgroundImage::UIBackgroundImage()
{
    imageType = BACKGROUND_LINES;

    GBF::Image::SpriteFactory *spriteFactory = new GBF::Image::SpriteFactory("gbf-window-background");
    background = spriteFactory->createFrameLayer(0, 0, 10, 10);

    delete(spriteFactory);
}

/** Destrutor */
UIBackgroundImage::~UIBackgroundImage()
{
    if (background) {
        delete(background);
    }
}

/** Aplica o efeito visual */
void UIBackgroundImage::apply(const GBF::Point & point, const GBF::Dimension & dimension)
{
    UIBackground::apply(point, dimension);

    if (background != NULL) {
        background->setFrame(point.x, point.y, dimension.w, dimension.h);
        background->setTiles((dimension.w / 10), (dimension.h / 10));
        background->setPixelTile(10, 10);
        background->iniciarCom(imageType);
    }
}

/** Desenha o EstiloVisual do Componente */
void UIBackgroundImage::draw()
{
    if (background != NULL) {
        background->draw();
    }

    graphicSystem->gfx->setColor(borderColor.r, borderColor.g, borderColor.b);

    graphicSystem->gfx->retangulo(point.x, point.y, dimension.w, dimension.h);
}

/** Retorna uma copia do objeto */
UIBackground * UIBackgroundImage::clone()
{
    UIBackgroundImage * clone = new UIBackgroundImage();
    clone->setBorderColor(borderColor.r, borderColor.g, borderColor.b);
    clone->setImageType(imageType);

    return clone;
}

/** Define o estilo de background a ser utilizado */
void UIBackgroundImage::setImageType(UIBackgroundImageType imageType)
{
    this->imageType = imageType;
}

} // namespace UserInterface::Look

} // namespace UserInterface
