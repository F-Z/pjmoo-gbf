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
#ifndef _TIMERPROGRESSIVE_H
#define _TIMERPROGRESSIVE_H

#include "Timer.h"

namespace GBF {

namespace Kernel {

namespace Timer {

/**
 * Classe para contagem do tempo (Contador Crescente).
 */
class TimerProgressive : public Timer
{

    public:
        /** Construtor */
        TimerProgressive();

        /** Destrutor */
        virtual ~TimerProgressive();

    protected:
        /** Executa este método quando o estado é TIMER_EXECUTE */
        void execute();
};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF

#endif
