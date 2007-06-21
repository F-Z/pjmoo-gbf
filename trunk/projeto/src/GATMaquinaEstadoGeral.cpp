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

#include "GATMaquinaEstadoGeral.h"

//Construtor
GATMaquinaEstadoGeral::GATMaquinaEstadoGeral() 
{
    setInicio();
}
//Destrutor
GATMaquinaEstadoGeral::~GATMaquinaEstadoGeral() 
{
}
GATEstadoGeral GATMaquinaEstadoGeral::processarEstadoGeral() 
{
    return estado;
}
bool GATMaquinaEstadoGeral::setMenu() 
{
    bool mudou = false;
    //if ((estado!=GAT_EG_MENU)&&(isTempoEspera())){
    if (estado!=GAT_EG_MENU){
        if ((estado==GAT_EG_APRESENTACAO)
            ||(estado==GAT_EG_JOGO)
            ||(estado==GAT_EG_TOPGALERIA)){
                estado=GAT_EG_MENU;
                mudou=true;
                gatilhoMenu();
                reiniciarTempo();
        }
    }

    return mudou;
}
void GATMaquinaEstadoGeral::setApresentacao() 
{
    if (estado!=GAT_EG_APRESENTACAO){
        if ((estado==GAT_EG_MENU)
            ||(estado==GAT_EG_INICIO)){
                gatilhoApresentacao();
                estado=GAT_EG_APRESENTACAO;
        }
    }
}
bool GATMaquinaEstadoGeral::setJogo() 
{
    bool mudou = false;
    if ((estado!=GAT_EG_JOGO)
        //&&(estado==GAT_EG_MENU)&&(isTempoEspera())){
        &&(estado==GAT_EG_MENU)){
            estado=GAT_EG_JOGO;
            mudou = true;
            gatilhoJogo();
            //reiniciarTempo();
    }

    return mudou;
}
bool GATMaquinaEstadoGeral::setTopGaleria() 
{
    bool mudou = false;

    if ((estado!=GAT_EG_TOPGALERIA)&&(isTempoEspera())){
        estado=GAT_EG_TOPGALERIA;
        gatilhoJogo();
        mudou = true;
        reiniciarTempo();
    }

    return mudou;
}
void GATMaquinaEstadoGeral::setSair() 
{
//    if ((eEstadoGeral!=GAT_EG_SAIR)&&
//        (eEstadoGeral==GAT_EG_MENU)&&
//        (isTempoEspera())){
    if (estado!=GAT_EG_SAIR){ //provisorio
        gatilhoSair();
        estado=GAT_EG_SAIR;
    }
}
void GATMaquinaEstadoGeral::gatilhoMenu() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoGeral::gatilhoApresentacao() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoGeral::gatilhoJogo() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoGeral::gatilhoTopGaleria() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoGeral::gatilhoSair() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoGeral::setInicio() 
{
    estado=GAT_EG_INICIO;
}
