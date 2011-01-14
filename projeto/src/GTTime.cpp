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
#include "GTTime.h"

namespace GAT {

GBF::Kernel::Timer::TimerRegressive GTTime::time;

/** Construtor */
GTTime::GTTime()
{
    time.setInitialTime(1);
    time.setUnit(GBF::Kernel::Timer::TIME_SECOND_HALF);
    time.setReset();
}

/** Destrutor */
GTTime::~GTTime()
{
}

/** Informa se o tempo já terminou. */
bool GTTime::isFinish()
{
    return time.isFinish();
}

/** Reseta a contagem do tempo. */
void GTTime::reset()
{
    time.setReset();
}

/** Atualiza o processamento do tempo. */
void GTTime::update()
{
    time.update();
}

} // namespace GAT
