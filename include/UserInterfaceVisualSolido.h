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

#ifndef _USERINTERFACEVISUALSOLIDO_H
#define _USERINTERFACEVISUALSOLIDO_H

#include "UserInterfaceVisual.h"
#include "GBF_define.h"
#include "UtilColor.h"

class UserInterfaceVisualSolido : public UserInterfaceVisual
{
  public:
    //Construtor
    UserInterfaceVisualSolido();

    //Destrutor
    virtual ~UserInterfaceVisualSolido();

    void setCorFundo(const CorPaleta & r, const CorPaleta & g, const CorPaleta & b);

    //Desenha o EstiloVisual do Componente
    virtual void desenhar();

    //Retorna uma copia do objeto
    virtual UserInterfaceVisual * clone();


  protected:
    RGB corFundo;

};
#endif
