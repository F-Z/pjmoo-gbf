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

#ifndef _TIMERABSTRACT_H
#define _TIMERABSTRACT_H

#include <SDL/SDL.h>

#include "Object.h"

namespace GBF {

namespace Kernel {

namespace Timer {

/** Valores para marcação da passagem do tempo
 Motivação: Fornecer um conjunto de valores para medição da passagem de tempo */

enum TimeUnit {
    /** Tempo de um segundo */
    TIME_SECOND_ONE  = 1000,
    /** Tempo de meio segundo */
    TIME_SECOND_HALF = 500,
    /** Tempo de um décimo de segundo */
    TIME_SECOND_0100 = 100
};

/** Valores para  indicação de estado
Motivação: Fornecer um conjunto de valores para definição da máquina de estados dos cronometros */
enum TimerState {
    /** Restaura tempo original e passa para o estado de iniciar */
    TIMER_RESET,
    /** Inicio do cronometro */
    TIMER_START,
    /** Pausa cronometro */
    TIMER_PAUSE,
    /** continua contagem do cronometro */
    TIMER_CONTINUE,
    /** Cronometro em execução */
    TIMER_EXECUTE,
    /** Cronometro finalizado */
    TIMER_FINISH
};
/** Classe abstrata para criação de cronometros
Motivação:  Fornecer um conjunto de métodos padrões para controle de tempo */

class TimerAbstract : public GBF::Object {

    public:
        /** Muda o estado para CRONOMETRO_PAUSAR */
        void setPause();

        /** Muda o estado para CRONOMETRO_CONTINUAR */
        void setContinuar();

        /** Centro de processamento de estados */
        void update();

        /** Retorna a contagem de tempo corrente */
        int getTime();

        /** Adiciona o marcador de tempo inicial */
        void setInitialTime(int time);

        /** Informa se o tempo já terminou */
        bool isFinish();

        /** Construtor */
        TimerAbstract();

        /** Destrutor */
        virtual ~TimerAbstract();

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

        /** Executa este método quando o estado é CRONOMETRO_EXECUTAR */
        virtual void execute() = 0;

        /** Executa este método quando o estado é CRONOMETRO_RESETAR */
        virtual void reset();

        /** Executa este método quando o estado é CRONOMETRO_INICIAR */
        virtual void start();

        /** Executa este método quando o estado é CRONOMETRO_CONTINUAR */
        virtual void continuar();

        /** Muda o estado para CRONOMETRO_EXECUTAR */
        void setExecute();

        /** Muda o estado para CRONOMETRO_TERMINAR */
        void setFinish();

        /** Muda o estado para CRONOMETRO_INICIAR */
        void setStart();

        /** Inicia o contado de tempo */
        void initialTick();
};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF

#endif
