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

namespace GBF { namespace Kernel { namespace Timer { class FPSContador; }  }  } 
namespace GBF { namespace Kernel { namespace Timer { class FPSLimitado; }  }  } 

namespace GBF {

namespace Kernel {

namespace Timer {

enum FPSTipo {
  FPS_CONTADOR = 4,
  FPS_LIMITADO = 0
};
class FPSFactory
{
  public:
    static FPS * criar(FPSTipo  tipo);

};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
#endif
