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

#ifndef _UIMENUABSTRACT_H
#define _UIMENUABSTRACT_H

#include "GBF.h"
#include <deque>
#include "UIItemAbstract.h"
#include "CronometroDecrescente.h"
#include "Cor.h"
#include "UserInterface.h"
#include "InputSystemUtility.h"

namespace UserInterface {

namespace Menu {

//Descrição: 
//    Classe para criação de menus
//Motivação:
//    Fornecer uma interface padrão para criação de menus
class UIMenuAbstract : public GBF::Kernel::Input::InputSystemUtility
{
  protected:
    int itemSelecionado;

    int espacoVertical;

    GBF::Ponto posicao;

    std::deque<UIItemAbstract *> item;

    GBF::Kernel::Timer::CronometroDecrescente delayNavegacao;


  public:
    //Construtor
    UIMenuAbstract();

    //Destrutor
    virtual ~UIMenuAbstract();

    void setEspacoVertical(int espaco);

    void setCorBorda(const GBF::Cor::CorPaleta & r, const GBF::Cor::CorPaleta & g, const GBF::Cor::CorPaleta & b);

    void setCorFundo(const GBF::Cor::CorPaleta & r, const GBF::Cor::CorPaleta & g, const GBF::Cor::CorPaleta & b);

    //Define a posição x,y do menu
    void setPosicao(int x, int y);

    //Centraliza o menu na tela de acordo com as coordenadas passadas
    //Obs.: Caso o parâmetro de alinhamento seja HORIZONTAL ou VERTICAL ele usará o parâmetro
    //referente a outra posição para posicionar o menu na tela
    void centralizarTela(int x, int y, UserInterface::UIAlinhamento alinhamento);

    bool executar();

    //Adiciona um item ao menu
    void adicionar(UIItemAbstract * item);

    //Retorna o índice da opção selecionada
    virtual int confirmarSelecao();


  protected:
    GBF::Ponto calcularAlinhamento(int caixaLargura, int caixaAltura);

    //desenha o menu na tela
    virtual void desenhar() = 0;

    //remove todos os itens do menu
    void limparLista();

    virtual void selecao();

    virtual bool navegar() = 0;

    int maiorPalavra;

    UserInterface::UIAlinhamento eAlinhamento;

    GBF::Cor::RGB corBorda;

    GBF::Cor::RGB corFundo;

};

} // namespace UserInterface::Menu

} // namespace UserInterface
#endif
