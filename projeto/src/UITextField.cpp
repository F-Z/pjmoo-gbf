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

#include "UITextField.h"

namespace UserInterface {

namespace Component {

UITextField::UITextField(){
}

UITextField::~UITextField(){
}

void UITextField::setValue(std::string value)
{
    this->value = value;
}
void UITextField::drawContent()
{
    writeManager->write(fonteCampo.nome, fonteCampo.posicao.x, fonteCampo.posicao.y, "%s"  , value.c_str());
}

} // namespace UserInterface::Componente

} // namespace UserInterface
