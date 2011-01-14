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
#ifndef _TIMER_H
#define _TIMER_H

#include <SDL/SDL.h>

#include "Object.h"

namespace GBF {

namespace Kernel {

/** Namespace para cronometros (timers) */
namespace Timer {

/**
 *  Enumera��o para marca��o da passagem do tempo.
 *  Fornecer um conjunto de valores para medi��o da passagem de tempo.
 */
enum TimeUnit
{
    /** Tempo de um segundo */
    TIME_SECOND_ONE  = 1000,
    /** Tempo de meio segundo */
    TIME_SECOND_HALF = 500,
    /** Tempo de um d�cimo de segundo */
    TIME_SECOND_0100 = 100
};

/**
 * Enumera��o para indica��o de estado do tempo.
 * Fornecer um conjunto de valores para defini��o da m�quina de estados dos cronometros.
 */
enum TimerState
{
    /** Restaura tempo original e passa para o estado de iniciar */
    TIMER_RESET,
    /** Inicio do cronometro */
    TIMER_START,
    /** Pausa cronometro */
    TIMER_PAUSE,
    /** continua contagem do cronometro */
    TIMER_RESUME,
    /** Cronometro em execu��o */
    TIMER_EXECUTE,
    /** Cronometro finalizado */
    TIMER_FINISH
};

/**
 * Classe abstrata para cria��o de cronometros.
 * Fornecer um conjunto de m�todos padr�es para controle de tempo.
 */
class Timer : public GBF::Object
{
    public:
        /** Muda o estado para CRONOMETRO_PAUSAR */
        void setPause();

        /** Muda o estado para CRONOMETRO_CONTINUAR */
        void setResume();

        /** Centro de processamento de estados */
        void update();

        /** Retorna a contagem de tempo corrente */
        int getTime();

        /** Adiciona o marcador de tempo inicial */
        void setInitialTime(int time);

        /** Informa se o tempo j� terminou */
        bool isFinish();

        /** Construtor */
        Timer();

        /** Destrutor */
        virtual ~Timer();

        /** Configura a unidade de tempo a ser usada */
        void setUnit(TimeUnit unit);

        /** Muda o estado para CRONOMETRO_RESETAR */
        void setReset();

    protected:
        Uint32 tempoUnidade;

        Uint32 tempoInicial;

        Uint32 tempoAtual;

        int tempoCorrente;

        int tempoOriginal;

        TimerState state;

        /** Executa este m�todo quando o estado � TIMER_EXECUTE */
        virtual void execute() = 0;

        /** Executa este m�todo quando o estado � TIMER_RESET */
        virtual void reset();

        /** Executa este m�todo quando o estado � TIMER_START */
        virtual void start();

        /** Executa este m�todo quando o estado � TIMER_RESUME */
        virtual void resume();

        /** Muda o estado para TIMER_EXECUTE */
        void setExecute();

        /** Muda o estado para TIMER_FINISH */
        void setFinish();

        /** Muda o estado para TIMER_START */
        void setStart();

        /** Inicia o contado de tempo */
        void initialTick();
};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF

#endif
