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
#ifndef _FPSCOUNTER_H
#define _FPSCOUNTER_H

#include "FPS.h"

namespace GBF {

namespace Kernel {

namespace FPS {

#define FRAME_VALUES 10
//Descrição:
//    Classe para controle da quantidade de quadros por segundo
//Motivação:
//    Fornecer um mecanismo para controlar a  velocidade de processamento da aplicação

class FPSCounter : public FPS {

    private:
        //Construtor
        FPSCounter();


    public:
        //Destrutor
        virtual ~FPSCounter();

        void update();

        //Deve ser chamado antes do loop principal do jogo
        void start();

        int getValue();


    private:
        Uint32 frametimelast;

        Uint32 frametimes[FRAME_VALUES];

        Uint32 framecount;

        float framespersecond;

        friend class FPSFactory;
};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF

#endif
