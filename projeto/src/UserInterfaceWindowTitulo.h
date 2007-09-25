////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#ifndef _USERINTERFACEWINDOWTITULO_H
#define _USERINTERFACEWINDOWTITULO_H

#include "UserInterfaceWindow.h"
#include "UserInterfaceObjetoTexto.h"

class UserInterfaceWindowTitulo : public UserInterfaceWindow
{
  public:
    UserInterfaceWindowTitulo();

    virtual ~UserInterfaceWindowTitulo();


  protected:
    virtual void desenharConteudo();


  public:
    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    UserInterfaceObjetoTexto titulo;

};
#endif
