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

#include "UINumberField.h"

namespace UserInterface {

namespace Componente {

UINumberField::UINumberField(){
    //ctor
}

UINumberField::~UINumberField(){
    //dtor
}

void UINumberField::setValue(unsigned int value) 
{
    this->value=value;
}
void UINumberField::desenharConteudo() 
{
    wsManager->escrever(fonteCampo.nome, fonteCampo.posicao.x, fonteCampo.posicao.y,"%08d",value);
}

} // namespace UserInterface::Componente

} // namespace UserInterface
