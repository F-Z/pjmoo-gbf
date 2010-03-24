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

#include "UIBackground.h"

namespace UserInterface {

namespace Look {

/** Construtor */
UIBackground::UIBackground()
{
}

/** Destrutor */
UIBackground::~UIBackground()
{
}

void UIBackground::setBorderColor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    borderColor.r = r;
    borderColor.g = g;
    borderColor.b = b;
}

/** Aplica o efeito visual*/
void UIBackground::apply(const GBF::Point & point, const GBF::Dimension & dimension)
{
    this->dimension = dimension;
    this->point = point;
}

} // namespace UserInterface::Look

} // namespace UserInterface
