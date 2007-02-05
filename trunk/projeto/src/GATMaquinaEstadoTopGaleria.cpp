////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
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

#include "GATMaquinaEstadoTopGaleria.h"

GATMaquinaEstadoTopGaleria::GATMaquinaEstadoTopGaleria() 
{
    setTopGaleriaInicio();
}
GATMaquinaEstadoTopGaleria::~GATMaquinaEstadoTopGaleria() 
{
}
GATEstadoTopGaleria GATMaquinaEstadoTopGaleria::processarEstadoTopGaleria() 
{
    return estado;
}
void GATMaquinaEstadoTopGaleria::loopTopGaleria() 
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
void GATMaquinaEstadoTopGaleria::setTopGaleriaNovo() 
{
    if ((estado!=GAT_ET_NOVO)&&(gatilhoTopGaleriaNovo())){
        estado=GAT_ET_NOVO;
//		reiniciarTempo();
//      tempoEspera.setIniciar();
    }
}
void GATMaquinaEstadoTopGaleria::setTopGaleriaSalvar() 
{
//    if ((estado!=GAT_ET_SALVAR)&&(isTempoEspera())){
    if (estado!=GAT_ET_SALVAR){
        estado=GAT_ET_SALVAR;
//        reiniciarTempo();            
//        gatilhoTopGaleriaSalvar();            
    }
}
void GATMaquinaEstadoTopGaleria::setTopGaleriaExibir() 
{
    if ((estado==GAT_ET_INICIO)||
        ((estado!=GAT_ET_EXIBIR)&&(isTempoEspera()))){
        gatilhoTopGaleriaExibir();
        estado=GAT_ET_EXIBIR;
		reiniciarTempo();
    }
}
bool GATMaquinaEstadoTopGaleria::gatilhoTopGaleriaNovo() 
{
//opicional implementação de acordo com a necessidade
    return true;
}
bool GATMaquinaEstadoTopGaleria::gatilhoTopGaleriaSalvar() 
{
//opicional implementação de acordo com a necessidade
    return true;
}
bool GATMaquinaEstadoTopGaleria::gatilhoTopGaleriaExibir() 
{
//opicional implementação de acordo com a necessidade
    return true;
}
void GATMaquinaEstadoTopGaleria::setTopGaleriaInicio() 
{
    estado=GAT_ET_INICIO;
}
