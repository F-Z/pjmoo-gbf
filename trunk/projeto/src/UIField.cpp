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

#include "UIField.h"

namespace UserInterface
{

namespace Component
{

UIField::UIField()
{
    tempoBlink.setInitialTime(0);
    tempoBlink.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoBlink.setReset();

    cursor.show = false;
    indice = 0;

    visual = NULL;
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
    fonteLabel.nome = font;
    fonteLabel.dimensao = writeManager->getFont(fonteLabel.nome)->getDimensao();
}

/** Define a fonte a ser usada pelo Campo */
void UIField::setFontInput(std::string font)
{
    fonteCampo.nome = font;
    fonteCampo.dimensao = writeManager->getFont(fonteCampo.nome)->getDimensao();

    dimension.w = (length * fonteCampo.dimensao.w) + (fonteCampo.dimensao.w * 0.2);
    dimension.h = (fonteCampo.dimensao.h) * 1.6;
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
void UIField::setVisual(UserInterface::Visual::UIVisual * visual)
{
    this->visual = visual;
}

/** Desenha o conteudo da janela */
void UIField::drawBackground()
{
    //escrevendo label (Jogador - Pontos)
    writeManager->writeKeyText(fonteLabel.nome, fonteLabel.posicao.x, fonteLabel.posicao.y, label);

    if (visual != NULL)
    {
        visual->desenhar();
    }
}

void UIField::drawForeground()
{
    //desenhando cursor
    if (cursor.show) {
        if (tempoBlink.getTime() % 2 != 0) {
            graphicSystem->gfx->setColor(250, 250, 250);
            graphicSystem->gfx->retanguloPreenchido(cursor.point.x, cursor.point.y, fonteCampo.dimensao.w, 2);
        }
    }
}

void UIField::update()
{
    tempoBlink.update();

    fonteLabel.posicao.x = point.x;
    fonteLabel.posicao.y = point.y;

    fonteCampo.posicao.x = point.x + (fonteCampo.dimensao.w * 0.2);
    fonteCampo.posicao.y = fonteLabel.posicao.y + (fonteLabel.dimensao.h * 1.2) + 1;

    cursor.point.x = fonteCampo.posicao.x + (indice * fonteCampo.dimensao.w);
    cursor.point.y = fonteCampo.posicao.y + fonteCampo.dimensao.h;

    if (visual != NULL){
        GBF::Dimension d  = dimension;

        GBF::Point  p  = point;
        p.y = fonteLabel.posicao.y + (fonteLabel.dimensao.h * 1.2) - 1;

        visual->aplicar(p, dimension);
    }
}

void UIField::draw()
{
    drawBackground();

    drawContent();

    drawForeground();
}

} // namespace UserInterface::Componente

} // namespace UserInterface
