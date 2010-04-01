/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _GTESTADOGERAL_H
#define _GTESTADOGERAL_H

#include "GTTime.h"

namespace GAT {

enum State {
  GAT_EG_INICIO=0,
  GAT_EG_MENU=10,
  GAT_EG_APRESENTACAO=20,
  GAT_EG_JOGO=30,
  GAT_EG_TOPGALERIA=40,
  GAT_EG_SAIR=60
};

class GTState : public GTTime
{
  private:
    State estado;

  public:
    //Construtor
    GTState();

    //Destrutor
    virtual ~GTState();

    State processarEstadoGeral();


  protected:
    virtual bool setMenu();

    void setApresentacao();

    virtual bool setJogo();

    virtual bool setTopGaleria();

    void setSair();

    //Inicializa os recursos utilizados no jogo.
    //Ex.: Imagens, sons, fontes, configura��o do modo gr�fico e etc..
    virtual void inicializarRecursos() = 0;

    virtual void menu() = 0;

    virtual void apresentacao() = 0;

    virtual void jogo() = 0;

    virtual void topGaleria() = 0;

    virtual void sair() = 0;

    virtual void gatilhoMenu();

    virtual void gatilhoApresentacao();

    virtual void gatilhoJogo();

    virtual void gatilhoTopGaleria();

    virtual void gatilhoSair();


  private:
    void setInicio();


};

} // namespace GAT
#endif
