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
    //Construtor
    GAT(int argc, char * argv[]);

    //Destrutor
    virtual ~GAT();

    bool isFullScreen();

    void executar();

    virtual void interpretadorGlobal();


  private:
    void escutar();


  protected:
    //Apresentação do jogo
    virtual void apresentacao();

    //Tela para entrada de Novo Recorde
    virtual void topGaleriaNovo();

    //Tela para Salvar Novo Recorde
    virtual void topGaleriaSalvar();

    //Tela para Exibição dos Recordes
    virtual void topGaleriaExibir();

    bool setJogo();

    bool setMenu();

    bool setTopGaleria();


  private:
    void menu();

    void jogo();

    void topGaleria();

    void sair();


};
#endif
