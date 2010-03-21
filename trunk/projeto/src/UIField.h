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

#ifndef _UIFIELD_H
#define _UIFIELD_H

#include <string>

#include "UIVisual.h"
#include "UserInterface.h"
#include "UIComponent.h"
#include "GraphicSystemUtility.h"
#include "Timer.h"

namespace UserInterface
{

namespace Component
{

class UIField : public UserInterface::UIComponent, public GBF::Kernel::Graphic::GraphicSystemUtility
{
    public:
        UIField();

        virtual ~UIField();

        void setLabel(std::string label);

        /** Define a fonte a ser usada pelo label */
        void setFont(std::string font);

        /** Define a fonte a ser usada pelo Campo */
        void setFontInput(std::string font);

        void maxLength(int length);

        void showCursor(bool show);

        void setCursorPosicao(int posicao);

        void setVisual(UserInterface::Visual::UIVisual * visual);


    protected:
        UserInterface::UIFonteExtendida fonteLabel;

        UserInterface::UIFonteExtendida fonteCampo;

        UserInterface::UICursor cursor;

        int indice;

        /** Desenha o conteudo da janela */
        void drawBackground();

        virtual void drawContent() = 0;

        void drawForeground();

        void update();

        void draw();

        UserInterface::Visual::UIVisual * visual;


    private:
        std::string label;

        int length;


    protected:
        GBF::Kernel::Timer::Timer tempoBlink;

};

} // namespace UserInterface::Componente

} // namespace UserInterface

#endif
