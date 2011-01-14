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
#ifndef _UINUMBERFIELD_H
#define _UINUMBERFIELD_H

#include "UIField.h"

namespace UserInterface {

namespace Component {

class UINumberField : public UIField
{
    public:
        UINumberField();

        virtual ~UINumberField();

        void setValue(unsigned int value);


    protected:
        void drawContent();


    private:
        unsigned int value;

};

} // namespace UserInterface::Componente

} // namespace UserInterface
#endif
