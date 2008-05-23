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

#include "FPSLimitado.h"

namespace GBF {

namespace Kernel {

namespace Timer {

FPSLimitado::FPSLimitado()
{
    fpsMax = 30;
    framestart = 0.0f;
}
FPSLimitado::~FPSLimitado()
{
}
void FPSLimitado::processar()
{

    while( (SDL_GetTicks() - framestart) < 1000 / fpsMax )
    {
        //wait...
        //se tempo atual menos o tempo inicial for menor que
        // 1000/30, faz com que entre em espera
        //até que se complete o tempo
    }

    framestart = SDL_GetTicks();
}
//Deve ser chamado antes do loop principal do jogo
void FPSLimitado::iniciar()
{
//    UtilLog::tracer("Inicializando FPS");
    framestart = SDL_GetTicks();
}
//Aumenta a frequencia do FPS
void FPSLimitado::aumentar()
{
    fpsMax++;
}
//Diminui a frequencia do FPS
void FPSLimitado::diminuir()
{
    fpsMax--;
    if (fpsMax<=30){
        fpsMax=30;
    }
}
int FPSLimitado::getValor()
{
    return fpsMax;
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
