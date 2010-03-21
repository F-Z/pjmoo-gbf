/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
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

        UserInterface::Component::UIKeyboard keyboard;

        UserInterface::Component::UITextField textName;

        UserInterface::Component::UINumberField textScore;

        RankingSystem::RSRecorde record;

        UserInterface::Visual::UIVisualSolido * uiVisualComponentes;

        int nameIndex;

        bool showErro;


    protected:
        void update();

        /** Desenha o bot�o de a��o da janela */
        void drawForeground();

        /** Desenha o conteudo da janela */
        void drawContent();

        /** Efetua as a��es de acordo com a posi��o do cursor */
        int confirmSelection();


    public:
        static const int BUTTON_SAVE;

        /** Inicializa as configura��es da caixa de texto */
        virtual void inicializar();

        UIWindowRecord();

        /** Destrutor */
        ~UIWindowRecord();

        /** Estilo Visual a ser Aplicado no Componente */
        void setVisualComponentes(UserInterface::Visual::UIVisualSolido * visual);

        /** Define a fonte a ser usada pelo Titulo */
        void setFontTitle(std::string font);

        void setFontKeyboard(std::string keyFont, std::string controlFont);

        void setFontInput(std::string fontLabel, std::string fontValue);

        /** Retorna o TopSystemRecorde */
        RankingSystem::RSRecorde getRecord();

        /** Atribui um RSRecorde para complementar os dados */
        void setRecord(RankingSystem::RSRecorde record);

        /** Gerencia o controle do cursor (navega��o) e as op��es selecionadas */
        bool isAction(int action);

};

} // namespace UserInterface::Window

} // namespace UserInterface

#endif
