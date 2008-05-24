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

namespace FPS {

class FPSLimitado : public FPS
{
  private:
    int fpsConstante;

    double framestart;

    FPSLimitado(int taxaFrames);


  public:
    virtual ~FPSLimitado();

    void processar();

    //Deve ser chamado antes do loop principal do jogo
    void iniciar();

    int getValor();

  friend class FPSFactory;
};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
#endif
