#ifndef _SPRITECHARACTER_H
#define _SPRITECHARACTER_H

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

namespace GBF {

namespace Imagem {

namespace Sprite {

class SpriteCharacter : public Sprite
{
  public:
    //Destrutor
    virtual ~SpriteCharacter();

    void setDirection(Direcao DIR);

    void setQtdDirecoes(int QTD);

    virtual void desenhar(int x, int y);

    //Retorna a quantidade de direções que o personagem possui
    int getQtdDirecoes();

    Direcao getDirection();

    //Construtor
    SpriteCharacter();


  protected:
    Direcao direction;

    int qtdDirecao;

};

} // namespace GBF::Imagem::Sprite

} // namespace GBF::Imagem

} // namespace GBF
#endif
