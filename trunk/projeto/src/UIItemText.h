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

#ifndef _UIITEMTEXT_H
#define _UIITEMTEXT_H

#include <string>

#include "CronometroCrescente.h"
#include "WriteManager.h"
#include "GBF.h"
#include "UIItemAbstract.h"

namespace UserInterface {

namespace Menu {

//Descrição:
//    Implementação da Classe MenuItemAbstract
//Motivação:
//    Fornecer um classe básica para criação de itens de menus em texto

class UIItemText : public UIItemAbstract
{

    protected:
        std::string text;

        std::string font;

        GBF::Kernel::Timer::CronometroCrescente time;

        static GBF::Kernel::Write::WriteManager * writeManager;


    public:
        UIItemText(const std::string & text, const std::string & font);

        virtual ~UIItemText();

        virtual void draw(int x, int y);

        virtual int getQuantidadeLetras();

        virtual GBF::Dimensao getDimensaoLetra();

};

} // namespace UserInterface::Menu

} // namespace UserInterface

#endif
