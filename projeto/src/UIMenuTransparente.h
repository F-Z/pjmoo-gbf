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

#ifndef _UIMENUTRANSPARENTE_H
#define _UIMENUTRANSPARENTE_H

#include "UIMenuSolid.h"

namespace UserInterface {

namespace Menu {

class UIMenuTransparente : public UIMenuSolid
{
  public:
    //Construtor
    UIMenuTransparente();

    //Destrutor
    virtual ~UIMenuTransparente();


  protected:
    void desenhar();

};

} // namespace UserInterface::Menu

} // namespace UserInterface
#endif
