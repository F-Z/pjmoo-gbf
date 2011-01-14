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
#ifndef _GTMENU_H
#define _GTMENU_H

#include "GTTime.h"

namespace GAT {

enum StateMenu
{
    MENU_START  =  0,
    MENU_MAIN   = 10,
    MENU_HELP   = 20,
    MENU_CREDIT = 30,
    MENU_ABOUT  = 40,
    MENU_CONFIG = 50
};

class GTMenu : public GTTime
{
    public:
        /** Construtor */
        GTMenu();

        /** Destrutor */
        virtual ~GTMenu();

        StateMenu processarEstadoMenu();


    protected:

        void setMenuStart();

        void setMenuMain();

        void setMenuHelp();

        void setMenuCredit();

        void setMenuAbout();

        void setMenuConfig();

        virtual void screenMain() = 0;

        virtual void screenHelp() = 0;

        virtual void screenCredit() = 0;

        virtual void screenAbout() = 0;

        virtual void screenConfig();

        virtual void triggerMain();

        virtual void triggerConfig();

    private:
        StateMenu state;

};

} // namespace GAT
#endif
