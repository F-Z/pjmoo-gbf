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

#ifndef _FPSFACTORY_H
#define _FPSFACTORY_H

#include "FPS.h"

namespace GBF { namespace Kernel { namespace FPS { class FPSContador; }  }  }
namespace GBF { namespace Kernel { namespace FPS { class FPSLimitado; }  }  }

namespace GBF {

namespace Kernel {

namespace FPS {

enum Tipo {
  //Frame não limitado, exibe apenas o contador em seu máximo processamento
  FPS_CONTADOR = 0,
  //Limitado a 30 frames por segundo
  FPS_LIMITADO = 33,
  //Limitado a 40 frames por segundo
  FPS_LIMITADO_40 = 25,
  //Limitado a 50 frames por segundo
  FPS_LIMITADO_50 = 20,
  //Limitado a aproximadamente 60 frames por segundo
  FPS_LIMITADO_60 = 16
};
class FPSFactory
{
  public:
    static FPS * criar(Tipo  tipo);

};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
#endif
