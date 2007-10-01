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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "Sprite.h"

//Depreciado - observar para remover classe - utilize agora apenas Sprite ou SpritePersonagem
class SpriteItem : public Sprite
{
  public:
    //Destrutor 
    virtual ~SpriteItem();

    //Depreciado - observar para remover metodo
    virtual void desenhar(int x, int y);

    //Construtor 
    SpriteItem();

};
#endif
