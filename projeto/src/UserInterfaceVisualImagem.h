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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#ifndef _USERINTERFACEVISUALIMAGEM_H
#define _USERINTERFACEVISUALIMAGEM_H

#include "UserInterfaceVisual.h"
#include "GBF_define.h"
#include "FrameLayer.h"
#include "SpriteFactory.h"

enum UserInterfaceVisualTipoBackground {
  BACKGROUND_LINES=0,
  BACKGROUND_RINGS=1,
  BACKGROUND_CHESS=2,
  BAKCGROUND_SQUARE=3

};
class UserInterfaceVisualImagem : public UserInterfaceVisual
{
  public:
    //Construtor
    UserInterfaceVisualImagem();

    //Destrutor
    virtual ~UserInterfaceVisualImagem();

    //Aplica o efeito visual
    virtual void aplicar(const Ponto & posicao, const Dimensao & dimensao);

    //Desenha o EstiloVisual do Componente
    virtual void desenhar();

    //Retorna uma copia do objeto
    virtual UserInterfaceVisual * clone();

    //Define o estilo de background a ser utilizado
    void setTipoBackground(UserInterfaceVisualTipoBackground tipo);


  protected:
    FrameLayer * background;

    UserInterfaceVisualTipoBackground tipoBackground;

};
#endif
