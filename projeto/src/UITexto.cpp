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

#include "UITexto.h"

namespace UserInterface {

namespace Texto {

const float UITexto::ENTRELINHA_SIMPLES=1.0;

const float UITexto::ENTRELINHA_UMA_MEIA=1.5;

const float UITexto::ENTRELINHA_DUPLA=2.0;

//Construtor

//Construtor
UITexto::UITexto(){
    entreLinhas=ENTRELINHA_UMA_MEIA;
    alinhamento=TEXTO_NORMAL;
}

//Destrutor

//Destrutor
UITexto::~UITexto(){
}

void UITexto::setFonte(std::string fonte) 
{
    this->fonte=fonte;

//    dimensaoLetra=wsManager->getFonte(fonte)->getDimensao();
//    espacoEntreLinhas=int(dimensaoLetra.w*estiloEntreLinhas);
}
std::string UITexto::getFonte() 
{
    return fonte;
}
void UITexto::setChaveTexto(std::string chaveTexto) 
{
    this->chaveTexto=chaveTexto;
}
std::string UITexto::getChaveTexto() 
{
    return chaveTexto;
}
void UITexto::setDimensaoLetra(const Dimensao & dimensao) 
{
    dimensaoLetra=dimensao;
    espacoEntreLinhas=int(dimensaoLetra.w*entreLinhas);
}
Dimensao UITexto::getDimensaoLetra() 
{
    return dimensaoLetra;
}
//Informa o Estilo de entrelinhas a ser utilizado

//Informa o Estilo de entrelinhas a ser utilizado
void UITexto::setEntreLinha(float estiloEntreLinhas) 
{
    if ((estiloEntreLinhas==ENTRELINHA_SIMPLES)||(estiloEntreLinhas==ENTRELINHA_UMA_MEIA)||
       (estiloEntreLinhas==ENTRELINHA_DUPLA)){
        entreLinhas=estiloEntreLinhas;
    }
}
//Retorna em pixel o espaçamento entre as linhas

//Retorna em pixel o espaçamento entre as linhas
int UITexto::getEspacoEntreLinhas() 
{
    return espacoEntreLinhas;
}
//Configura o Alinhamento do Texto

//Configura o Alinhamento do Texto
void UITexto::setAlinhamento(UITextoAlinhamento alinhamento) 
{
    this->alinhamento=alinhamento;
}
//Retorna o alinhamento utilizado

//Retorna o alinhamento utilizado
UITextoAlinhamento UITexto::getAlinhamento() 
{
    return alinhamento;
}

} // namespace UserInterface::Texto

} // namespace UserInterface
