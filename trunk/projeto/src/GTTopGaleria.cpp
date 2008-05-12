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

#include "GTTopGaleria.h"

namespace GAT {

//Construtor
GTTopGaleria::GTTopGaleria() 
{
    setTopGaleriaInicio();
}
//Destrutor
GTTopGaleria::~GTTopGaleria() 
{
}
EstadoTopGaleria GTTopGaleria::processarEstadoTopGaleria() 
{
    return estado;
}
void GTTopGaleria::loopTopGaleria() 
{
    switch(processarEstadoTopGaleria()){
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
void GTTopGaleria::setTopGaleriaNovo() 
{
    if ((estado!=GAT_ET_NOVO)&&(gatilhoTopGaleriaNovo())){
        estado=GAT_ET_NOVO;
//		reiniciarTempo();
//      tempoEspera.setIniciar();
    }
}
void GTTopGaleria::setTopGaleriaSalvar() 
{
//    if ((estado!=GAT_ET_SALVAR)&&(isTempoEspera())){
    if (estado!=GAT_ET_SALVAR){
        estado=GAT_ET_SALVAR;
//        reiniciarTempo();            
//        gatilhoTopGaleriaSalvar();            
    }
}
void GTTopGaleria::setTopGaleriaExibir() 
{
    if ((estado==GAT_ET_INICIO)||
        ((estado!=GAT_ET_EXIBIR)&&(isTempoEspera()))){
        gatilhoTopGaleriaExibir();
        estado=GAT_ET_EXIBIR;
		reiniciarTempo();
    }
}
bool GTTopGaleria::gatilhoTopGaleriaNovo() 
{
//opicional implementação de acordo com a necessidade
    return true;
}
bool GTTopGaleria::gatilhoTopGaleriaSalvar() 
{
//opicional implementação de acordo com a necessidade
    return true;
}
bool GTTopGaleria::gatilhoTopGaleriaExibir() 
{
//opicional implementação de acordo com a necessidade
    return true;
}
void GTTopGaleria::setTopGaleriaInicio() 
{
    estado=GAT_ET_INICIO;
}

} // namespace GAT
