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

#ifndef _TIMERSYSTEMFPS_H
#define _TIMERSYSTEMFPS_H

#include "UtilLog.h"
#include "GBF_define.h"

//Descrição: 
//    Classe para controle da quantidade de quadros por segundo
//Motivação:
//    Fornecer um mecanismo para controlar a  velocidade de processamento da aplicação
class TimerSystemFPS {
  public:
    //Construtor
    TimerSystemFPS();

    //Destrutor
    virtual ~TimerSystemFPS();

    void processar();

    //Deve ser chamado antes do loop principal do jogo
    void start();

    //Aumenta a frequencia do FPS
    void aumentar();

    //Diminui a frequencia do FPS
    void diminuir();


  protected:
    Uint32 getDelay();


  private:
    double framestart;

    int fpsMax;

};
#endif
