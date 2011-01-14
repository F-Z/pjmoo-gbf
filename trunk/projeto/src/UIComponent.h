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
#ifndef _UICOMPONENT_H
#define _UICOMPONENT_H

#include "Language.h"
#include "WriteManager.h"
#include "GBF.h"

namespace UserInterface {

class UIComponent
{
    public:
        /** Construtor */
        UIComponent();

        /** Destrutor */
        virtual ~UIComponent();

        /** Posição do componente */
        virtual void setPoint(int x, int y);

        /** Retorna a Dimensão (altura e largura) do componente */
        GBF::Dimension getDimension();

        /** Executa o componente (update e draw) */
        virtual void execute();


    protected:
        /** Desenha os componentes visuais */
        virtual void draw() = 0;

        /** atualiza as informações do componente (posicao, dimensão, estado) */
        virtual void update();

        /** Posição (x e y) do componente */
        GBF::Point point;

        /** Dimensão (largura e altura) do componente */
        GBF::Dimension dimension;

        /** Referência para o gerenciador de idioma */
        static GBF::Kernel::Write::Language * language;

        /** Referência para o gerenciador de escrita */
        static GBF::Kernel::Write::WriteManager * writeManager;

};

} // namespace UserInterface

#endif
