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
#include "GTScore.h"

namespace GAT {

//Construtor
GTScore::GTScore()
{
    setTopGaleriaInicio();
}

//Destrutor
GTScore::~GTScore()
{
}

StateScore GTScore::processarEstadoTopGaleria()
{
    return estado;
}

void GTScore::loopTopGaleria()
{
    switch (processarEstadoTopGaleria()){

        case GAT_ET_EXIBIR:
            topGaleriaExibir();
            break;

        case GAT_ET_NOVO:
            topGaleriaNovo();
            break;

        case GAT_ET_SALVAR:
            topGaleriaSalvar();
            break;

        case GAT_ET_INICIO:

        default:
            setTopGaleriaExibir();
            break;
    }
}

void GTScore::setTopGaleriaNovo()
{
    if ((estado != GAT_ET_NOVO) && (gatilhoTopGaleriaNovo())){
        estado = GAT_ET_NOVO;
//  reiniciarTempo();
//      tempoEspera.setIniciar();
    }
}

void GTScore::setTopGaleriaSalvar()
{
//    if ((estado!=GAT_ET_SALVAR)&&(isTempoEspera())){
    if (estado != GAT_ET_SALVAR){
        estado = GAT_ET_SALVAR;
//        reiniciarTempo();
//        gatilhoTopGaleriaSalvar();
    }
}

void GTScore::setTopGaleriaExibir()
{
    if ((estado == GAT_ET_INICIO) ||
            ((estado != GAT_ET_EXIBIR) && (isTempoEspera()))){
        gatilhoTopGaleriaExibir();
        estado = GAT_ET_EXIBIR;
        reiniciarTempo();
    }
}

bool GTScore::gatilhoTopGaleriaNovo()
{
    return true;
}

bool GTScore::gatilhoTopGaleriaSalvar()
{
    return true;
}

bool GTScore::gatilhoTopGaleriaExibir()
{
    return true;
}

void GTScore::setTopGaleriaInicio()
{
    estado = GAT_ET_INICIO;
}

} // namespace GAT
