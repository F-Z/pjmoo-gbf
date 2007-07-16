////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
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

//Construtor
TimerSystemFPS::TimerSystemFPS()
{
    UtilLog::sistema("Instanciando FPS");
    framestart =0.0f;
    fpsMax     =30;
}
//Destrutor
TimerSystemFPS::~TimerSystemFPS()
{
    UtilLog::sistema("Removendo FPS[%i]",fpsMax);
}
void TimerSystemFPS::processar()
{
//    SDL_Delay(getDelay());
//    framestart += fpsMax;
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
void TimerSystemFPS::start()
{
    UtilLog::tracer("Inicializando FPS");
    //framestart = SDL_GetTicks() + fpsMax;
    framestart = SDL_GetTicks();
}
//Aumenta a frequencia do FPS
void TimerSystemFPS::aumentar()
{
    fpsMax++;
}
//Diminui a frequencia do FPS
void TimerSystemFPS::diminuir()
{
    fpsMax--;
    if (fpsMax<=30){
        fpsMax=30;
    }
}
Uint32 TimerSystemFPS::getDelay()
{
    Uint32 now = SDL_GetTicks();

    if (framestart <= now){
        return 0;
    } else {
        return Uint32(framestart - now);
    }
}
