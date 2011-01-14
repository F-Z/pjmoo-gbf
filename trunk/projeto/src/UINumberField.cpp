/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#include "UINumberField.h"

namespace UserInterface {

namespace Component {

UINumberField::UINumberField()
{
}

UINumberField::~UINumberField()
{
}

void UINumberField::setValue(unsigned int value)
{
    this->value = value;
}
void UINumberField::drawContent()
{
    writeManager->write(fonteCampo.name, fonteCampo.point.x, fonteCampo.point.y, "%08d", value);
}

} // namespace UserInterface::Component

} // namespace UserInterface
