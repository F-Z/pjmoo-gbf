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

#include "UIMenuAbstract.h"

namespace UserInterface {

namespace Menu {

//Construtor
UIMenuAbstract::UIMenuAbstract()
{
    selectedItem = 0;
    maxCharItem = 0;
    verticalSpace = 0;

    browseDelay.setTempoOriginal(2);
    browseDelay.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    browseDelay.setResetar();
}

//Destrutor
UIMenuAbstract::~UIMenuAbstract()
{
}

void UIMenuAbstract::setVerticalSpace(int space)
{
    verticalSpace = space;
}

void UIMenuAbstract::setBorderColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corBorda.r = r;
    corBorda.g = g;
    corBorda.b = b;
}

void UIMenuAbstract::setBackgroundColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corFundo.r = r;
    corFundo.g = g;
    corFundo.b = b;
}

//Define a posi��o x,y do menu
void UIMenuAbstract::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

//Centraliza o menu na tela de acordo com as coordenadas passadas
//Obs.: Caso o par�metro de alinhamento seja HORIZONTAL ou VERTICAL ele usar� o par�metro
//referente a outra posi��o para posicionar o menu na tela
void UIMenuAbstract::center(int x, int y, UserInterface::UIAlinhamento alinhamento)
{
    switch (alinhamento){

        case CENTRO:
            setPosition(x / 2, y / 2);
            break;

        case HORIZONTAL:
            setPosition(x / 2, y);
            break;

        case VERTICAL:
            setPosition(x, y / 2);
            break;
    }

    eAlinhamento = alinhamento;
}

bool UIMenuAbstract::execute()
{
    bool navegou = false;
    browseDelay.processar();

    if (browseDelay.isTerminou()){
        navegou = browse();
        selection();
    }

    draw();

    return navegou;
}

//Adiciona um item ao menu
void UIMenuAbstract::add(UIItemAbstract * item)
{
    if (item != NULL) {
        this->item.push_back(item);
        int quantidadeLetra = item->getQuantidadeLetras();

        if (quantidadeLetra > maxCharItem){
            maxCharItem = quantidadeLetra;
        }
    }
}

//Retorna o �ndice da op��o selecionada
int UIMenuAbstract::confirmSelection()
{
    int selecionado = -1;

    if (((inputSystem->teclado->isKey(SDLK_RETURN)) || (inputSystem->joystick->isButtonA())) &&
            (browseDelay.isTerminou())){
        browseDelay.setResetar();
        selecionado = selectedItem;
    }

    return selecionado;
}

GBF::Ponto UIMenuAbstract::calcularAlinhamento(int caixaLargura, int caixaAltura)
{
    GBF::Ponto ponto;

    switch (eAlinhamento)
    {

        case CENTRO:
            ponto.x = position.x - (caixaLargura / 2);
            ponto.y = position.y - (caixaAltura / 2);
            break;

        case HORIZONTAL:
            ponto.x = position.x - (caixaLargura / 2);
            ponto.y = position.y;
            break;

        case VERTICAL:
            ponto.x = position.x;
            ponto.y = position.y - (caixaAltura / 2);
            break;
    }

    return ponto;
}

//remove todos os itens do menu
void UIMenuAbstract::clear()
{
    for (unsigned int i = 0; i < item.size(); i++){
        try {
            if (item[i] != NULL){
                delete item[i];
                item[i] = NULL;
            }
        } catch (...){
        }
    }

    item.clear();
}

void UIMenuAbstract::selection()
{
    if (!item.empty()){
        for (unsigned int i = 0; i < item.size(); i++){
            if (item[i] != NULL){
                item[i]->setAtivo(false);
            }
        }

        item[selectedItem]->setAtivo(true);
    }
}

} // namespace UserInterface::Menu

} // namespace UserInterface
