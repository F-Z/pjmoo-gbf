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
#ifndef _UIWINDOWTITLE_H
#define _UIWINDOWTITLE_H

#include "UIText.h"
#include "UIWindowDialog.h"

namespace UserInterface {

namespace Window {

class UIWindowTitle : public UIWindowDialog
{
    public:

        /** Construtor */
        UIWindowTitle();

        /** Destrutor */
        virtual ~UIWindowTitle();

        /** Inicializa as configurações da caixa de texto */
        virtual void initialize();

        UserInterface::Text::UIText title;

    protected:

        virtual void drawContent();

};

} // namespace UserInterface::Window

} // namespace UserInterface

#endif
