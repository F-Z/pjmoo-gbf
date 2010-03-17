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

#ifndef _UIWINDOWRECORD_H
#define _UIWINDOWRECORD_H

#include "UserInterface.h"
#include "UITecladoVirtual.h"
#include "UITextField.h"
#include "UINumberField.h"
#include "RSRecorde.h"
#include "UIVisualSolido.h"
#include <string>

#include "UIWindow.h"

namespace UserInterface {

namespace Window {

class UIWindowRecord : public UIWindow
{
  private:
    UserInterface::UIFonteExtendida fontTitle;

    UserInterface::UIFonteExtendida fontNotice;

    UserInterface::Componente::UITecladoVirtual keyboard;

    UserInterface::Componente::UITextField textName;

    UserInterface::Componente::UINumberField textScore;

    RankingSystem::RSRecorde record;

    UserInterface::Visual::UIVisualSolido * uiVisualComponentes;

    int nameIndex;

    bool showErro;


  protected:
    void update();

    //Desenha o botão de ação da janela
    void desenharForeground();

    //Desenha o conteudo da janela
    void desenharConteudo();

    //Efetua as ações de acordo com a posição do cursor
    int confirmSelection();


  public:
    static const int BUTTON_SAVE;

    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    UIWindowRecord();

    //Destrutor
    ~UIWindowRecord();

    //Estilo Visual a ser Aplicado no Componente
    void setVisualComponentes(UserInterface::Visual::UIVisualSolido * visual);

    //Define a fonte a ser usada pelo Titulo
    void setFontTitle(std::string font);

    void setFontVirtualKeyboard(std::string keyFont, std::string controlFont);

    void setFontEdition(std::string fontLabel, std::string fontValue);

    //Retorna o TopSystemRecorde
    RankingSystem::RSRecorde getRecord();

    //Atribui um RSRecorde para complementar os dados
    void setRecord(RankingSystem::RSRecorde record);

    //Gerencia o controle do cursor (navegação) e as opções selecionadas
    bool isAction(int action);

};

} // namespace UserInterface::Window

} // namespace UserInterface
#endif
