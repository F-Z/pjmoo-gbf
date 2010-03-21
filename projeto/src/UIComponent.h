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

        /** Posicao do Componente na Tela */
        virtual void setPoint(int x, int y);

        GBF::Dimension getDimension();

        /** Executa o componente (atualizando,desenhando) */
        virtual void execute();


    protected:
        /** Desenha os componentes visuais */
        virtual void draw() = 0;

        /** atualiza as informações do componente (posicao, dimensao, estado) */
        virtual void update();

        GBF::Point point;

        GBF::Dimension dimension;

        static GBF::Kernel::Write::Language * language;

        static GBF::Kernel::Write::WriteManager * writeManager;

};

} // namespace UserInterface

#endif
