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

#ifndef _USERINTERFACECOMPONENTE_H
#define _USERINTERFACECOMPONENTE_H

#include "WriteSystemManager.h"
#include "UserInterfaceTexto.h"
#include "GBF_define.h"

class UserInterfaceComponente
{
  public:
    UserInterfaceComponente();

    virtual ~UserInterfaceComponente();


  protected:
    static WriteSystemManager * wsManager;

    static UserInterfaceTexto * uiTexto;

    Ponto posicao;

    Dimensao dimensao;


  public:
    //Posicao do Componente na Tela
    virtual void setPosicao(int x, int y);

    Dimensao getDimensao();

    //Executa o componente (atualizando,desenhando)
    virtual void executar();


  protected:
    //Desenha os componentes visuais
    virtual void desenhar() = 0;

    //atualiza as informações do componente (posicao, dimensao, estado)
    virtual void atualizar();

};
#endif
