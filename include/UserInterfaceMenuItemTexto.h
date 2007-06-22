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

#ifndef _USERINTERFACEMENUITEMTEXTO_H
#define _USERINTERFACEMENUITEMTEXTO_H

#include <string>

#include "TimerSystemCronometroCrescente.h"
#include "WriteSystemManager.h"
#include "GBF_define.h"
#include "UserInterfaceMenuItemAbstract.h"

//Descrição: 
//    Implementação da Classe MenuItemAbstract
//Motivação:
//    Fornecer um classe básica para criação de itens de menus em texto
class UserInterfaceMenuItemTexto : public UserInterfaceMenuItemAbstract
{
  protected:
    std::string texto;

    std::string fonteTexto;

    TimerSystemCronometroCrescente tempo;

    static WriteSystemManager * wsManager;


  public:
    UserInterfaceMenuItemTexto(const std::string & texto, const std::string & fonteTexto);

    virtual ~UserInterfaceMenuItemTexto();

    virtual void desenhar(int x, int y);

    virtual int getQuantidadeLetras();

    virtual Dimensao getDimensaoLetra();

};
#endif
