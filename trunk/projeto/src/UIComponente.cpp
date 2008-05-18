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

#include "UIComponente.h"

namespace UserInterface {

UIComponente::UIComponente() 
{
    if (wsManager==NULL){
        wsManager = GBF::Kernel::Write::WriteManager::getInstance();
    }

    if (uiTexto==NULL){
        uiTexto = GBF::Kernel::Write::Idioma::getInstance();
    }
}
UIComponente::~UIComponente(){
}

GBF::Kernel::Write::Idioma * UIComponente::uiTexto=NULL;

GBF::Kernel::Write::WriteManager * UIComponente::wsManager=NULL;

//Posicao do Componente na Tela
void UIComponente::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
}
GBF::Dimensao UIComponente::getDimensao() 
{
    return dimensao;
}
//Executa o componente (atualizando,desenhando)
void UIComponente::executar() 
{
    atualizar();
    desenhar();
}
//atualiza as informações do componente (posicao, dimensao, estado)
void UIComponente::atualizar() 
{
}

} // namespace UserInterface
