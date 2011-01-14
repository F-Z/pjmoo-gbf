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
#include "UIField.h"

namespace UserInterface {

namespace Component {

UIField::UIField()
{
    tempoBlink.setInitialTime(0);
    tempoBlink.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoBlink.setReset();

    cursor.show = false;
    indice = 0;

    background = NULL;
}

UIField::~UIField()
{
}

void UIField::setLabel(std::string label)
{
    this->label = label;
}

/** Define a fonte a ser usada pelo label */
void UIField::setFont(std::string font)
{
    fonteLabel.name = font;
    fonteLabel.dimension = writeManager->getFont(fonteLabel.name)->getDimension();
}

/** Define a fonte a ser usada pelo Campo */
void UIField::setFontInput(std::string font)
{
    fonteCampo.name = font;
    fonteCampo.dimension = writeManager->getFont(fonteCampo.name)->getDimension();

    dimension.w = (length * fonteCampo.dimension.w) + (fonteCampo.dimension.w * 0.2);
    dimension.h = (fonteCampo.dimension.h) * 1.6;
}

void UIField::maxLength(int length)
{
    this->length = length;
}

void UIField::showCursor(bool show)
{
    cursor.show = show;
    tempoBlink.setReset();
}

void UIField::setCursorPosicao(int posicao)
{
    indice = posicao;
}

/** Estilo Visual a ser Aplicado no Componente */
void UIField::setBackground(UserInterface::Look::UIBackground * background)
{
    this->background = background;
}

/** Desenha o conteudo da janela */
void UIField::drawBackground()
{
    //escrevendo label (Jogador - Pontos)
    writeManager->writeKeyText(fonteLabel.name, fonteLabel.point.x, fonteLabel.point.y, label);

    if (background != NULL)
    {
        background->draw();
    }
}

void UIField::drawForeground()
{
    //desenhando cursor
    if (cursor.show) {
        if (tempoBlink.getTime() % 2 != 0) {
            graphicSystem->gfx->setColor(250, 250, 250);
            graphicSystem->gfx->rectangleFill(cursor.point.x, cursor.point.y, fonteCampo.dimension.w, 2);
        }
    }
}

void UIField::update()
{
    tempoBlink.update();

    fonteLabel.point.x = point.x;
    fonteLabel.point.y = point.y;

    fonteCampo.point.x = point.x + (fonteCampo.dimension.w * 0.2);
    fonteCampo.point.y = fonteLabel.point.y + (fonteLabel.dimension.h * 1.2) + 1;

    cursor.point.x = fonteCampo.point.x + (indice * fonteCampo.dimension.w);
    cursor.point.y = fonteCampo.point.y + fonteCampo.dimension.h;

    if (background != NULL){
        GBF::Dimension d  = dimension;

        GBF::Point  p  = point;
        p.y = fonteLabel.point.y + (fonteLabel.dimension.h * 1.2) - 1;

        background->apply(p, dimension);
    }
}

void UIField::draw()
{
    drawBackground();

    drawContent();

    drawForeground();
}

} // namespace UserInterface::Component

} // namespace UserInterface
