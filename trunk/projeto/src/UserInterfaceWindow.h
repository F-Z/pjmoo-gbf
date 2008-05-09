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

#ifndef _USERINTERFACEWINDOW_H
#define _USERINTERFACEWINDOW_H

#include "UserInterfaceComponente.h"
#include "InputSystemUtility.h"
#include "UserInterfaceVisual.h"
#include "TimerSystemCronometroDecrescente.h"

class UserInterfaceWindow : public UserInterfaceComponente, public InputSystemUtility
{
  public:
    //Construtor
    UserInterfaceWindow();

    //Destrutor
    virtual ~UserInterfaceWindow();

    void setDimensao(int largura, int altura);

    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    //Estilo Visual a ser Aplicado no Componente
    void setVisual(UserInterfaceVisual * visual);

    //Retorna se a ação informada foi acionado
    virtual bool isAcao(int tipoAcao) = 0;


  protected:
    int espacoAntesTexto;

    TimerSystemCronometroDecrescente tempoEspera;

    //atualiza as informações do componente (posicao, dimensao, estado)
    virtual void atualizar();

    //desenha os componentes vistuais
    void desenhar();

    //Desenha o background da caixa de texto
    virtual void desenharBackground();

    //Desenha o conteudo da janela
    virtual void desenharConteudo() = 0;

    //Desenha a camada de decoração da janela (botões)
    virtual void desenharForeground();

    UserInterfaceVisual * visual;

};
#endif
