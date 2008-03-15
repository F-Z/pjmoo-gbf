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

#ifndef _GATMAQUINAESTADOMENU_H
#define _GATMAQUINAESTADOMENU_H

#include "GATMaquinaEstado.h"

enum GATEstadoMenu {
  GAT_EM_INICIO=0,
  GAT_EM_PRINCIPAL=10,
  GAT_EM_AJUDA=20,
  GAT_EM_CREDITO=30,
  GAT_EM_SOBRE=40,
  GAT_EM_CONFIGURACAO=50
};
class GATMaquinaEstadoMenu : public GATMaquinaEstado
{
  private:
    GATEstadoMenu estado;


  public:
    //Construtor
    GATMaquinaEstadoMenu();

    //Destrutor
    virtual ~GATMaquinaEstadoMenu();

    GATEstadoMenu processarEstadoMenu();


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
#endif
