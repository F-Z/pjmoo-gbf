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

#include "FPSCounter.h"

namespace GBF {

namespace Kernel {

namespace FPS {

//Construtor

//Construtor
FPSCounter::FPSCounter() {
    std::cout << "GBF::Kernel::FPS::FPSCounter" << std::endl;
}

//Destrutor

//Destrutor
FPSCounter::~FPSCounter() {
//    UtilLog::sistema("Removendo FPS[%i]",fpsMax);
}

void FPSCounter::update() {

    Uint32 frametimesindex;
    Uint32 getticks;
    Uint32 count;
    Uint32 i;

    // frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
    // This value rotates back to 0 after it hits FRAME_VALUES.
    frametimesindex = framecount % FRAME_VALUES;

    // store the current time
    getticks = SDL_GetTicks();

    // save the frame time value
    frametimes[frametimesindex] = getticks - frametimelast;

    // save the last frame time for the next fpsthink
    frametimelast = getticks;

    // increment the frame count
    framecount++;

    // Work out the current framerate

    // The code below could be moved into another function if you don't need the value every frame.

    // I've included a test to see if the whole array has been written to or not. This will stop
    // strange values on the first few (FRAME_VALUES) frames.

    if (framecount < FRAME_VALUES) {

        count = framecount;

    }
    else {

        count = FRAME_VALUES;

    }

    // add up all the values and divide to get the average frame time.
    framespersecond = 0;

    for (i = 0; i < count; i++) {

        framespersecond += frametimes[i];

    }

    framespersecond /= count;

    // now to make it an actual frames per second value...
    framespersecond = 1000.f / framespersecond;

}

//Deve ser chamado antes do loop principal do jogo

//Deve ser chamado antes do loop principal do jogo
void FPSCounter::start() {
    std::cout << "\tSDL: " << std::endl;

    // Set all frame times to 0ms.
    memset(frametimes, 0, sizeof(frametimes));
    framecount = 0;
    framespersecond = 0;
    frametimelast = SDL_GetTicks();

    std::cout << (double) frametimelast << " ticks" << std::endl;
}

int FPSCounter::getValue() {
    return framespersecond;
}

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
