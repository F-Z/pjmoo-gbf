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
#ifndef _UITEXT_H
#define _UITEXT_H

#include <string>

#include "GBF.h"

namespace UserInterface
{

namespace Text
{

enum UITextAlignment
{
    TEXT_NORMAL = 0,
    TEXT_CENTRAL = 1

};
//Texto Alinhado a esquerda
//Texto Alinhado ao Centro (Centralizado)

class UIText
{
    public:
        static const float STYLE_SINGLE_LINE;

        static const float STYLE_SINGLE_AND_HALF_LINE;

        static const float STYLE_DOUBLE_LINE;


    protected:
        float lineStyle;

        std::string font;

        std::string keyText;

        int lineSpace;


    public:
        //Construtor
        UIText();

        //Destrutor
        ~UIText();

        void setFont(std::string fonte);

        std::string getFont();

        void setKeyText(std::string keyText);

        std::string getKeyText();

        void setLetterDimension(const GBF::Dimension & dimension);

        GBF::Dimension getLetterDimension();

        //Informa o Estilo de entrelinhas a ser utilizado
        void setLineStyle(float style);

        //Retorna em pixel o espaçamento entre as linhas
        int getLineSpace();

        //Configura o Alinhamento do Texto
        void setAlignment(UITextAlignment alignment);

        //Retorna o alinhamento utilizado
        UITextAlignment getAlignment();


    protected:
        UITextAlignment alignment;

        GBF::Dimension letterDimension;

};

} // namespace UserInterface::Texto

} // namespace UserInterface

#endif
