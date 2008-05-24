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

namespace FPS {

FPSLimitado::FPSLimitado(int taxaFrames) 
{
    framestart = 0.0f;

    if (taxaFrames<30){
        fpsConstante = 30;
    } else {
        fpsConstante = taxaFrames;
    }
}
FPSLimitado::~FPSLimitado() 
{
}
void FPSLimitado::processar() 
{

    while( (SDL_GetTicks() - framestart) < 1000 / fpsConstante )
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
int FPSLimitado::getValor() 
{
    return fpsConstante;
}

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
