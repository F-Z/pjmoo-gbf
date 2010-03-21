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

#include "GTMaquinaEstado.h"

namespace GAT {

GBF::Kernel::Timer::TimerRegressive GTMaquinaEstado::tempoEspera;

//Construtor
GTMaquinaEstado::GTMaquinaEstado()
{
    tempoEspera.setInitialTime(1);
    tempoEspera.setUnit(GBF::Kernel::Timer::TIME_SECOND_HALF);
    tempoEspera.setReset();
}
//Destrutor
GTMaquinaEstado::~GTMaquinaEstado()
{
}
bool GTMaquinaEstado::isTempoEspera()
{
	return tempoEspera.isFinish();
}
void GTMaquinaEstado::reiniciarTempo()
{
    tempoEspera.setReset();
}
void GTMaquinaEstado::executarTempo()
{
    tempoEspera.update();
}

} // namespace GAT
