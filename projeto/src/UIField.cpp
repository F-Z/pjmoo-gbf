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

#include "UIField.h"

namespace UserInterface
{

namespace Componente
{

UIField::UIField()
{
    tempoBlink.setTempoOriginal(0);
    tempoBlink.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    tempoBlink.setResetar();

    cursor.show = false;
    indice = 0;

    visual = NULL;
}

UIField::~UIField()
{
    //dtor
}

void UIField::setLabel(std::string label)
{
    this->label = label;
}

//Define a fonte a ser usada pelo label

//Define a fonte a ser usada pelo label
void UIField::setFonteLabel(std::string fonte)
{
    fonteLabel.nome = fonte;
    fonteLabel.dimensao = writeManager->getFonte(fonteLabel.nome)->getDimensao();
}

//Define a fonte a ser usada pelo Campo
void UIField::setFonteCampo(std::string fonte)
{
    fonteCampo.nome = fonte;
    fonteCampo.dimensao = writeManager->getFonte(fonteCampo.nome)->getDimensao();

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
    tempoBlink.setResetar();
}

void UIField::setCursorPosicao(int posicao)
{
    indice = posicao;
}

//Estilo Visual a ser Aplicado no Componente

void UIField::setVisual(UserInterface::Visual::UIVisual * visual)
{
    this->visual = visual;
}

//Desenha o conteudo da janela
void UIField::desenharBackground()
{
    //escrevendo label (Jogador - Pontos)
    writeManager->escreverLocalizado(fonteLabel.nome, fonteLabel.posicao.x, fonteLabel.posicao.y, label);

    if (visual != NULL)
    {
        visual->desenhar();
    }
}

void UIField::desenharForeground()
{
    //desenhando cursor
    if (cursor.show) {
        if (tempoBlink.getTempo() % 2 != 0) {
            graphicSystem->gfx->setColor(250, 250, 250);
            graphicSystem->gfx->retanguloPreenchido(cursor.posicao.x, cursor.posicao.y, fonteCampo.dimensao.w, 2);
        }
    }
}

void UIField::update()
{
    tempoBlink.processar();

    fonteLabel.posicao.x = position.x;
    fonteLabel.posicao.y = position.y;

    fonteCampo.posicao.x = position.x + (fonteCampo.dimensao.w * 0.2);
    fonteCampo.posicao.y = fonteLabel.posicao.y + (fonteLabel.dimensao.h * 1.2) + 1;

    cursor.posicao.x = fonteCampo.posicao.x + (indice * fonteCampo.dimensao.w);
    cursor.posicao.y = fonteCampo.posicao.y + fonteCampo.dimensao.h;

    if (visual != NULL){
        GBF::Dimensao d  = dimension;

        GBF::Ponto  p  = position;
        p.y = fonteLabel.posicao.y + (fonteLabel.dimensao.h * 1.2) - 1;

        visual->aplicar(p, dimension);
    }
}

void UIField::draw()
{
    desenharBackground();

    desenharConteudo();

    desenharForeground();
}

} // namespace UserInterface::Componente

} // namespace UserInterface
