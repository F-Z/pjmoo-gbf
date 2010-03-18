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

#include "UIText.h"

namespace UserInterface
{

namespace Text
{

const float UIText::STYLE_SINGLE_LINE = 1.0;

const float UIText::STYLE_SINGLE_AND_HALF_LINE = 1.5;

const float UIText::STYLE_DOUBLE_LINE = 2.0;

//Construtor

//Construtor
UIText::UIText()
{
    lineStyle = STYLE_SINGLE_AND_HALF_LINE;
    alignment = TEXT_NORMAL;
}

//Destrutor

//Destrutor
UIText::~UIText()
{
}

void UIText::setFont(std::string font)
{
    this->font = font;

//    dimensaoLetra=wsManager->getFonte(fonte)->getDimensao();
//    espacoEntreLinhas=int(dimensaoLetra.w*estiloEntreLinhas);
}

std::string UIText::getFont()
{
    return font;
}

void UIText::setKeyText(std::string keyText)
{
    this->keyText = keyText;
}

std::string UIText::getKeyText()
{
    return keyText;
}

void UIText::setLetterDimension(const GBF::Dimension & dimension)
{
    letterDimension = dimension;
    lineSpace = int(letterDimension.w * lineStyle);
}

GBF::Dimension UIText::getLetterDimension()
{
    return letterDimension;
}

//Informa o Estilo de entrelinhas a ser utilizado

//Informa o Estilo de entrelinhas a ser utilizado
void UIText::setLineStyle(float style)
{
    if ((style == STYLE_SINGLE_LINE) || (style == STYLE_SINGLE_AND_HALF_LINE) ||
        (style == STYLE_DOUBLE_LINE)) {

            lineStyle = style;
    }
}

//Retorna em pixel o espaçamento entre as linhas

//Retorna em pixel o espaçamento entre as linhas
int UIText::getLineSpace()
{
    return lineSpace;
}

//Configura o Alinhamento do Texto

//Configura o Alinhamento do Texto
void UIText::setAlignment(UITextAlignment alignment)
{
    this->alignment = alignment;
}

//Retorna o alinhamento utilizado

//Retorna o alinhamento utilizado
UITextAlignment UIText::getAlignment()
{
    return alignment;
}

} // namespace UserInterface::Text

} // namespace UserInterface
