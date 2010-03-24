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
#ifndef _UIWINDOW_H
#define _UIWINDOW_H

#include "UIComponent.h"
#include "InputSystemUtility.h"
#include "UIBackground.h"
#include "TimerRegressive.h"

namespace UserInterface {

namespace Window {

class UIWindow : public UserInterface::UIComponent, public GBF::Kernel::Input::InputSystemUtility
{

    public:
        /** Construtor */
        UIWindow();

        /** Destrutor */
        virtual ~UIWindow();

        void setDimension(int largura, int altura);

        /** Inicializa as configurações da caixa de texto */
        virtual void inicializar();

        /** Estilo Visual a ser Aplicado no Componente */
        void setBackground(UserInterface::Look::UIBackground * background);

        /** Retorna se a ação informada foi acionado */
        virtual bool isAction(int tipoAcao) = 0;


    protected:
        int espacoAntesTexto;

        GBF::Kernel::Timer::TimerRegressive tempoEspera;

        /** atualiza as informações do componente (posicao, dimensao, estado) */
        virtual void update();

        /** desenha os componentes vistuais */
        void draw();

        /** Desenha o background da caixa de texto */
        virtual void drawBackground();

        /** Desenha o conteudo da janela */
        virtual void drawContent() = 0;

        /** Desenha a camada de decoração da janela (botões) */
        virtual void drawForeground();

        UserInterface::Look::UIBackground * background;

};

} //  namespace UserInterface::Window

} //  namespace UserInterface

#endif
