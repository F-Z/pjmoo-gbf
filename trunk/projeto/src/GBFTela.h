#ifndef _GBFTELA_H
#define _GBFTELA_H

////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
////    
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////    
////    David Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "UserInterfaceRecorde.h"

class GBFTela {
  public:
    virtual ~GBFTela();

    GBFTela();


  protected:
    // Telas Principais 
    //* Tela de Introducao do jogo
    virtual void telaIntroducao() = 0;

    //* Tela de Menu 
    virtual void telaMenu() = 0;

    //* Tela de Sobre
    virtual void telaSobre() = 0;

    //* Tela de Ajuda
    virtual void telaAjuda() = 0;

    //* Tela de Agradecimentos a Equipe Técnica
    virtual void telaCredito() = 0;

    //* Tela de TOP 10, Recordes 
    virtual void telaTopRecorde();

    //* Tela de TOP 10, Recorde Novo 
    virtual void telaTopRecordeNovo();

    //* Tela de Configurações 
    virtual void telaConfigurar();

    virtual void telaSair();

    UserInterfaceRecorde * uiRecordeNovo;

};
#endif
