////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
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

#ifndef _GATMAQUINAESTADO_H
#define _GATMAQUINAESTADO_H

#include "TimerSystemCronometroDecrescente.h"

class GATMaquinaEstado
{
  private:
    static TimerSystemCronometroDecrescente tempoEspera;


  public:
    //Construtor
    GATMaquinaEstado();

    //Destrutor
    virtual ~GATMaquinaEstado();


  protected:
    static bool isTempoEspera();

    static void reiniciarTempo();

    static void executarTempo();


};
#endif
