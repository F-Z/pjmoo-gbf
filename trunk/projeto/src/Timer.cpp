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
#include "Timer.h"

namespace GBF {

namespace Kernel {

namespace Timer {

/** Executa este m�todo quando o estado � TIMER_RESET */
void Timer::reset()
{
    tempoCorrente = tempoOriginal;
    setStart();
}

/** Executa este m�todo quando o estado � TIMER_START */
void Timer::start()
{
    setExecute();
    initialTick();
}

/** Executa este m�todo quando o estado � TIMER_RESUME */
void Timer::resume()
{
    setExecute();
    initialTick();
}

/** Inicia o contado de tempo */
void Timer::initialTick()
{
    tempoInicial = SDL_GetTicks();
}

/** Muda o estado para TIMER_EXECUTE */
void Timer::setExecute()
{
    if ((state == TIMER_START) || (state == TIMER_RESUME)){
        state = TIMER_EXECUTE;
    }
}

/** Muda o estado para TIMER_FINISH */
void Timer::setFinish()
{
    if (state == TIMER_EXECUTE){
        state = TIMER_FINISH;
    }
}

/** Construtor */
Timer::Timer()
{
    tempoInicial  = 0;
    tempoAtual    = 0;
    tempoCorrente = 0;
    tempoOriginal = 0;
    setUnit(TIME_SECOND_ONE);
    state = TIMER_RESET;
}

/** Destrutor */
Timer::~Timer()
{
}

/** Configura a unidade de tempo a ser usada */
void Timer::setUnit(TimeUnit unit)
{
    tempoUnidade = int(unit);
}

/** Muda o estado para TIMER_RESET */
void Timer::setReset()
{
    if ((state == TIMER_EXECUTE) || (state == TIMER_FINISH)){
        state = TIMER_RESET;
    }
}

/** Muda o estado para TIMER_START */
void Timer::setStart()
{
    if (state == TIMER_RESET){
        state = TIMER_START;
    }
}

/** Muda o estado para TIMER_PAUSE */
void Timer::setPause()
{
    if (state == TIMER_EXECUTE){
        state = TIMER_PAUSE;
    }
}

/** Muda o estado para TIMER_RESUME */
void Timer::setResume()
{
    if (state == TIMER_PAUSE){
        state = TIMER_RESUME;
    }
}

/** Centro de processamento de estados */
void Timer::update()
{
    switch (state){

        case TIMER_EXECUTE:
            execute();
            break;

        case TIMER_RESUME:
            resume();
            break;

        case TIMER_START:
            start();
            break;

        case TIMER_PAUSE:
            //sem implementacao
            break;

        case TIMER_FINISH:
            //sem implementacao
            break;

        case TIMER_RESET:

        default:
            reset();
            break;
    }
}

/** Retorna a contagem de tempo corrente */
int Timer::getTime()
{
    return tempoCorrente;
}

/** Adiciona o marcador de tempo inicial */
void Timer::setInitialTime(int time)
{
    tempoOriginal = time;
}

/** Informa se o tempo j� terminou */
bool Timer::isFinish()
{
    if (state == TIMER_FINISH){
        return true;
    } else {
        return false;
    }
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
