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

#include "UITextField.h"

namespace UserInterface {

namespace Componente {

UITextField::UITextField(){

}

UITextField::~UITextField(){
    //dtor
}

void UITextField::setValue(std::string value) 
{
    this->value=value;
}
void UITextField::desenharConteudo() 
{
    wsManager->escrever(fonteCampo.nome, fonteCampo.posicao.x, fonteCampo.posicao.y,"%s"  ,value.c_str());
}

} // namespace UserInterface::Componente

} // namespace UserInterface
