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

#include "TimerSystemCronometroAbstract.h"

//Executa este método quando o estado é CRONOMETRO_RESETAR
void TimerSystemCronometroAbstract::resetar() 
{
    tempoCorrente=tempoOriginal;
    setIniciar();
}
//Executa este método quando o estado é CRONOMETRO_INICIAR
void TimerSystemCronometroAbstract::iniciar() 
{
    //resetar();
    setExecutar();
    execTempoInicial();
}
//Executa este método quando o estado é CRONOMETRO_CONTINUAR
void TimerSystemCronometroAbstract::continuar() 
{
    setExecutar();
    execTempoInicial();
}
//Inicia o contado de tempo
void TimerSystemCronometroAbstract::execTempoInicial() 
{
    tempoInicial = SDL_GetTicks();
}
//Muda o estado para CRONOMETRO_EXECUTAR
void TimerSystemCronometroAbstract::setExecutar() 
{
    if ((eCronometro==CRONOMETRO_INICIAR)||(eCronometro==CRONOMETRO_CONTINUAR)){
        eCronometro=CRONOMETRO_EXECUTAR;
    }
}
//Muda o estado para CRONOMETRO_TERMINAR
void TimerSystemCronometroAbstract::setTerminar() 
{
    if (eCronometro==CRONOMETRO_EXECUTAR){
        eCronometro=CRONOMETRO_TERMINAR;
    }
}
//Construtor 
TimerSystemCronometroAbstract::TimerSystemCronometroAbstract() 
{
    tempoInicial  = 0;
    tempoAtual    = 0;
    tempoCorrente = 0;
    tempoOriginal = 0;
    setUnidade(TEMPO_SEGUNDO);
    eCronometro=CRONOMETRO_RESETAR;
}
//Destrutor 
TimerSystemCronometroAbstract::~TimerSystemCronometroAbstract() 
{

}
//Configura a unidade de tempo a ser usada
void TimerSystemCronometroAbstract::setUnidade(EnumTempo eTempo) 
{
    tempoUnidade = int(eTempo);
}
//Muda o estado para CRONOMETRO_RESETAR
void TimerSystemCronometroAbstract::setResetar() 
{
    if ((eCronometro==CRONOMETRO_EXECUTAR)||(eCronometro==CRONOMETRO_TERMINAR)){
        eCronometro=CRONOMETRO_RESETAR;
    }
}
//Muda o estado para CRONOMETRO_INICIAR
void TimerSystemCronometroAbstract::setIniciar() 
{
    if (eCronometro==CRONOMETRO_RESETAR){
        eCronometro=CRONOMETRO_INICIAR;
    }
}
//Muda o estado para CRONOMETRO_PAUSAR
void TimerSystemCronometroAbstract::setPausar() 
{
    if (eCronometro==CRONOMETRO_EXECUTAR){
        eCronometro=CRONOMETRO_PAUSAR;
    }
}
//Muda o estado para CRONOMETRO_CONTINUAR
void TimerSystemCronometroAbstract::setContinuar() 
{
    if (eCronometro==CRONOMETRO_PAUSAR){
        eCronometro=CRONOMETRO_CONTINUAR;
    }
}
//Centro de processamento de estados
void TimerSystemCronometroAbstract::processar() 
{
    switch(eCronometro){
        case CRONOMETRO_EXECUTAR:
                executar();
            break;
        case CRONOMETRO_CONTINUAR:
                continuar();
            break;
        case CRONOMETRO_INICIAR:
                iniciar();
            break;
        case CRONOMETRO_PAUSAR:
                //sem implementacao
            break;
        case CRONOMETRO_TERMINAR:
                //sem implementacao
            break;
        case CRONOMETRO_RESETAR:
        default:
                resetar();
            break;
    }
}
//Retorna a contagem de tempo corrente
int TimerSystemCronometroAbstract::getTempo() 
{
    return tempoCorrente;
}
//Adiciona o marcador de tempo inicial
void TimerSystemCronometroAbstract::setTempoOriginal(int tempo) 
{
    tempoOriginal=tempo;
}
//Informa se o tempo já terminou
bool TimerSystemCronometroAbstract::isTerminou() 
{
    if (eCronometro==CRONOMETRO_TERMINAR){
        return true;
    } else {
        return false;
    }
}
