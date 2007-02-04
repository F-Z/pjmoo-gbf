////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "GATMaquinaEstado.h"

TimerSystemCronometroDecrescente GATMaquinaEstado::tempoEspera;

GATMaquinaEstado::GATMaquinaEstado() 
{
    tempoEspera.setTempoOriginal(1);
    tempoEspera.setUnidade(TEMPO_MEIO);
    tempoEspera.setResetar();
}
GATMaquinaEstado::~GATMaquinaEstado() 
{
}
bool GATMaquinaEstado::isTempoEspera()
{
	return tempoEspera.isTerminou();
}
void GATMaquinaEstado::reiniciarTempo()
{
    tempoEspera.setResetar();
}
void GATMaquinaEstado::executarTempo()
{
    tempoEspera.processar();
}
