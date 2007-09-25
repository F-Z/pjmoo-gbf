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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#ifndef _USERINTERFACEWINDOW_H
#define _USERINTERFACEWINDOW_H

#include "UserInterfaceComponente.h"
#include "InputSystem.h"
#include "UserInterfaceVisual.h"
#include "UserInterfaceBotao.h"
#include "GBF_define.h"
#include "UserInterfaceObjetoTexto.h"
#include "TimerSystemCronometroDecrescente.h"

class UserInterfaceWindow : public UserInterfaceComponente
{
  public:
    static const int BOTAO_OK;

    //Construtor
    UserInterfaceWindow();

    //Destrutor
    virtual ~UserInterfaceWindow();

    //Configura o dispositivo de Input
    static void setInputSystem(InputSystem * input);

    virtual void executar();

    //Posicação da Caixa na tela
    void setPosicao(int x, int y);

    void setDimensao(int largura, int altura);

    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    //Estilo Visual a ser Aplicado no Componente
    void setVisual(UserInterfaceVisual * visual);

    void adicionarBotao(UserInterfaceBotao * novoBotao);

    int confirmarSelecao();

    //Retorna se o Botão informado foi acionado
    bool isBotao(int tipoBotao);


  protected:
    Dimensao dimensao;

    Ponto posicao;

    int espacoAntesTexto;

    UserInterfaceTextoAlinhamento textoAlinhamento;

    //Desenha o background da caixa de texto
    void desenharBackground();

    //Desenha o conteudo da janela
    virtual void desenharConteudo();

    //Desenha o botão de ação da janela
    void desenharBotao();


  public:
    UserInterfaceObjetoTexto texto;


  protected:
    UserInterfaceVisual * visual;

    UserInterfaceBotao * botao;

    TimerSystemCronometroDecrescente tempoEspera;

    static InputSystem * input;

};
#endif
