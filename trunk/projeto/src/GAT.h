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

#include "GTEstadoGeral.h"
#include "GTTopGaleria.h"
#include "GTMenu.h"
#include "GTJogo.h"
#include "GBFramework.h"
#include "UIWindowRecorde.h"
#include "RSManager.h"
#include "UIMenuAbstract.h"
#include "CronometroCrescente.h"

namespace GAT {

class GAT : public GTEstadoGeral, public GTTopGaleria, public GTMenu, public GTJogo
{
  protected:
    GBF::GBFramework * frameworkGBF;

    UserInterface::Window::UIWindowRecorde * uiRecordeNovo;

    RankingSystem::RSManager * recordeManager;

    UserInterface::Menu::UIMenuAbstract * uiMenuPrincipal;

    GBF::Kernel::Timer::CronometroCrescente tempoInativo;


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

} // namespace GAT
#endif
