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

#ifndef _UICOMPONENT_H
#define _UICOMPONENT_H

#include "Language.h"
#include "WriteManager.h"
#include "GBF.h"

namespace UserInterface
{

class UIComponent
{
    public:
        UIComponent();

        virtual ~UIComponent();


    protected:
        static GBF::Kernel::Write::Language * text;

        static GBF::Kernel::Write::WriteManager * writeManager;


    public:
        //Posicao do Componente na Tela
        virtual void setPosition(int x, int y);

        GBF::Dimension getDimension();

        //Executa o componente (atualizando,desenhando)
        virtual void execute();


    protected:
        //Desenha os componentes visuais
        virtual void draw() = 0;

        //atualiza as informações do componente (posicao, dimensao, estado)
        virtual void update();

        GBF::Point position;

        GBF::Dimension dimension;

};

} // namespace UserInterface

#endif
