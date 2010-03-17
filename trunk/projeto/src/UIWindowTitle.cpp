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

#include "UIWindowTitle.h"

namespace UserInterface {

namespace Window {

UIWindowTitle::UIWindowTitle()
{
    title.setAlinhamento(Texto::TEXTO_CENTRALIZADO);
}
UIWindowTitle::~UIWindowTitle(){
}

void UIWindowTitle::desenharConteudo()
{
    UIWindowDialog::desenharConteudo();

    int posicaoTextoHorizontal = 0;
    int posicaoTextoVertical   = position.y+int(title.getDimensaoLetra().h*0.2);

    if (title.getAlinhamento()==Texto::TEXTO_CENTRALIZADO){
        int auxiliar = writeManager->getLarguraLinha(title.getFonte(),title.getChaveTexto());
        posicaoTextoHorizontal=int (position.x+(dimension.w/2)-(auxiliar/2));
    } else {
        posicaoTextoHorizontal = position.x+title.getDimensaoLetra().w;
    }

    writeManager->escreverLocalizado(title.getFonte(),posicaoTextoHorizontal,posicaoTextoVertical,title.getChaveTexto());

}
//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindowTitle::inicializar()
{
    UIWindowDialog::inicializar();
    title.setDimensaoLetra(writeManager->getFonte(title.getFonte())->getDimensao());
    espacoAntesTexto=int(title.getDimensaoLetra().h*title.ENTRELINHA_UMA_MEIA);
}

} // namespace UserInterface::Window

} // namespace UserInterface
