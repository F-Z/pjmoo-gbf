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

#ifndef _UITEXTFIELD_H
#define _UITEXTFIELD_H

#include "UIField.h"
#include <string>


namespace UserInterface {

namespace Component {

class UITextField : public UIField
{
    public:
        UITextField();

        virtual ~UITextField();

        void setValue(std::string value);


    protected:
        void drawContent();


    private:
        std::string value;

};

} // namespace UserInterface::Componente

} // namespace UserInterface
#endif
