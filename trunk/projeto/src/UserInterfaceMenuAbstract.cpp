////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "UserInterfaceMenuAbstract.h"

//Construtor
UserInterfaceMenuAbstract::UserInterfaceMenuAbstract(InputSystem * input) 
{
    this->input=input;
    
    itemSelecionado=0;
    maiorPalavra=0;
    
    delayNavegacao.setTempoOriginal(2);
    delayNavegacao.setUnidade(TEMPO_CENTESIMO);
    delayNavegacao.setResetar();
}
//Destrutor
UserInterfaceMenuAbstract::~UserInterfaceMenuAbstract() 
{
}
void UserInterfaceMenuAbstract::setEspacoVertical(int espaco) 
{
    espacoVertical=espaco;
}
void UserInterfaceMenuAbstract::setCorBorda(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b) 
{
    corBorda.r=r;
    corBorda.g=g;
    corBorda.b=b;
}
void UserInterfaceMenuAbstract::setCorFundo(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b) 
{
    corFundo.r=r;
    corFundo.g=g;
    corFundo.b=b;
}
//Define a posição x,y do menu
void UserInterfaceMenuAbstract::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
}
//Centraliza o menu na tela de acordo com as coordenadas passadas
//Obs.: Caso o parâmetro de alinhamento seja HORIZONTAL ou VERTICAL ele usará o parâmetro
//referente a outra posição para posicionar o menu na tela
void UserInterfaceMenuAbstract::centralizarTela(int x, int y, EnumAlinhamento alinhamento) 
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
bool UserInterfaceMenuAbstract::executar() 
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
void UserInterfaceMenuAbstract::adicionar(UserInterfaceMenuItemAbstract * item) 
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
int UserInterfaceMenuAbstract::confirmarSelecao() 
{
    int selecionado = -1;
    
    if (((input->teclado->isKey(SDLK_RETURN))||(input->joystick->isButtonA()))&&
        (delayNavegacao.isTerminou())){
        delayNavegacao.setResetar();
        selecionado=itemSelecionado;
    }
    
    return selecionado;
}
Ponto UserInterfaceMenuAbstract::calcularAlinhamento(int caixaLargura, int caixaAltura) 
{
    Ponto ponto;
    
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
void UserInterfaceMenuAbstract::limparLista() 
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
void UserInterfaceMenuAbstract::selecao() 
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
