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

#ifndef _UIBUTTON_H
#define _UIBUTTON_H

#include "UIComponent.h"
#include <string>

#include "UIText.h"

namespace UserInterface
{

namespace Component
{

class UIButton : public UserInterface::UIComponent
{
    public:
        UIButton(std::string font, std::string keyText, const SDLKey & tecla);

        virtual ~UIButton();

        //Retorna a tecla correspondente ao botão
        SDLKey getKey();


    protected:
        SDLKey key;

        UserInterface::Text::UIText button;

        //Desenha os componentes visuais
        virtual void draw();

};

} // namespace UserInterface::Componente

} // namespace UserInterface

#endif
