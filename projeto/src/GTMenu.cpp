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
#include "GTMenu.h"

namespace GAT {

//Construtor
GTMenu::GTMenu()
{
    setMenuStart();
}

//Destrutor
GTMenu::~GTMenu()
{
}

StateMenu GTMenu::processarEstadoMenu()
{
    return state;
}

void GTMenu::setMenuMain()
{
    if ((state == MENU_START) || ((state != MENU_MAIN) && (isFinish()))){
        state = MENU_MAIN;
        triggerMain();
        reset();
    }
}

void GTMenu::setMenuHelp()
{
    if ((state != MENU_HELP) && (isFinish())){
        state = MENU_HELP;
        reset();
    }
}

void GTMenu::setMenuCredit()
{
    if ((state != MENU_CREDIT) && (isFinish())){
        state = MENU_CREDIT;
        reset();
    }
}

void GTMenu::setMenuAbout()
{
    if ((state != MENU_ABOUT) && (isFinish())){
        state = MENU_ABOUT;
        reset();
    }
}

void GTMenu::setMenuConfig()
{
    if ((state != MENU_CONFIG) && (isFinish())){
        state = MENU_CONFIG;
        triggerConfig();
        reset();
    }
}

void GTMenu::screenConfig()
{
    //opcional implementação de acordo com a necessidade
}

void GTMenu::triggerMain()
{
    //opcional implementação de acordo com a necessidade
}

void GTMenu::triggerConfig()
{
    //opcional implementação de acordo com a necessidade
}

void GTMenu::setMenuStart()
{
    state = MENU_START;
}

} // namespace GAT
