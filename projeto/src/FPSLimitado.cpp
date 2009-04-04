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
    std::cout << "GBF::Kernel::FPS::FPSLimitado" << std::endl;

    if (taxaFrames<30){
        fpsConstante = 30;
    } else {
        fpsConstante = taxaFrames;
    }

    std::cout << "\tFPS: " << (float) fpsConstante << " fps" << std::endl;
    iniciar();
}
FPSLimitado::~FPSLimitado()
{

}
void FPSLimitado::processar()
{
    int delta = SDL_GetTicks() - frameStart;

    if(delta < fpsConstante){
        SDL_Delay(fpsConstante - delta);
    }

    frameStart = SDL_GetTicks();
}
//Deve ser chamado antes do loop principal do jogo
void FPSLimitado::iniciar()
{
    std::cout << "\tSDL: ";
    frameStart = SDL_GetTicks();
    std::cout << (int) frameStart << " ticks" << std::endl;
}
int FPSLimitado::getValor()
{
    return fpsConstante;
}

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
