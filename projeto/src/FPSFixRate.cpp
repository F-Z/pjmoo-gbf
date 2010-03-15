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

#include "FPSFixRate.h"

namespace GBF {

namespace Kernel {

namespace FPS {

FPSFixRate::FPSFixRate(int frameRate) {
    std::cout << "GBF::Kernel::FPS::FPSFixRate" << std::endl;

    if (frameRate < 30) {
        fixRate = 30;
    }
    else {
        fixRate = frameRate;
    }

    std::cout << "\tFPS: " << (float) fixRate << " fps" << std::endl;

    iniciar();
}

FPSFixRate::~FPSFixRate() {

}

void FPSFixRate::processar() {
    int delta = SDL_GetTicks() - time;

    if (delta < fixRate) {
        SDL_Delay(fixRate - delta);
    }

    time = SDL_GetTicks();
}

//Deve ser chamado antes do loop principal do jogo
void FPSFixRate::iniciar() {
    std::cout << "\tSDL: ";
    time = SDL_GetTicks();
    std::cout << (int) time << " ticks" << std::endl;
}

int FPSFixRate::getValor() {
    return fixRate;
}

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
