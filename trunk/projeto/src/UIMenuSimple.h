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
#ifndef _UIMENUSIMPLE_H
#define _UIMENUSIMPLE_H

#include "UIMenuSolid.h"

namespace UserInterface {

namespace Menu {

class UIMenuSimple : public UIMenuSolid
{
  public:
    //Construtor
    UIMenuSimple();

    //Destrutor
    virtual ~UIMenuSimple();


  protected:
    void draw();

};

} // namespace UserInterface::Menu

} // namespace UserInterface
#endif
