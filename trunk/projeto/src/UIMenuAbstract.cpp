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
    itemSelecionado=0;
    maiorPalavra=0;

    delayNavegacao.setTempoOriginal(2);
    delayNavegacao.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    delayNavegacao.setResetar();
}
//Destrutor
UIMenuAbstract::~UIMenuAbstract()
{
}
void UIMenuAbstract::setEspacoVertical(int espaco)
{
    espacoVertical=espaco;
}
void UIMenuAbstract::setCorBorda(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corBorda.r=r;
    corBorda.g=g;
    corBorda.b=b;
}
void UIMenuAbstract::setCorFundo(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corFundo.r=r;
    corFundo.g=g;
    corFundo.b=b;
}
//Define a posição x,y do menu
void UIMenuAbstract::setPosicao(int x, int y)
{
    posicao.x=x;
    posicao.y=y;
}
//Centraliza o menu na tela de acordo com as coordenadas passadas
//Obs.: Caso o parâmetro de alinhamento seja HORIZONTAL ou VERTICAL ele usará o parâmetro
//referente a outra posição para posicionar o menu na tela
void UIMenuAbstract::centralizarTela(int x, int y, UserInterface::UIAlinhamento alinhamento)
{
    switch(alinhamento){
        case CENTRO:
                setPosicao(x/2,y/2);
            break;
        case HORIZONTAL:
                setPosicao(x/2,y);
            break;
        case VERTICAL:
                setPosicao(x,y/2);
            break;
    }

    eAlinhamento=alinhamento;
}
bool UIMenuAbstract::executar()
{
    bool navegou = false;
    delayNavegacao.processar();

    if (delayNavegacao.isTerminou()){
        navegou=navegar();
        selecao();
    }
    desenhar();

    return navegou;
}
//Adiciona um item ao menu
void UIMenuAbstract::adicionar(UIItemAbstract * item)
{
    if (item!=NULL) {
        this->item.push_back(item);
        int quantidadeLetra = item->getQuantidadeLetras();

        if (quantidadeLetra>maiorPalavra){
            maiorPalavra=quantidadeLetra;
        }
    }
}
//Retorna o índice da opção selecionada
int UIMenuAbstract::confirmarSelecao()
{
    int selecionado = -1;

    if (((inputSystem->teclado->isKey(SDLK_RETURN))||(inputSystem->joystick->isButtonA()))&&
        (delayNavegacao.isTerminou())){
        delayNavegacao.setResetar();
        selecionado=itemSelecionado;
    }

    return selecionado;
}
GBF::Ponto UIMenuAbstract::calcularAlinhamento(int caixaLargura, int caixaAltura)
{
    GBF::Ponto ponto;

    switch (eAlinhamento)
    {
        case CENTRO:
                ponto.x=posicao.x-(caixaLargura/2);
                ponto.y=posicao.y-(caixaAltura/2);
            break;

        case HORIZONTAL:
                ponto.x=posicao.x-(caixaLargura/2);
                ponto.y=posicao.y;
            break;

        case VERTICAL:
                ponto.x=posicao.x;
                ponto.y=posicao.y-(caixaAltura/2);
            break;
    }

    return ponto;
}
//remove todos os itens do menu
void UIMenuAbstract::limparLista()
{
    for (unsigned int i=0; i<item.size(); i++){
        try {
            if (item[i]!=NULL){
                delete item[i];
                item[i]=NULL;
            }
        } catch (...){
        }
    }

    item.clear();
}
void UIMenuAbstract::selecao()
{
    if (!item.empty()){
        for (unsigned int i=0; i<item.size(); i++){
            if (item[i]!=NULL){
                item[i]->setAtivo(false);
            }
        }
        item[itemSelecionado]->setAtivo(true);
    }
}

} // namespace UserInterface::Menu

} // namespace UserInterface
