/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _TIMERREGRESSIVE_H
#define _TIMERREGRESSIVE_H

#include "TimerAbstract.h"

namespace GBF {

namespace Kernel {

namespace Timer {

/** Classe para marcação de tempo decrecente
 Motivação: Fornecer uma marcação de tempo decrescente */

class TimerRegressive : public TimerAbstract {

    public:
        /** Construtor */
        TimerRegressive();

        /** Destrutor */
        virtual ~TimerRegressive();

    protected:
        /** Executa este método quando o estado é CRONOMETRO_EXECUTAR */
        void execute();
};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF

#endif
