////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
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

#ifndef _GAT_H
#define _GAT_H

#include "GATMaquinaEstadoGeral.h"
#include "GATMaquinaEstadoTopGaleria.h"
#include "GATMaquinaEstadoMenu.h"
#include "GATMaquinaEstadoJogo.h"
#include "UserInterfaceRecorde.h"
#include "GBF.h"
#include "TopSystemGaleria.h"
#include "UserInterfaceMenuAbstract.h"
#include "TimerSystemCronometroCrescente.h"

class GAT : public GATMaquinaEstadoGeral, public GATMaquinaEstadoTopGaleria, public GATMaquinaEstadoMenu, public GATMaquinaEstadoJogo
{
  protected:
    UserInterfaceRecorde * uiRecordeNovo;

    GBF * frameworkGBF;

    TopSystemGaleria * tsGaleria;

    UserInterfaceMenuAbstract * uiMenuPrincipal;

    TimerSystemCronometroCrescente tempoInativo;


  private:
    bool looping;

    bool fullscreen;


  public:
    GAT(int argc, char * argv[]);

    virtual ~GAT();

    bool isFullScreen();

    void executar();

    virtual void interpretadorGlobal();


  private:
    void escutar();


  protected:
    bool setMenu();

    bool setJogo();

    bool setTopGaleria();


  private:
    void menu();

    void jogo();

    void topGaleria();

    void sair();


};
#endif
