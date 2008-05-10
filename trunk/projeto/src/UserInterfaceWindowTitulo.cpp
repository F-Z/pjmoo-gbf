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

#include "UserInterfaceWindowTitulo.h"

UserInterfaceWindowTitulo::UserInterfaceWindowTitulo(){
    titulo.setAlinhamento(TEXTO_CENTRALIZADO);
}

UserInterfaceWindowTitulo::~UserInterfaceWindowTitulo(){
}

void UserInterfaceWindowTitulo::desenharConteudo()
{
    UserInterfaceWindowDialog::desenharConteudo();

    int posicaoTextoHorizontal = 0;
    int posicaoTextoVertical   = posicao.y+int(titulo.getDimensaoLetra().h*0.2);

    if (titulo.getAlinhamento()==TEXTO_CENTRALIZADO){
        int auxiliar = wsManager->getLarguraLinha(titulo.getFonte(),titulo.getChaveTexto());
        posicaoTextoHorizontal=int (posicao.x+(dimensao.w/2)-(auxiliar/2));
    } else {
        posicaoTextoHorizontal = posicao.x+titulo.getDimensaoLetra().w;
    }

    wsManager->escreverLocalizado(titulo.getFonte(),posicaoTextoHorizontal,posicaoTextoVertical,titulo.getChaveTexto());

}
//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UserInterfaceWindowTitulo::inicializar()
{
    UserInterfaceWindowDialog::inicializar();
    titulo.setDimensaoLetra(wsManager->getFonte(titulo.getFonte())->getDimensao());
    espacoAntesTexto=int(titulo.getDimensaoLetra().h*titulo.ENTRELINHA_UMA_MEIA);
}
