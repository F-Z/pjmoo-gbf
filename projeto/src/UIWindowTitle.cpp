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
    title.setAlignment(Text::TEXT_CENTRAL);
}
UIWindowTitle::~UIWindowTitle(){
}

void UIWindowTitle::desenharConteudo()
{
    UIWindowDialog::desenharConteudo();

    int posicaoTextoHorizontal = 0;
    int posicaoTextoVertical   = position.y+int(title.getLetterDimension().h*0.2);

    if (title.getAlignment()==Text::TEXT_CENTRAL){
        int auxiliar = writeManager->getLarguraLinha(title.getFont(),title.getKeyText());
        posicaoTextoHorizontal=int (position.x+(dimension.w/2)-(auxiliar/2));
    } else {
        posicaoTextoHorizontal = position.x+title.getLetterDimension().w;
    }

    writeManager->escreverLocalizado(title.getFont(),posicaoTextoHorizontal,posicaoTextoVertical,title.getKeyText());

}
//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindowTitle::inicializar()
{
    UIWindowDialog::inicializar();
    title.setLetterDimension(writeManager->getFonte(title.getFont())->getDimensao());
    espacoAntesTexto=int(title.getLetterDimension().h*title.STYLE_SINGLE_AND_HALF_LINE);
}

} // namespace UserInterface::Window

} // namespace UserInterface
