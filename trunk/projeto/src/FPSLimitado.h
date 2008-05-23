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

#ifndef _FPSLIMITADO_H
#define _FPSLIMITADO_H

#include "FPS.h"

namespace GBF {

namespace Kernel {

namespace Timer {

class FPSLimitado : public FPS
{
  private:
    int fpsMax;

    double framestart;


  public:
    FPSLimitado();

    virtual ~FPSLimitado();

    void processar();

    //Deve ser chamado antes do loop principal do jogo
    void iniciar();

    //Aumenta a frequencia do FPS
    void aumentar();

    //Diminui a frequencia do FPS
    void diminuir();

    int getValor();

};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
#endif
