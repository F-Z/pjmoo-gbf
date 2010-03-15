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
#include "FPSCounter.h"
#include "FPSFixRate.h"

namespace GBF {

namespace Kernel {

namespace FPS {

FPS * FPSFactory::criar(Tipo  tipo)

{
    FPS * fps = NULL;

    switch (tipo) {

        case FPS_CONTADOR:
            fps = new FPSCounter();
            break;

        default:
            fps = new FPSFixRate(tipo);
    }

    return fps;
}

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
