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
#include "GTState.h"

namespace GAT {

/** Construtor */
GTState::GTState()
{
    setStateStart();
}

/** Destrutor */
GTState::~GTState()
{
}

State GTState::processarEstadoGeral()
{
    return estado;
}

bool GTState::setMenu()
{
    bool mudou = false;

    if ((estado == STATE_INTRODUCTION) || (estado == STATE_GAME) || (estado == STATE_SCORE)){
        if (triggerMenu()){
            estado = STATE_MENU;
            mudou = true;
            reset();
        }
    }

    return mudou;
}

void GTState::setIntroduction()
{
    if ((estado == STATE_MENU) || (estado == STATE_START)){
        if (triggerIntroduction()){
            estado = STATE_INTRODUCTION;
        }
    }
}

bool GTState::setGame()
{
    bool mudou = false;

    if ((estado != STATE_GAME) && (estado == STATE_MENU)){
        if (triggerGame()){
            estado = STATE_GAME;
            mudou = true;
        }
    }

    return mudou;
}

bool GTState::setScore()
{
    bool mudou = false;

    if ((estado != STATE_SCORE) && (isFinish())){
        if (triggerScore()){
            estado = STATE_SCORE;
            mudou = true;
            reset();
        }
    }

    return mudou;
}

void GTState::setQuit()
{
    if (estado != STATE_QUIT){
        if (triggerQuit()){
            estado = STATE_QUIT;
        }
    }
}

bool GTState::triggerMenu()
{
    return true;
}

bool GTState::triggerIntroduction()
{
    return true;
}

bool GTState::triggerGame()
{
    return true;
}

bool GTState::triggerScore()
{
    return true;
}

bool GTState::triggerQuit()
{
    return true;
}

void GTState::setStateStart()
{
    estado = STATE_START;
}

} // namespace GAT
