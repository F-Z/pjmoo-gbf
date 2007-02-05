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

#ifndef _USERINTERFACEMENUABSTRACT_H
#define _USERINTERFACEMENUABSTRACT_H

#include "GBF_define.h"
#include <deque>
#include "UserInterfaceMenuItemAbstract.h"
#include "TimerSystemCronometroDecrescente.h"
#include "InputSystem.h"
#include "UserInterface.h"
#include "UtilColor.h"

//Descrição: 
//    Classe para criação de menus
//Motivação:
//    Fornecer uma interface padrão para criação de menus
class UserInterfaceMenuAbstract
{
  protected:
    Ponto posicao;

    int itemSelecionado;

    int espacoVertical;

    std::deque<UserInterfaceMenuItemAbstract *> item;

    TimerSystemCronometroDecrescente delayNavegacao;

    InputSystem * input;


  public:
    //Construtor
    UserInterfaceMenuAbstract(InputSystem * input);

    //Destrutor
    virtual ~UserInterfaceMenuAbstract();

    void setEspacoVertical(int espaco);

    void setCorBorda(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b);

    void setCorFundo(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b);

    //Define a posição x,y do menu
    void setPosicao(int x, int y);

    //Centraliza o menu na tela de acordo com as coordenadas passadas
    //Obs.: Caso o parâmetro de alinhamento seja HORIZONTAL ou VERTICAL ele usará o parâmetro
    //referente a outra posição para posicionar o menu na tela
    void centralizarTela(int x, int y, EnumAlinhamento alinhamento);

    bool executar();

    //Adiciona um item ao menu
    void adicionar(UserInterfaceMenuItemAbstract * item);

    //Retorna o índice da opção selecionada
    virtual int confirmarSelecao();


  protected:
    Ponto calcularAlinhamento(int caixaLargura, int caixaAltura);

    //desenha o menu na tela
    virtual void desenhar() = 0;

    //remove todos os itens do menu
    void limparLista();

    virtual void selecao();

    virtual bool navegar() = 0;

    int maiorPalavra;

    EnumAlinhamento eAlinhamento;

    RGB corBorda;

    RGB corFundo;


};
#endif
