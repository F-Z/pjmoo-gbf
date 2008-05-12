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

#ifndef _GTMENU_H
#define _GTMENU_H

#include "GTMaquinaEstado.h"

namespace GAT {

enum EstadoMenu {
  GAT_EM_INICIO=0,
  GAT_EM_PRINCIPAL=10,
  GAT_EM_AJUDA=20,
  GAT_EM_CREDITO=30,
  GAT_EM_SOBRE=40,
  GAT_EM_CONFIGURACAO=50
};
class GTMenu : public GTMaquinaEstado
{
  private:
    EstadoMenu estado;


  public:
    //Construtor
    GTMenu();

    //Destrutor
    virtual ~GTMenu();

    EstadoMenu processarEstadoMenu();


  protected:
    void setMenuPrincipal();

    void setMenuAjuda();

    void setMenuCredito();

    void setMenuSobre();

    void setMenuConfiguracao();

    virtual void menuPrincipal() = 0;

    virtual void menuAjuda() = 0;

    virtual void menuCredito() = 0;

    virtual void menuSobre() = 0;

    virtual void menuConfiguracao();

    virtual void gatilhoMenuPrincipal();

    virtual void gatilhoMenuConfiguracao();

    void setMenuInicio();


};

} // namespace GAT
#endif
