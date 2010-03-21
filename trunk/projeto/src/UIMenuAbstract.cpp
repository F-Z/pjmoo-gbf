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

    browseDelay.setInitialTime(2);
    browseDelay.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    browseDelay.setReset();
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

//Define a posição x,y do menu
void UIMenuAbstract::setPoint(int x, int y)
{
    point.x = x;
    point.y = y;
}

//Centraliza o menu na tela de acordo com as coordenadas passadas
//Obs.: Caso o parâmetro de alinhamento seja HORIZONTAL ou VERTICAL ele usará o parâmetro
//referente a outra posição para posicionar o menu na tela
void UIMenuAbstract::center(int x, int y, UserInterface::UIAlinhamento alinhamento)
{
    switch (alinhamento){

        case CENTRO:
            setPoint(x / 2, y / 2);
            break;

        case HORIZONTAL:
            setPoint(x / 2, y);
            break;

        case VERTICAL:
            setPoint(x, y / 2);
            break;
    }

    eAlinhamento = alinhamento;
}

bool UIMenuAbstract::execute()
{
    bool navegou = false;
    browseDelay.update();

    if (browseDelay.isFinish()){
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

//Retorna o índice da opção selecionada
int UIMenuAbstract::confirmSelection()
{
    int selecionado = -1;

    if (((inputSystem->keyboard->isKey(SDLK_RETURN)) || (inputSystem->joystick->isButtonA())) &&
            (browseDelay.isFinish())){
        browseDelay.setReset();
        selecionado = selectedItem;
    }

    return selecionado;
}

GBF::Point UIMenuAbstract::calcularAlinhamento(int caixaLargura, int caixaAltura)
{
    GBF::Point ponto;

    switch (eAlinhamento)
    {

        case CENTRO:
            ponto.x = point.x - (caixaLargura / 2);
            ponto.y = point.y - (caixaAltura / 2);
            break;

        case HORIZONTAL:
            ponto.x = point.x - (caixaLargura / 2);
            ponto.y = point.y;
            break;

        case VERTICAL:
            ponto.x = point.x;
            ponto.y = point.y - (caixaAltura / 2);
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
                item[i]->setActive(false);
            }
        }

        item[selectedItem]->setActive(true);
    }
}

} // namespace UserInterface::Menu

} // namespace UserInterface
