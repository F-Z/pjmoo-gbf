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

    dimension   = writeManager->getFont(button.getFont())->getDimension();
    dimension.w = writeManager->getLineWidth(button.getFont(), button.getKeyText());
}

UIButton::~UIButton()
{
}

/** Retorna a tecla correspondente ao botão */
SDLKey UIButton::getKey()
{
    return key;
}

/** Desenha os componentes visuais */
void UIButton::draw()
{
    writeManager->writeKeyText(button.getFont(), point.x, point.y, button.getKeyText());
}

} // namespace UserInterface::Component

} // namespace UserInterface
