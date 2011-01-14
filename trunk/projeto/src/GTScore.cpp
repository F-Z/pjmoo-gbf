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
#include "GTScore.h"

namespace GAT {

/** Construtor */
GTScore::GTScore()
{
    state = SCORE_VIEW;
    setScoreView();
}

/** Destrutor */
GTScore::~GTScore()
{
}

/** Retorna o Estado do Score */
StateScore GTScore::getScoreState()
{
    return state;
}

void GTScore::loopScore()
{
    switch (getScoreState()){

        case SCORE_VIEW:
            screenViewScore();
            break;

        case SCORE_NEW:
            screenNewScore();
            break;

        case SCORE_SAVE:
            actionSaveScore();
            break;

        default:
            setScoreView();
            break;
    }
}

void GTScore::setScoreNew()
{
    if ((state != SCORE_NEW) && (triggerNewScore())){
        state = SCORE_NEW;
//  reiniciarTempo();
//      tempoEspera.setIniciar();
    }
}

void GTScore::setScoreSave()
{
//    if ((estado!=GAT_ET_SALVAR)&&(isTempoEspera())){
    if (state != SCORE_SAVE){
        state = SCORE_SAVE;
//        reiniciarTempo();
//        gatilhoTopGaleriaSalvar();
    }
}

void GTScore::setScoreView()
{
    if ((state == SCORE_VIEW) || ((state != SCORE_VIEW) && (isFinish()))){
        triggerViewScore();
        state = SCORE_VIEW;
        reset();
    }
}

bool GTScore::triggerNewScore()
{
    return true;
}

bool GTScore::triggerSaveScore()
{
    return true;
}

bool GTScore::triggerViewScore()
{
    return true;
}

} // namespace GAT
