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

#include "UIButton.h"

namespace UserInterface
{

namespace Component
{

UIButton::UIButton(std::string font, std::string keyText, const SDLKey & key)
{
    button.setFont(font);
    button.setKeyText(keyText);
    this->key = key;

    dimension   = writeManager->getFonte(button.getFont())->getDimensao();
    dimension.w = writeManager->getLarguraLinha(button.getFont(), button.getKeyText());
}

UIButton::~UIButton()
{
}

//Retorna a tecla correspondente ao botão
SDLKey UIButton::getKey()
{
    return key;
}

//Desenha os componentes visuais
void UIButton::draw()
{
    writeManager->escreverLocalizado(button.getFont(), position.x, position.y, button.getKeyText());
}

} // namespace UserInterface::Componente

} // namespace UserInterface
