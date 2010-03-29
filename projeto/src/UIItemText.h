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
#ifndef _UIITEMTEXT_H
#define _UIITEMTEXT_H

#include <string>

#include "TimerProgressive.h"
#include "WriteManager.h"
#include "GBF.h"
#include "UIItemAbstract.h"

namespace UserInterface {

namespace Menu {

/**
 * Implementação da Classe MenuItemAbstract.
 * Fornecer um classe básica para criação de itens de menus em texto.
 */
class UIItemText : public UIItemAbstract
{
    public:
        /** Construtor */
        UIItemText(const std::string & text, const std::string & font);
        /** Destrutor */
        virtual ~UIItemText();

        virtual void draw(int x, int y);

        virtual int getQuantidadeLetras();

        virtual GBF::Dimension getDimensaoLetra();


    protected:
        std::string text;

        std::string font;

        GBF::Kernel::Timer::TimerProgressive time;

        static GBF::Kernel::Write::WriteManager * writeManager;
};

} // namespace UserInterface::Menu

} // namespace UserInterface

#endif
