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

#ifndef _UIITEMTEXTO_H
#define _UIITEMTEXTO_H

#include <string>

#include "CronometroCrescente.h"
#include "WriteManager.h"
#include "GBF_define.h"
#include "UIItemAbstract.h"

namespace UserInterface {

namespace Menu {

//Descrição: 
//    Implementação da Classe MenuItemAbstract
//Motivação:
//    Fornecer um classe básica para criação de itens de menus em texto
class UIItemTexto : public UIItemAbstract
{
  protected:
    std::string texto;

    std::string fonteTexto;

    GBF::Kernel::Timer::CronometroCrescente tempo;

    static GBF::Kernel::Write::WriteManager * wsManager;


  public:
    UIItemTexto(const std::string & texto, const std::string & fonteTexto);

    virtual ~UIItemTexto();

    virtual void desenhar(int x, int y);

    virtual int getQuantidadeLetras();

    virtual ::Dimensao getDimensaoLetra();

};

} // namespace UserInterface::Menu

} // namespace UserInterface
#endif
