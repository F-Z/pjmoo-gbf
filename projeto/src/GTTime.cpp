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
#include "GTTime.h"

namespace GAT {

GBF::Kernel::Timer::TimerRegressive GTTime::tempoEspera;

//Construtor
GTTime::GTTime()
{
    tempoEspera.setInitialTime(1);
    tempoEspera.setUnit(GBF::Kernel::Timer::TIME_SECOND_HALF);
    tempoEspera.setReset();
}
//Destrutor
GTTime::~GTTime()
{
}
bool GTTime::isTempoEspera()
{
    return tempoEspera.isFinish();
}
void GTTime::reiniciarTempo()
{
    tempoEspera.setReset();
}
void GTTime::executarTempo()
{
    tempoEspera.update();
}

} // namespace GAT
