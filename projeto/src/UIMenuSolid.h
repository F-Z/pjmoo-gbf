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
#ifndef _UIMENUSOLID_H
#define _UIMENUSOLID_H

#include "UIMenuAbstract.h"
#include "GraphicSystemUtility.h"

namespace UserInterface {

namespace Menu {

//Descri��o:
//    Implementa��o da Classe MenuAbstract
//Motiva��o:
//    Fornecer um classe b�sica para cria��o de menus em texto
class UIMenuSolid : public UIMenuAbstract, public GBF::Kernel::Graphic::GraphicSystemUtility
{
  public:
    //Construtor
    UIMenuSolid();

    //Destrutor
    virtual ~UIMenuSolid();


  protected:
    void draw();

    virtual bool browse();

    virtual void next();

    virtual void previous();

};

} // namespace UserInterface::Menu

} // namespace UserInterface
#endif
