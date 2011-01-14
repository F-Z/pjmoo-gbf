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
#include "TimerRegressive.h"

namespace GBF {

namespace Kernel {

namespace Timer {


/** Construtor */
TimerRegressive::TimerRegressive()
{
}

/** Destrutor */
TimerRegressive::~TimerRegressive()
{
}

/** Executa este método quando o estado é TIMER_EXECUTE */
void TimerRegressive::execute()
{
    tempoAtual = SDL_GetTicks();

    if (tempoAtual - tempoInicial >= tempoUnidade){
        tempoCorrente--;

        if (tempoCorrente <= 0){
            tempoCorrente = 0;
            setFinish();
        }

        initialTick();
    }
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
