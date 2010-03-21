/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "UIComponent.h"

namespace UserInterface
{

UIComponent::UIComponent()
{
    if (writeManager == NULL){
        writeManager = GBF::Kernel::Write::WriteManager::getInstance();
    }

    if (language == NULL){
        language = GBF::Kernel::Write::Language::getInstance();
    }
}

UIComponent::~UIComponent()
{
}

GBF::Kernel::Write::Language * UIComponent::language = NULL;

GBF::Kernel::Write::WriteManager * UIComponent::writeManager = NULL;

/** Posicao do Componente na Tela */
void UIComponent::setPoint(int x, int y)
{
    point.x = x;
    point.y = y;
}

GBF::Dimension UIComponent::getDimension()
{
    return dimension;
}

/** Executa o componente (atualizando,desenhando) */
void UIComponent::execute()
{
    update();
    draw();
}

/** atualiza as informações do componente (posicao, dimensao, estado) */
void UIComponent::update()
{
}

} //  namespace UserInterface
