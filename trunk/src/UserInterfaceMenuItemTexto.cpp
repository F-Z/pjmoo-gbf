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

#include "UserInterfaceMenuItemTexto.h"

WriteSystemManager * UserInterfaceMenuItemTexto::wsManager =NULL;

UserInterfaceMenuItemTexto::UserInterfaceMenuItemTexto(const std::string & texto, const std::string & fonteTexto) 
{
    this->texto=texto;
    this->fonteTexto=fonteTexto;
    
    tempo.setTempoOriginal(0);
    tempo.setUnidade(TEMPO_CENTESIMO);
    tempo.setResetar();
    
    if (wsManager==NULL){
        wsManager = WriteSystemManager::getInstance();
    }
}
UserInterfaceMenuItemTexto::~UserInterfaceMenuItemTexto() 
{
}
void UserInterfaceMenuItemTexto::desenhar(int x, int y) 
{
    if (isAtivo()){
        tempo.processar();
        if (tempo.getTempo()%2==0){
            wsManager->escreverLocalizado(fonteTexto,x,y,texto.c_str());
        }
    } else {
        wsManager->escreverLocalizado(fonteTexto,x,y,texto.c_str());
    }
}
int UserInterfaceMenuItemTexto::getQuantidadeLetras() 
{
//    return strlen(wsManager->uiTexto->getTexto(fonteTexto).c_str());
    return wsManager->uiTexto->getTexto(texto).length();
}
Dimensao UserInterfaceMenuItemTexto::getDimensaoLetra() 
{
    return wsManager->getFonte(fonteTexto)->getDimensao();
}
