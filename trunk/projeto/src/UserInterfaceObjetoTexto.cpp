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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "UserInterfaceObjetoTexto.h"

const float UserInterfaceObjetoTexto::ENTRELINHA_SIMPLES=1.0;

const float UserInterfaceObjetoTexto::ENTRELINHA_UMA_MEIA=1.5;

const float UserInterfaceObjetoTexto::ENTRELINHA_DUPLA=2.0;

//Construtor

//Construtor
UserInterfaceObjetoTexto::UserInterfaceObjetoTexto(){
    entreLinhas=ENTRELINHA_UMA_MEIA;
}

//Destrutor

//Destrutor
UserInterfaceObjetoTexto::~UserInterfaceObjetoTexto(){
}

void UserInterfaceObjetoTexto::setFonte(std::string fonte) 
{
    this->fonte=fonte;

//    dimensaoLetra=wsManager->getFonte(fonte)->getDimensao();
//    espacoEntreLinhas=int(dimensaoLetra.w*estiloEntreLinhas);
}
std::string UserInterfaceObjetoTexto::getFonte() 
{
    return fonte;
}
void UserInterfaceObjetoTexto::setChaveTexto(std::string chaveTexto) 
{
    this->chaveTexto=chaveTexto;
}
std::string UserInterfaceObjetoTexto::getChaveTexto() 
{
    return chaveTexto;
}
void UserInterfaceObjetoTexto::setDimensaoLetra(const Dimensao & dimensao) 
{
    dimensaoLetra=dimensao;
    espacoEntreLinhas=int(dimensaoLetra.w*entreLinhas);
}
Dimensao UserInterfaceObjetoTexto::getDimensaoLetra() 
{
    return dimensaoLetra;
}
//Informa o Estilo de entrelinhas a ser utilizado

//Informa o Estilo de entrelinhas a ser utilizado
void UserInterfaceObjetoTexto::setEntreLinha(float estiloEntreLinhas) 
{
    if ((estiloEntreLinhas==ENTRELINHA_SIMPLES)||(estiloEntreLinhas==ENTRELINHA_UMA_MEIA)||
       (estiloEntreLinhas==ENTRELINHA_DUPLA)){
        entreLinhas=estiloEntreLinhas;
    }
}
//Retorna em pixel o espaçamento entre as linhas

//Retorna em pixel o espaçamento entre as linhas
int UserInterfaceObjetoTexto::getEspacoEntreLinhas() 
{
    return espacoEntreLinhas;
}
//Configura o Alinhamento do Texto

//Configura o Alinhamento do Texto
void UserInterfaceObjetoTexto::setAlinhamento(UserInterfaceTextoAlinhamento alinhamento) 
{
    this->alinhamento=alinhamento;
}
//Retorna o alinhamento utilizado

//Retorna o alinhamento utilizado
UserInterfaceTextoAlinhamento UserInterfaceObjetoTexto::getAlinhamento() 
{
    return alinhamento;
}
