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

#ifndef _TIMERSYSTEMCRONOMETROCRESCENTE_H
#define _TIMERSYSTEMCRONOMETROCRESCENTE_H

#include "TimerSystemCronometroAbstract.h"

//Descrição: 
//    Classe para marcação de tempo crescente
//Motivação:
//    Fornecer uma marcação de tempo crescente
class TimerSystemCronometroCrescente : public TimerSystemCronometroAbstract {
  protected:
    //Executa este método quando o estado é CRONOMETRO_EXECUTAR
    void executar();


  public:
    //Construtor
    TimerSystemCronometroCrescente();

    //Destrutor
    virtual ~TimerSystemCronometroCrescente();

};
#endif
