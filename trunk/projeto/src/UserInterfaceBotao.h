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

#ifndef _USERINTERFACEBOTAO_H
#define _USERINTERFACEBOTAO_H

#include "UserInterfaceComponente.h"
#include <string>

#include "UserInterfaceObjetoTexto.h"

class UserInterfaceBotao : public UserInterfaceComponente
{
  public:
    UserInterfaceBotao(std::string fonte, std::string chaveTexto, const SDLKey & tecla);

    virtual ~UserInterfaceBotao();

    //Retorna a tecla correspondente ao botão
    SDLKey getTecla();


  protected:
    SDLKey tecla;

    UserInterfaceObjetoTexto botao;

    //Desenha os componentes visuais
    virtual void desenhar();

    //atualiza as informações do componente (posicao, dimensao, estado)
    void atualizar();

};
#endif
