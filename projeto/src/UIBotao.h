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

#ifndef _UIBOTAO_H
#define _UIBOTAO_H

#include "UIComponent.h"
#include <string>

#include "UIText.h"

namespace UserInterface
{

namespace Componente
{

class UIBotao : public UserInterface::UIComponent
{
    public:
        UIBotao(std::string fonte, std::string chaveTexto, const SDLKey & tecla);

        virtual ~UIBotao();

        //Retorna a tecla correspondente ao botão
        SDLKey getTecla();


    protected:
        SDLKey tecla;

        UserInterface::Text::UIText botao;

        //Desenha os componentes visuais
        virtual void draw();

};

} // namespace UserInterface::Componente

} // namespace UserInterface

#endif
