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

#ifndef _UIKEYBOARD_H
#define _UIKEYBOARD_H

#include "Color.h"
#include <string>

#include "UserInterface.h"
#include "UIVisual.h"
#include "GraphicSystemUtility.h"
#include "UIComponent.h"
#include "InputSystemUtility.h"
#include "TimerRegressive.h"
#include "Timer.h"

namespace UserInterface
{

namespace Component
{

class UIKeyboard : public GBF::Kernel::Graphic::GraphicSystemUtility, public UserInterface::UIComponent, public GBF::Kernel::Input::InputSystemUtility
{

    private:
        //Efetua o controle sobre a navegação do cursor
        void browse();

        GBF::Color::RGB corCursor;


    protected:
        char caracter[50];

        std::string controle[3];

        UserInterface::UIFonteReferencia fontKey;

        UserInterface::UIFonteReferencia fontControl;

        int selecao;

        int tamanhoControle;

        UserInterface::Visual::UIVisual * visual;

        void drawBackground();

        void drawContent();

        void update();

        void draw();


    public:
        UIKeyboard();

        virtual ~UIKeyboard();

        int getTotalCaracter();

        int getTotalControle();

        int getTotalTeclas();

        int getTamanhoControle();

        void setCaracter(std::string caracteres);

        void addControl(int index, std::string text);

        char getCaracter();

        int getIndex();

        //Define a fonte a ser usada pelo Controle
        void setFontControl(std::string fonte);

        //Define a fonte a ser usada pelo teclado virtual
        void setFontKey(std::string fonte);

        void setVisual(UserInterface::Visual::UIVisual * visual);

        void setColorCursor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b);


    protected:
        GBF::Kernel::Timer::TimerRegressive tempoEspera;

        GBF::Kernel::Timer::Timer tempoBlink;

};

} // namespace UserInterface::Componente

} // namespace UserInterface

#endif
