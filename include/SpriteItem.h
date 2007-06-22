#ifndef _SPRITEITEM_H
#define _SPRITEITEM_H

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

#include "SpriteAbstract.h"
#include "GBF_define.h"

class SpriteItem : public SpriteAbstract
{
  public:
    //Destrutor 
    virtual ~SpriteItem();

    void setPosicao(Ponto ponto);

    virtual void desenhar(int x, int y);

    //Construtor 
    SpriteItem();

};
#endif
