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

#ifndef _UIWINDOW_H
#define _UIWINDOW_H

#include "UIComponente.h"
#include "InputSystemUtility.h"
#include "UIVisual.h"
#include "CronometroDecrescente.h"

namespace UserInterface {

namespace Window {

class UIWindow : public UserInterface::UIComponente, public GBF::Kernel::Input::InputSystemUtility
{
  public:
    //Construtor
    UIWindow();

    //Destrutor
    virtual ~UIWindow();

    void setDimensao(int largura, int altura);

    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    //Estilo Visual a ser Aplicado no Componente
    void setVisual(UserInterface::Visual::UIVisual * visual);

    //Retorna se a ação informada foi acionado
    virtual bool isAcao(int tipoAcao) = 0;


  protected:
    int espacoAntesTexto;

    GBF::Kernel::Timer::CronometroDecrescente tempoEspera;

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

    UserInterface::Visual::UIVisual * visual;

};

} // namespace UserInterface::Window

} // namespace UserInterface
#endif
