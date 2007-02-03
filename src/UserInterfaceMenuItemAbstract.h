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

#ifndef _USERINTERFACEMENUITEMABSTRACT_H
#define _USERINTERFACEMENUITEMABSTRACT_H

#include "GBF_define.h"

//Descrição: 
//    Classe para criação de itens de menus
//Motivação:
//    Fornecer uma interface padrão para criação de itens de menus
class UserInterfaceMenuItemAbstract
{
  private:
    bool ativo;


  public:
    UserInterfaceMenuItemAbstract();

    virtual ~UserInterfaceMenuItemAbstract();

    virtual void desenhar(int x, int y) = 0;

    void setAtivo(bool ativo);

    virtual int getQuantidadeLetras() = 0;

    virtual Dimensao getDimensaoLetra() = 0;


  protected:
    bool isAtivo();


};
#endif
