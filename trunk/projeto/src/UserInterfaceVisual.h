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

#ifndef _USERINTERFACEVISUAL_H
#define _USERINTERFACEVISUAL_H

#include "GBF_define.h"
#include "UtilColor.h"
#include "GraphicSystemGFX.h"

class UserInterfaceVisual
{
  public:
    UserInterfaceVisual();

    UserInterfaceVisual(const UserInterfaceVisual & base);

    virtual ~UserInterfaceVisual();

    void setCorBorda(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b);

    //Aplica o efeito visual
    virtual void aplicar(const Ponto & posicao, const Dimensao & dimensao);

    //Desenha o EstiloVisual do Componente
    virtual void desenhar() = 0;

    virtual UserInterfaceVisual * clone() = 0;


  protected:
    RGB corBorda;

    Ponto posicao;

    Dimensao dimensao;

    static GraphicSystemGFX * gsGFX;

};
#endif
