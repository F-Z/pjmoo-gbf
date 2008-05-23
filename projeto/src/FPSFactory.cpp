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

#include "FPSFactory.h"
#include "FPSContador.h"
#include "FPSLimitado.h"

namespace GBF {

namespace Kernel {

namespace Timer {

FPS * FPSFactory::criar(FPSTipo  tipo)

{
    FPS * fps = NULL;

    switch(tipo){
        case FPS_CONTADOR:
            fps = new FPSContador();
        break;
        default:
            fps = new FPSLimitado();
    }

    return fps;
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
