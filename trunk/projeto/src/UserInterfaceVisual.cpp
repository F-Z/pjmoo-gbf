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

#include "UserInterfaceVisual.h"

UserInterfaceVisual::UserInterfaceVisual(){
    if (gsGFX==NULL){
        gsGFX = GraphicSystemGFX::getInstance();
    }

}

UserInterfaceVisual::UserInterfaceVisual(const UserInterfaceVisual & base){
    posicao  = base.posicao;
    dimensao = base.dimensao;
    corBorda = base.corBorda;
}

UserInterfaceVisual::~UserInterfaceVisual(){
}

void UserInterfaceVisual::setCorBorda(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b) 
{
    corBorda.r=r;
    corBorda.g=g;
    corBorda.b=b;
}
//Aplica o efeito visual

//Aplica o efeito visual
void UserInterfaceVisual::aplicar(const Ponto & posicao, const Dimensao & dimensao) 
{
    this->dimensao=dimensao;
    this->posicao=posicao;
}
GraphicSystemGFX * UserInterfaceVisual::gsGFX =NULL;

