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
#include "UIWindowTitle.h"

namespace UserInterface {

namespace Window {

UIWindowTitle::UIWindowTitle()
{
    title.setAlignment(Text::TEXT_CENTRAL);
}

UIWindowTitle::~UIWindowTitle()
{
}

void UIWindowTitle::drawContent()
{
    UIWindowDialog::drawContent();

    int posicaoTextoHorizontal = 0;
    int posicaoTextoVertical   = point.y + int(title.getLetterDimension().h * 0.2);

    if (title.getAlignment() == Text::TEXT_CENTRAL){
        int auxiliar = writeManager->getLineWidth(title.getFont(), title.getKeyText());
        posicaoTextoHorizontal = int (point.x + (dimension.w / 2) - (auxiliar / 2));
    } else {
        posicaoTextoHorizontal = point.x + title.getLetterDimension().w;
    }

    writeManager->writeKeyText(title.getFont(), posicaoTextoHorizontal, posicaoTextoVertical, title.getKeyText());

}

/** Inicializa as configurações da caixa de texto */
void UIWindowTitle::initialize()
{
    UIWindowDialog::initialize();
    title.setLetterDimension(writeManager->getFont(title.getFont())->getDimension());
    espacoAntesTexto = int(title.getLetterDimension().h * title.STYLE_SINGLE_AND_HALF_LINE);
}

} // namespace UserInterface::Window

} // namespace UserInterface
