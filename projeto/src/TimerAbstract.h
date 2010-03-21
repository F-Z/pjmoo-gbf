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

/** Valores para marca��o da passagem do tempo
 Motiva��o: Fornecer um conjunto de valores para medi��o da passagem de tempo */

enum TimeUnit {
    /** Tempo de um segundo */
    TIME_SECOND_ONE  = 1000,
    /** Tempo de meio segundo */
    TIME_SECOND_HALF = 500,
    /** Tempo de um d�cimo de segundo */
    TIME_SECOND_0100 = 100
};

/** Valores para  indica��o de estado
Motiva��o: Fornecer um conjunto de valores para defini��o da m�quina de estados dos cronometros */
enum TimerState {
    /** Restaura tempo original e passa para o estado de iniciar */
    TIMER_RESET,
    /** Inicio do cronometro */
    TIMER_START,
    /** Pausa cronometro */
    TIMER_PAUSE,
    /** continua contagem do cronometro */
    TIMER_CONTINUE,
    /** Cronometro em execu��o */
    TIMER_EXECUTE,
    /** Cronometro finalizado */
    TIMER_FINISH
};
/** Classe abstrata para cria��o de cronometros
Motiva��o:  Fornecer um conjunto de m�todos padr�es para controle de tempo */

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

        /** Informa se o tempo j� terminou */
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

        /** Executa este m�todo quando o estado � CRONOMETRO_EXECUTAR */
        virtual void execute() = 0;

        /** Executa este m�todo quando o estado � CRONOMETRO_RESETAR */
        virtual void reset();

        /** Executa este m�todo quando o estado � CRONOMETRO_INICIAR */
        virtual void start();

        /** Executa este m�todo quando o estado � CRONOMETRO_CONTINUAR */
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
