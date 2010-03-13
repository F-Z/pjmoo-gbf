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

#ifndef _UICOMPONENTE_H
#define _UICOMPONENTE_H

#include "Language.h"
#include "WriteManager.h"
#include "GBF.h"

namespace UserInterface {

class UIComponente
{
  public:
    UIComponente();

    virtual ~UIComponente();


  protected:
    static GBF::Kernel::Write::Language * uiTexto;

    static GBF::Kernel::Write::WriteManager * wsManager;


  public:
    //Posicao do Componente na Tela
    virtual void setPosicao(int x, int y);

    GBF::Dimensao getDimensao();

    //Executa o componente (atualizando,desenhando)
    virtual void executar();


  protected:
    //Desenha os componentes visuais
    virtual void desenhar() = 0;

    //atualiza as informações do componente (posicao, dimensao, estado)
    virtual void atualizar();

    GBF::Ponto posicao;

    GBF::Dimensao dimensao;

};

} // namespace UserInterface
#endif
