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

#ifndef _UIITEMABSTRACT_H
#define _UIITEMABSTRACT_H

#include "GBF.h"

namespace UserInterface {

namespace Menu {

//Descri��o:
//    Classe para cria��o de itens de menus
//Motiva��o:
//    Fornecer uma interface padr�o para cria��o de itens de menus

class UIItemAbstract
{

    private:
        bool active;


    public:
        UIItemAbstract();

        virtual ~UIItemAbstract();

        virtual void draw(int x, int y) = 0;

        void setActive(bool active);

        virtual int getQuantidadeLetras() = 0;

        virtual GBF::Dimension getDimensaoLetra() = 0;


    protected:
        bool isActive();

};

} // namespace UserInterface::Menu

} // namespace UserInterface

#endif
