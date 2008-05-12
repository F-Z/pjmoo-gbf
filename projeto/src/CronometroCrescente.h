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

#ifndef _CRONOMETROCRESCENTE_H
#define _CRONOMETROCRESCENTE_H

#include "CronometroAbstract.h"

namespace GBF {

namespace Kernel {

namespace Timer {

//Descrição: 
//    Classe para marcação de tempo crescente
//Motivação:
//    Fornecer uma marcação de tempo crescente
class CronometroCrescente : public CronometroAbstract {
  protected:
    //Executa este método quando o estado é CRONOMETRO_EXECUTAR
    void executar();


  public:
    //Construtor
    CronometroCrescente();

    //Destrutor
    virtual ~CronometroCrescente();

};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
#endif
