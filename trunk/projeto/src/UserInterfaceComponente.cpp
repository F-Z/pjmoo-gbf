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

#include "UserInterfaceComponente.h"

UserInterfaceComponente::UserInterfaceComponente(){
    if (wsManager==NULL){
        wsManager = WriteSystemManager::getInstance();
    }

    if (uiTexto==NULL){
        uiTexto = UserInterfaceTexto::getInstance();
    }
}

UserInterfaceComponente::~UserInterfaceComponente(){
}

WriteSystemManager * UserInterfaceComponente::wsManager=NULL;

UserInterfaceTexto * UserInterfaceComponente::uiTexto=NULL;

//Posicao do Componente na Tela
void UserInterfaceComponente::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
}
Dimensao UserInterfaceComponente::getDimensao() 
{
    return dimensao;
}
//Executa o componente (atualizando,desenhando)
void UserInterfaceComponente::executar() 
{
    atualizar();
    desenhar();
}
//atualiza as informações do componente (posicao, dimensao, estado)
void UserInterfaceComponente::atualizar() 
{
}
