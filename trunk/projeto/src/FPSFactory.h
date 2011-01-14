/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _FPSFACTORY_H
#define _FPSFACTORY_H

#include "FPS.h"
#include "FPSCounter.h"
#include "FPSFixRate.h"

namespace GBF
{

namespace Kernel {

namespace FPS {

enum FPSType {
    //Frame n�o limitado, exibe apenas o contador em seu m�ximo processamento
    FPS_COUNTER = 0,
    //Limitado a 30 frames por segundo
    FPS_30 = 33,
    //Limitado a 40 frames por segundo
    FPS_40 = 25,
    //Limitado a 50 frames por segundo
    FPS_50 = 20,
    //Limitado a aproximadamente 60 frames por segundo
    FPS_60 = 16
};

class FPSFactory
{
    public:
        static FPS * create(FPSType type);
};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF

#endif
