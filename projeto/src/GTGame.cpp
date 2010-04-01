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
#include "GTGame.h"

namespace GAT {

//Construtor
GTGame::GTGame()
{
    setJogoInicio();
}

//Destrutor
GTGame::~GTGame()
{
}

StateGame GTGame::processarEstadoJogo()
{
    return estado;
}

void GTGame::loopJogo()
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

void GTGame::setJogoNovo()
{
    if ((estado==GAT_EJ_INICIO)||((estado!=GAT_EJ_NOVO)&&(isTempoEspera()))){
        estado=GAT_EJ_NOVO;
        gatilhoJogoNovo();
        reiniciarTempo();
    }
}

//Coloca o jogo em estado de execução imediata
void GTGame::setJogoExecutando()
{
//    if ((estado!=GAT_EJ_EXECUTANDO)&&(isTempoEspera())){
    if (estado!=GAT_EJ_EXECUTANDO){
        gatilhoJogoExecutando();
        estado=GAT_EJ_EXECUTANDO;
//      reiniciarTempo();
    }
}

void GTGame::setJogoPause()
{
    if ((estado!=GAT_EJ_PAUSE)&&(isTempoEspera())){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_PAUSE;
        reiniciarTempo();
    }
}

void GTGame::setJogoFaseCarregar()
{
    if ((estado!=GAT_EJ_FASE_CARREGAR)&&(isTempoEspera())){
        if (gatilhoJogoFaseCarregar()){
            estado=GAT_EJ_FASE_CARREGAR;
            reiniciarTempo();
        }
    }
}

void GTGame::setJogoFaseFinalizada()
{
    if (estado!=GAT_EJ_FASE_FINALIZADA){
        estado=GAT_EJ_FASE_FINALIZADA;
        gatilhoJogoFaseFinalizada();
        reiniciarTempo();
    }
}

void GTGame::setJogoGameOver()
{
    if ((estado!=GAT_EJ_GAMEOVER)&&(isTempoEspera())){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_GAMEOVER;
        reiniciarTempo();
    }
}

void GTGame::setJogoZerado()
{
    if (estado!=GAT_EJ_ZERADO){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_ZERADO;
        reiniciarTempo();
    }
}

void GTGame::gatilhoJogoNovo()
{
    //opicional implementação de acordo com a necessidade
}

void GTGame::gatilhoJogoExecutando()
{
    //opicional implementação de acordo com a necessidade
}

bool GTGame::gatilhoJogoFaseCarregar()
{
    //opicional implementação de acordo com a necessidade
    return true;
}

bool GTGame::gatilhoJogoFaseFinalizada()
{
    //opicional implementação de acordo com a necessidade
    return true;
}

void GTGame::setJogoInicio()
{
    estado=GAT_EJ_INICIO;
}

} // namespace GAT
