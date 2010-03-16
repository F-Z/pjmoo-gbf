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

#ifndef _UIWINDOWTITLE_H
#define _UIWINDOWTITLE_H

#include "UITexto.h"
#include "UIWindowDialog.h"

namespace UserInterface {

namespace Window {

class UIWindowTitle : public UIWindowDialog
{
  public:
    UIWindowTitle();

    virtual ~UIWindowTitle();


  protected:
    virtual void desenharConteudo();


  public:
    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    UserInterface::Texto::UITexto title;

};

} // namespace UserInterface::Window

} // namespace UserInterface
#endif
