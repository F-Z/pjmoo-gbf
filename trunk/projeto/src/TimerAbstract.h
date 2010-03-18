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

#ifndef _TIMERABSTRACT_H
#define _TIMERABSTRACT_H

#include <SDL/SDL.h>

#include "Object.h"

namespace GBF {

namespace Kernel {

namespace Timer {

//Descrição:
//    Valores para marcação da passagem do tempo
//Motivação:
//    Fornecer um conjunto de valores para medição da passagem de tempo
//

enum Tempo {
    //Tempo de um segundo
    TEMPO_SEGUNDO = 1000,
    //Tempo de meio segundo
    TEMPO_MEIO = 500,
    //Tempo de um décimo de segundo
    TEMPO_DECIMO = 100

};
//Descrição:
//    Valores para  indicação de estado
//Motivação:
//    Fornecer um conjunto de valores para definição da máquina de estados dos cronometros
enum TimerState {
    //Restaura tempo original e passa para o estado de iniciar
    CRONOMETRO_RESETAR,
    //Inicio do cronometro
    CRONOMETRO_INICIAR,
    //Pausa cronometro
    CRONOMETRO_PAUSAR,
    //continua contagem do cronometro
    CRONOMETRO_CONTINUAR,
    //Cronometro em execução
    CRONOMETRO_EXECUTAR,
    //Cronometro finalizado

    CRONOMETRO_TERMINAR
};
//Descrição:
//    Classe abstrata para criação de cronometros
//Motivação:
//    Fornecer um conjunto de métodos padrões para controle de tempo

class TimerAbstract : public GBF::Object {

    protected:
        Uint32 tempoUnidade;

        Uint32 tempoInicial;

        Uint32 tempoAtual;

        int tempoCorrente;

        int tempoOriginal;

        TimerState eCronometro;

        //Executa este método quando o estado é CRONOMETRO_EXECUTAR
        virtual void executar() = 0;

        //Executa este método quando o estado é CRONOMETRO_RESETAR
        virtual void resetar();

        //Executa este método quando o estado é CRONOMETRO_INICIAR
        virtual void iniciar();

        //Executa este método quando o estado é CRONOMETRO_CONTINUAR
        virtual void continuar();

        //Inicia o contado de tempo
        void execTempoInicial();

        //Muda o estado para CRONOMETRO_EXECUTAR
        void setExecutar();

        //Muda o estado para CRONOMETRO_TERMINAR
        void setTerminar();


    public:
        //Construtor
        TimerAbstract();

        //Destrutor
        virtual ~TimerAbstract();

        //Configura a unidade de tempo a ser usada
        void setUnidade(Tempo eTempo);

        //Muda o estado para CRONOMETRO_RESETAR
        void setResetar();


    protected:
        //Muda o estado para CRONOMETRO_INICIAR
        void setIniciar();


    public:
        //Muda o estado para CRONOMETRO_PAUSAR
        void setPausar();

        //Muda o estado para CRONOMETRO_CONTINUAR
        void setContinuar();

        //Centro de processamento de estados
        void processar();

        //Retorna a contagem de tempo corrente
        int getTempo();

        //Adiciona o marcador de tempo inicial
        void setTempoOriginal(int tempo);

        //Informa se o tempo já terminou
        bool isTerminou();

};

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF

#endif
