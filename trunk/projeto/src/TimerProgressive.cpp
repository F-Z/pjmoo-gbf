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
#include "TimerProgressive.h"

namespace GBF {

namespace Kernel {

namespace Timer {


/** Construtor */
TimerProgressive::TimerProgressive()
{
}

/** Destrutor */
TimerProgressive::~TimerProgressive()
{
}

/** Executa este método quando o estado é TIMER_EXECUTE */
void TimerProgressive::execute()
{
    tempoAtual = SDL_GetTicks();

    if (tempoAtual - tempoInicial >= tempoUnidade){
        tempoCorrente++;
        initialTick();
    }
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
