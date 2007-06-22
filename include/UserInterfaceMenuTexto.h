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
////////////////////////////////////////////////////////////////////////

#ifndef _USERINTERFACEMENUTEXTO_H
#define _USERINTERFACEMENUTEXTO_H

#include "UserInterfaceMenuAbstract.h"
#include "InputSystem.h"
#include "GraphicSystemGFX.h"

//Descrição: 
//    Implementação da Classe MenuAbstract
//Motivação:
//    Fornecer um classe básica para criação de menus em texto
class UserInterfaceMenuTexto : public UserInterfaceMenuAbstract
{
  public:
    UserInterfaceMenuTexto(InputSystem * input);

    virtual ~UserInterfaceMenuTexto();


  protected:
    void desenhar();

    virtual bool navegar();

    virtual void itemAvancar();

    virtual void itemAnterior();

    GraphicSystemGFX * gsGFX;

};
#endif
