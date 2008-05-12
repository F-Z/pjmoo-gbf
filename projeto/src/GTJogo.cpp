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

#include "GTJogo.h"

namespace GAT {

//Construtor
GTJogo::GTJogo() 
{
    setJogoInicio();
}
//Destrutor
GTJogo::~GTJogo() 
{
}
EstadoJogo GTJogo::processarEstadoJogo() 
{
    return estado;
}
void GTJogo::loopJogo() 
{
    switch(processarEstadoJogo()){
        case GAT_EJ_EXECUTANDO:
                jogoExecutando();
            break;
        case GAT_EJ_PAUSE:
                jogoPause();
            break;
        case GAT_EJ_FASE_CARREGAR:
                jogoFaseCarregar();
            break;
        case GAT_EJ_FASE_FINALIZADA:
                jogoFaseFinalizada();
            break;
        case GAT_EJ_GAMEOVER:
                jogoGameOver();
            break;
        case GAT_EJ_ZERADO:
                jogoZerado();
            break;
        case GAT_EJ_NOVO:
                jogoNovo();
            break;
        case GAT_EJ_INICIO:
        default:
                setJogoNovo();
            break;
    }
}
void GTJogo::setJogoNovo() 
{
    if ((estado==GAT_EJ_INICIO)||((estado!=GAT_EJ_NOVO)&&(isTempoEspera()))){
        estado=GAT_EJ_NOVO;
        gatilhoJogoNovo();
        reiniciarTempo();
    }
}
//Coloca o jogo em estado de execução imediata
void GTJogo::setJogoExecutando() 
{
//    if ((estado!=GAT_EJ_EXECUTANDO)&&(isTempoEspera())){
    if (estado!=GAT_EJ_EXECUTANDO){
        gatilhoJogoExecutando();
        estado=GAT_EJ_EXECUTANDO;
//      reiniciarTempo();
    }
}
void GTJogo::setJogoPause() 
{
    if ((estado!=GAT_EJ_PAUSE)&&(isTempoEspera())){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_PAUSE;
        reiniciarTempo();
    }
}
void GTJogo::setJogoFaseCarregar() 
{
    if ((estado!=GAT_EJ_FASE_CARREGAR)&&(isTempoEspera())){
        if (gatilhoJogoFaseCarregar()){
            estado=GAT_EJ_FASE_CARREGAR;
            reiniciarTempo();
        }
    }
}
void GTJogo::setJogoFaseFinalizada() 
{
    if (estado!=GAT_EJ_FASE_FINALIZADA){
        estado=GAT_EJ_FASE_FINALIZADA;
        gatilhoJogoFaseFinalizada();
        reiniciarTempo();
    }
}
void GTJogo::setJogoGameOver() 
{
    if ((estado!=GAT_EJ_GAMEOVER)&&(isTempoEspera())){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_GAMEOVER;
        reiniciarTempo();
    }
}
void GTJogo::setJogoZerado() 
{
    if (estado!=GAT_EJ_ZERADO){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_ZERADO;
        reiniciarTempo();
    }
}
void GTJogo::gatilhoJogoNovo() 
{
    //opicional implementação de acordo com a necessidade
}
void GTJogo::gatilhoJogoExecutando() 
{
    //opicional implementação de acordo com a necessidade
}
bool GTJogo::gatilhoJogoFaseCarregar() 
{
    //opicional implementação de acordo com a necessidade
    return true;
}
bool GTJogo::gatilhoJogoFaseFinalizada() 
{
    //opicional implementação de acordo com a necessidade
    return true;
}
void GTJogo::setJogoInicio() 
{
    estado=GAT_EJ_INICIO;
}

} // namespace GAT
