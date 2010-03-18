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

#include "UIComponent.h"

namespace UserInterface
{

UIComponent::UIComponent()
{
    if (writeManager == NULL){
        writeManager = GBF::Kernel::Write::WriteManager::getInstance();
    }

    if (text == NULL){
        text = GBF::Kernel::Write::Language::getInstance();
    }
}

UIComponent::~UIComponent()
{
}

GBF::Kernel::Write::Language * UIComponent::text = NULL;

GBF::Kernel::Write::WriteManager * UIComponent::writeManager = NULL;

//Posicao do Componente na Tela
void UIComponent::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

GBF::Dimension UIComponent::getDimension()
{
    return dimension;
}

//Executa o componente (atualizando,desenhando)
void UIComponent::execute()
{
    update();
    draw();
}

//atualiza as informações do componente (posicao, dimensao, estado)
void UIComponent::update()
{
}

} // namespace UserInterface
