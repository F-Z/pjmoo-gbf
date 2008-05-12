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

#include "CronometroAbstract.h"

namespace GBF {

namespace Kernel {

namespace Timer {

//Executa este método quando o estado é CRONOMETRO_RESETAR
void CronometroAbstract::resetar() 
{
    tempoCorrente=tempoOriginal;
    setIniciar();
}
//Executa este método quando o estado é CRONOMETRO_INICIAR
void CronometroAbstract::iniciar() 
{
    //resetar();
    setExecutar();
    execTempoInicial();
}
//Executa este método quando o estado é CRONOMETRO_CONTINUAR
void CronometroAbstract::continuar() 
{
    setExecutar();
    execTempoInicial();
}
//Inicia o contado de tempo
void CronometroAbstract::execTempoInicial() 
{
    tempoInicial = SDL_GetTicks();
}
//Muda o estado para CRONOMETRO_EXECUTAR
void CronometroAbstract::setExecutar() 
{
    if ((eCronometro==CRONOMETRO_INICIAR)||(eCronometro==CRONOMETRO_CONTINUAR)){
        eCronometro=CRONOMETRO_EXECUTAR;
    }
}
//Muda o estado para CRONOMETRO_TERMINAR
void CronometroAbstract::setTerminar() 
{
    if (eCronometro==CRONOMETRO_EXECUTAR){
        eCronometro=CRONOMETRO_TERMINAR;
    }
}
//Construtor 
CronometroAbstract::CronometroAbstract() 
{
    tempoInicial  = 0;
    tempoAtual    = 0;
    tempoCorrente = 0;
    tempoOriginal = 0;
    setUnidade(TEMPO_SEGUNDO);
    eCronometro=CRONOMETRO_RESETAR;
}
//Destrutor 
CronometroAbstract::~CronometroAbstract() 
{

}
//Configura a unidade de tempo a ser usada
void CronometroAbstract::setUnidade(Tempo eTempo) 
{
    tempoUnidade = int(eTempo);
}
//Muda o estado para CRONOMETRO_RESETAR
void CronometroAbstract::setResetar() 
{
    if ((eCronometro==CRONOMETRO_EXECUTAR)||(eCronometro==CRONOMETRO_TERMINAR)){
        eCronometro=CRONOMETRO_RESETAR;
    }
}
//Muda o estado para CRONOMETRO_INICIAR
void CronometroAbstract::setIniciar() 
{
    if (eCronometro==CRONOMETRO_RESETAR){
        eCronometro=CRONOMETRO_INICIAR;
    }
}
//Muda o estado para CRONOMETRO_PAUSAR
void CronometroAbstract::setPausar() 
{
    if (eCronometro==CRONOMETRO_EXECUTAR){
        eCronometro=CRONOMETRO_PAUSAR;
    }
}
//Muda o estado para CRONOMETRO_CONTINUAR
void CronometroAbstract::setContinuar() 
{
    if (eCronometro==CRONOMETRO_PAUSAR){
        eCronometro=CRONOMETRO_CONTINUAR;
    }
}
//Centro de processamento de estados
void CronometroAbstract::processar() 
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
int CronometroAbstract::getTempo() 
{
    return tempoCorrente;
}
//Adiciona o marcador de tempo inicial
void CronometroAbstract::setTempoOriginal(int tempo) 
{
    tempoOriginal=tempo;
}
//Informa se o tempo já terminou
bool CronometroAbstract::isTerminou() 
{
    if (eCronometro==CRONOMETRO_TERMINAR){
        return true;
    } else {
        return false;
    }
}

} // namespace GBF::Kernel::Timer

} // namespace GBF::Kernel

} // namespace GBF
