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
#ifndef _UIITEMABSTRACT_H
#define _UIITEMABSTRACT_H

#include "GBF.h"

namespace UserInterface {

namespace Menu {

//Descrição:
//    Classe para criação de itens de menus
//Motivação:
//    Fornecer uma interface padrão para criação de itens de menus

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
