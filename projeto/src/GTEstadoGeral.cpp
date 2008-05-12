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

#include "GTEstadoGeral.h"

namespace GAT {

//Construtor
GTEstadoGeral::GTEstadoGeral() 
{
    setInicio();
}
//Destrutor
GTEstadoGeral::~GTEstadoGeral() 
{
}
EstadoGeral GTEstadoGeral::processarEstadoGeral() 
{
    return estado;
}
bool GTEstadoGeral::setMenu() 
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
void GTEstadoGeral::setApresentacao() 
{
    if (estado!=GAT_EG_APRESENTACAO){
        if ((estado==GAT_EG_MENU)
            ||(estado==GAT_EG_INICIO)){
                gatilhoApresentacao();
                estado=GAT_EG_APRESENTACAO;
        }
    }
}
bool GTEstadoGeral::setJogo() 
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
bool GTEstadoGeral::setTopGaleria() 
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
void GTEstadoGeral::setSair() 
{
//    if ((eEstadoGeral!=GAT_EG_SAIR)&&
//        (eEstadoGeral==GAT_EG_MENU)&&
//        (isTempoEspera())){
    if (estado!=GAT_EG_SAIR){ //provisorio
        gatilhoSair();
        estado=GAT_EG_SAIR;
    }
}
void GTEstadoGeral::gatilhoMenu() 
{
    //opicional implementação de acordo com a necessidade
}
void GTEstadoGeral::gatilhoApresentacao() 
{
    //opicional implementação de acordo com a necessidade
}
void GTEstadoGeral::gatilhoJogo() 
{
    //opicional implementação de acordo com a necessidade
}
void GTEstadoGeral::gatilhoTopGaleria() 
{
    //opicional implementação de acordo com a necessidade
}
void GTEstadoGeral::gatilhoSair() 
{
    //opicional implementação de acordo com a necessidade
}
void GTEstadoGeral::setInicio() 
{
    estado=GAT_EG_INICIO;
}

} // namespace GAT
