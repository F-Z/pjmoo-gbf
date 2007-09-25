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

#include "UserInterfaceVisualSolido.h"

UserInterfaceVisualSolido::UserInterfaceVisualSolido(){
}

UserInterfaceVisualSolido::UserInterfaceVisualSolido(const UserInterfaceVisualSolido & base):UserInterfaceVisual(base) 
{
    corFundo=base.corFundo;
}

UserInterfaceVisualSolido::~UserInterfaceVisualSolido(){
}

void UserInterfaceVisualSolido::setCorFundo(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b) 
{
    corFundo.r=r;
    corFundo.g=g;
    corFundo.b=b;
}
//Desenha o EstiloVisual do Componente

//Desenha o EstiloVisual do Componente
void UserInterfaceVisualSolido::desenhar() 
{
    gsGFX->setColor(corFundo.r,corFundo.g,corFundo.b);
    gsGFX->retanguloPreenchido(posicao.x,posicao.y,dimensao.w,dimensao.h);

    gsGFX->setColor(corBorda.r,corBorda.g,corBorda.b);
    gsGFX->retangulo(posicao.x,posicao.y,dimensao.w,dimensao.h);
}
UserInterfaceVisual * UserInterfaceVisualSolido::clone() 
{
   return new UserInterfaceVisualSolido(*this);
}
