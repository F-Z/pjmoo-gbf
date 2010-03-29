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
#ifndef _UIWINDOWDIALOG_H
#define _UIWINDOWDIALOG_H

#include "UIButton.h"
#include "UIWindow.h"
#include "UIText.h"

namespace UserInterface {

namespace Window {

class UIWindowDialog : public UIWindow
{
    public:

        static const int BUTTON_OK;

        UIWindowDialog();

        virtual ~UIWindowDialog();

        void addButton(UserInterface::Component::UIButton * button);

        /** Retorna se a ação informada foi acionado */
        virtual bool isAction(int action);

        UserInterface::Text::UIText text;

        /** Inicializa as configurações da caixa de texto */
        virtual void initialize();


    protected:

        int confirmSelection();

        UserInterface::Component::UIButton * button;

        /** Desenha o conteudo da janela */
        virtual void drawContent();

        /** Desenha a camada de decoração da janela (botões) */
        virtual void drawForeground();

        /** atualiza as informações do componente (posicao, dimensao, estado) */
        virtual void update();

};

} // namespace UserInterface::Window

} // namespace UserInterface

#endif
