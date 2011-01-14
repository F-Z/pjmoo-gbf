/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _UIWINDOWRECORD_H
#define _UIWINDOWRECORD_H

#include "UserInterface.h"
#include "UIKeyboard.h"
#include "UITextField.h"
#include "UINumberField.h"
#include "Score.h"
#include "UIBackgroundColor.h"
#include <string>

#include "UIWindow.h"

namespace UserInterface {

namespace Window {

class UIWindowRecord : public UIWindow
{
    public:

        /** Construtor */
        UIWindowRecord();

        /** Destrutor */
        ~UIWindowRecord();

        static const int BUTTON_SAVE;

        /** Inicializa as configurações da caixa de texto */
        virtual void initialize();

        /** Estilo Visual a ser Aplicado no Componente */
        void setBackground(UserInterface::Look::UIBackgroundColor * background);

        /** Define a fonte a ser usada pelo Titulo */
        void setFontTitle(std::string font);

        void setFontKeyboard(std::string keyFont, std::string controlFont);

        void setFontInput(std::string fontLabel, std::string fontValue);

        /** Retorna o TopSystemRecorde */
        Score::Score getRecord();

        /** Atribui um RSRecorde para complementar os dados */
        void setRecord(Score::Score record);

        /** Gerencia o controle do cursor (navegação) e as opções selecionadas */
        bool isAction(int action);

    protected:

        void update();

        /** Desenha o botão de ação da janela */
        void drawForeground();

        /** Desenha o conteudo da janela */
        void drawContent();

        /** Efetua as ações de acordo com a posição do cursor */
        int confirmSelection();

    private:
        UserInterface::UIFontExtend fontTitle;

        UserInterface::UIFontExtend fontNotice;

        UserInterface::Component::UIKeyboard keyboard;

        UserInterface::Component::UITextField textName;

        UserInterface::Component::UINumberField textScore;

        Score::Score record;

        UserInterface::Look::UIBackgroundColor * background;

        int nameIndex;

        bool showErro;
};

} // namespace UserInterface::Window

} // namespace UserInterface

#endif
