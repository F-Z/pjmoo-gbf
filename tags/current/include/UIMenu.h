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

#ifndef _UIMENU_H
#define _UIMENU_H

#include "UIMenuAbstract.h"
#include "GraphicSystemUtility.h"

namespace UserInterface {

namespace Menu {

//Descrição: 
//    Implementação da Classe MenuAbstract
//Motivação:
//    Fornecer um classe básica para criação de menus em texto
class UIMenu : public UIMenuAbstract, public GBF::Kernel::Graphic::GraphicSystemUtility
{
  public:
    //Construtor
    UIMenu();

    //Destrutor
    virtual ~UIMenu();


  protected:
    void desenhar();

    virtual bool navegar();

    virtual void itemAvancar();

    virtual void itemAnterior();

};

} // namespace UserInterface::Menu

} // namespace UserInterface
#endif
