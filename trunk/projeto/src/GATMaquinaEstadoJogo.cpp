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

#include "GATMaquinaEstadoJogo.h"

//Construtor
GATMaquinaEstadoJogo::GATMaquinaEstadoJogo() 
{
    setJogoInicio();
}
//Destrutor
GATMaquinaEstadoJogo::~GATMaquinaEstadoJogo() 
{
}
GATEstadoJogo GATMaquinaEstadoJogo::processarEstadoJogo() 
{
    return estado;
}
void GATMaquinaEstadoJogo::loopJogo() 
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
void GATMaquinaEstadoJogo::setJogoNovo() 
{
    if ((estado==GAT_EJ_INICIO)||((estado!=GAT_EJ_NOVO)&&(isTempoEspera()))){
        estado=GAT_EJ_NOVO;
        gatilhoJogoNovo();
        reiniciarTempo();
    }
}
void GATMaquinaEstadoJogo::setJogoExecutando() 
{
    if ((estado!=GAT_EJ_EXECUTANDO)&&(isTempoEspera())){
        gatilhoJogoExecutando();
        estado=GAT_EJ_EXECUTANDO;        
		reiniciarTempo();
    }
}
void GATMaquinaEstadoJogo::setJogoPause() 
{
    if ((estado!=GAT_EJ_PAUSE)&&(isTempoEspera())){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_PAUSE;
        reiniciarTempo();
    }
}
void GATMaquinaEstadoJogo::setJogoFaseCarregar() 
{
    if ((estado!=GAT_EJ_FASE_CARREGAR)&&(isTempoEspera())){
        if (gatilhoJogoFaseCarregar()){
            estado=GAT_EJ_FASE_CARREGAR;
            reiniciarTempo();
        }
    }
}
void GATMaquinaEstadoJogo::setJogoFaseFinalizada() 
{
    if (estado!=GAT_EJ_FASE_FINALIZADA){
        estado=GAT_EJ_FASE_FINALIZADA;
        gatilhoJogoFaseFinalizada();
        reiniciarTempo();
    }
}
void GATMaquinaEstadoJogo::setJogoGameOver() 
{
    if ((estado!=GAT_EJ_GAMEOVER)&&(isTempoEspera())){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_GAMEOVER;
        reiniciarTempo();
    }
}
void GATMaquinaEstadoJogo::setJogoZerado() 
{
    if (estado!=GAT_EJ_ZERADO){
        //gatilhoJogoExecutando();
        estado=GAT_EJ_ZERADO;
        reiniciarTempo();
    }
}
void GATMaquinaEstadoJogo::gatilhoJogoNovo() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoJogo::gatilhoJogoExecutando() 
{
    //opicional implementação de acordo com a necessidade
}
bool GATMaquinaEstadoJogo::gatilhoJogoFaseCarregar() 
{
    //opicional implementação de acordo com a necessidade
    return true;
}
bool GATMaquinaEstadoJogo::gatilhoJogoFaseFinalizada() 
{
    //opicional implementação de acordo com a necessidade
    return true;
}
void GATMaquinaEstadoJogo::setJogoInicio() 
{
    estado=GAT_EJ_INICIO;
}
