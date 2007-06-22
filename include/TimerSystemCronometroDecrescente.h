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

#ifndef _TIMERSYSTEMCRONOMETRODECRESCENTE_H
#define _TIMERSYSTEMCRONOMETRODECRESCENTE_H

#include "TimerSystemCronometroAbstract.h"

//Descri��o: 
//    Classe para marca��o de tempo decrecente
//Motiva��o:
//    Fornecer uma marca��o de tempo decrescente
class TimerSystemCronometroDecrescente : public TimerSystemCronometroAbstract {
  protected:
    //Executa este m�todo quando o estado � CRONOMETRO_EXECUTAR
    void executar();


  public:
    //Construtor
    TimerSystemCronometroDecrescente();

    //Destrutor
    virtual ~TimerSystemCronometroDecrescente();

};
#endif
