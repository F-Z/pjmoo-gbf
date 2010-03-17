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

#ifndef _UIWINDOWDIALOG_H
#define _UIWINDOWDIALOG_H

#include "UIBotao.h"
#include "UIWindow.h"
#include "UITexto.h"

namespace UserInterface {

namespace Window {

class UIWindowDialog : public UIWindow
{
  public:
    static const int BOTAO_OK;

    UIWindowDialog();

    virtual ~UIWindowDialog();

    void adicionarBotao(UserInterface::Componente::UIBotao * novoBotao);

    //Retorna se a ação informada foi acionado
    virtual bool isAcao(int tipoAcao);


  protected:
    int confirmarSelecao();


  public:
    UserInterface::Texto::UITexto texto;


  protected:
    UserInterface::Componente::UIBotao * botao;


  public:
    //Inicializa as configurações da caixa de texto
    virtual void inicializar();


  protected:
    //Desenha o conteudo da janela
    virtual void desenharConteudo();

    //Desenha a camada de decoração da janela (botões)
    virtual void desenharForeground();

    //atualiza as informações do componente (posicao, dimensao, estado)
    virtual void update();

};

} // namespace UserInterface::Window

} // namespace UserInterface
#endif
