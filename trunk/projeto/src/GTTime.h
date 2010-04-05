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
#ifndef _GTTIME_H
#define _GTTIME_H

#include "TimerRegressive.h"

namespace GAT {

class GTTime
{
    public:

        /** Construtor */
        GTTime();

        /** Destrutor */
        virtual ~GTTime();


    protected:
        /** Informa se o tempo já terminou. */
        static bool isFinish();

        /** Reseta a contagem do tempo. */
        static void reset();

        /** Atualiza o processamento do tempo. */
        static void update();

    private:

        static GBF::Kernel::Timer::TimerRegressive time;

};

} // namespace GAT

#endif
