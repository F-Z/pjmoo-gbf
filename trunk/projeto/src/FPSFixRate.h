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
#ifndef _FPSFIXRATE_H
#define _FPSFIXRATE_H

#include "FPS.h"

namespace GBF {

namespace Kernel {

namespace FPS {

class FPSFixRate : public FPS {

    private:
        int fixRate;

        int time;

        FPSFixRate(int frameRate);

    public:
        virtual ~FPSFixRate();

        void update();

        //Deve ser chamado antes do loop principal do jogo
        void start();

        int getValue();

        friend class FPSFactory;
};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF

#endif
