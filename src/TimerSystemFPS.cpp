////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "TimerSystemFPS.h"

TimerSystemFPS::TimerSystemFPS(){

    UtilLog::sistema("Instanciando FPS");
	framestart =0.0f;
	fpsMax     =30;
}

TimerSystemFPS::~TimerSystemFPS(){

    UtilLog::sistema("Removendo FPS[%i]",fpsMax);
}

void TimerSystemFPS::processar() {

	SDL_Delay(getDelay());
	framestart += fpsMax;
}

// Deve ser chamado antes do loop do jogo 

void TimerSystemFPS::start() {

    UtilLog::tracer("Inicializando FPS");
	framestart = SDL_GetTicks() + fpsMax;
}

//* Aumenta a frequencia do FPS
void TimerSystemFPS::aumentar() {

    fpsMax++;
}

//* Diminui a frequencia do FPS
void TimerSystemFPS::diminuir() {

    fpsMax--;
    if (fpsMax<=30){
        fpsMax=30;
    }
}

Uint32 TimerSystemFPS::getDelay() {

	Uint32 now = SDL_GetTicks();
	if (framestart <= now){
	    return 0;
	} else {
	    return Uint32(framestart - now);
	}
}

