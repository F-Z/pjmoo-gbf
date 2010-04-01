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
#include "GTState.h"

namespace GAT {

//Construtor
GTState::GTState()
{
    setInicio();
}

//Destrutor
GTState::~GTState()
{
}

State GTState::processarEstadoGeral()
{
    return estado;
}

bool GTState::setMenu()
{
    bool mudou = false;
    //if ((estado!=GAT_EG_MENU)&&(isTempoEspera())){

    if (estado != GAT_EG_MENU){
        if ((estado == GAT_EG_APRESENTACAO)
                || (estado == GAT_EG_JOGO)
                || (estado == GAT_EG_TOPGALERIA)){
            estado = GAT_EG_MENU;
            mudou = true;
            gatilhoMenu();
            reiniciarTempo();
        }
    }

    return mudou;
}

void GTState::setApresentacao()
{
    if (estado != GAT_EG_APRESENTACAO){
        if ((estado == GAT_EG_MENU)
                || (estado == GAT_EG_INICIO)){
            gatilhoApresentacao();
            estado = GAT_EG_APRESENTACAO;
        }
    }
}

bool GTState::setJogo()
{
    bool mudou = false;

    if ((estado != GAT_EG_JOGO)
            //&&(estado==GAT_EG_MENU)&&(isTempoEspera())){
            && (estado == GAT_EG_MENU)){
        estado = GAT_EG_JOGO;
        mudou = true;
        gatilhoJogo();
        //reiniciarTempo();
    }

    return mudou;
}

bool GTState::setTopGaleria()
{
    bool mudou = false;

    if ((estado != GAT_EG_TOPGALERIA) && (isTempoEspera())){
        estado = GAT_EG_TOPGALERIA;
        gatilhoJogo();
        mudou = true;
        reiniciarTempo();
    }

    return mudou;
}

void GTState::setSair()
{
//    if ((eEstadoGeral!=GAT_EG_SAIR)&&
//        (eEstadoGeral==GAT_EG_MENU)&&
//        (isTempoEspera())){
    if (estado != GAT_EG_SAIR){ //provisorio
        gatilhoSair();
        estado = GAT_EG_SAIR;
    }
}

void GTState::gatilhoMenu()
{
    //opcional implementação de acordo com a necessidade
}

void GTState::gatilhoApresentacao()
{
    //opcional implementação de acordo com a necessidade
}

void GTState::gatilhoJogo()
{
    //opcional implementação de acordo com a necessidade
}

void GTState::gatilhoTopGaleria()
{
    //opcional implementação de acordo com a necessidade
}

void GTState::gatilhoSair()
{
    //opcional implementação de acordo com a necessidade
}

void GTState::setInicio()
{
    estado = GAT_EG_INICIO;
}

} // namespace GAT
