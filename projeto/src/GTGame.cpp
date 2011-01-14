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
#include "GTGame.h"

namespace GAT {

//Construtor
GTGame::GTGame()
{
    setGameStart();
}

//Destrutor
GTGame::~GTGame()
{
}

StateGame GTGame::processarEstadoJogo()
{
    return estado;
}

void GTGame::loopGame()
{
    switch(processarEstadoJogo()){
        case GAME_ON:
                actionOnGame();
            break;
        case GAME_PAUSE:
                screenGamePause();
            break;
        case GAME_STAGE_LOAD:
                screenLoadStage();
            break;
        case GAME_STAGE_FINISH:
                screenFinishStage();
            break;
        case GAME_OVER:
                screenGameOver();
            break;
        case GAME_FINISH:
                screenGameFinish();
            break;
        case GAME_NEW:
                actionNewGame();
            break;
        case GAME_START:
        default:
                setNewGame();
            break;
    }
}

void GTGame::setNewGame()
{
    if ((estado==GAME_START)||((estado!=GAME_NEW)&&(isFinish()))){
        estado=GAME_NEW;
        triggerNewGame();
        reset();
    }
}

//Coloca o jogo em estado de execução imediata
void GTGame::setOnGame()
{
//    if ((estado!=GAT_EJ_EXECUTANDO)&&(isTempoEspera())){
    if (estado!=GAME_ON){
        triggerOnGame();
        estado=GAME_ON;
//      reiniciarTempo();
    }
}

void GTGame::setGamePause()
{
    if ((estado!=GAME_PAUSE)&&(isFinish())){
        //gatilhoJogoExecutando();
        estado=GAME_PAUSE;
        reset();
    }
}

void GTGame::setLoadStage()
{
    if ((estado!=GAME_STAGE_LOAD)&&(isFinish())){
        if (triggerLoadStage()){
            estado=GAME_STAGE_LOAD;
            reset();
        }
    }
}

void GTGame::setFinishStage()
{
    if (estado!=GAME_STAGE_FINISH){
        estado=GAME_STAGE_FINISH;
        triggerFinishStage();
        reset();
    }
}

void GTGame::setGameOver()
{
    if ((estado!=GAME_OVER)&&(isFinish())){
        //gatilhoJogoExecutando();
        estado=GAME_OVER;
        reset();
    }
}

void GTGame::setGameFinish()
{
    if (estado!=GAME_FINISH){
        //gatilhoJogoExecutando();
        estado=GAME_FINISH;
        reset();
    }
}

void GTGame::triggerNewGame()
{
    //opcional implementação de acordo com a necessidade
}

void GTGame::triggerOnGame()
{
    //opcional implementação de acordo com a necessidade
}

bool GTGame::triggerLoadStage()
{
    return true;
}

bool GTGame::triggerFinishStage()
{
    return true;
}

void GTGame::setGameStart()
{
    estado=GAME_START;
}

} // namespace GAT
