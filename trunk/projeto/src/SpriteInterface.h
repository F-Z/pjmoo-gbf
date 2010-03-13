#ifndef _SPRITEINTERFACE_H
#define _SPRITEINTERFACE_H

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

#include "ImageBuffer.h"
#include <SDL/SDL.h>

#include "Animacao.h"
#include "Object.h"

namespace GBF {

namespace Imagem {

class SpriteInterface : public GBF::Object
{
  public:
    //Destrutor
    virtual ~SpriteInterface();

    void criar(int left, int top, int largura, int altura, GBF::Kernel::Graphic::ImageBuffer * gsiBuffer);


  protected:
    //Construtor
    SpriteInterface();

    GBF::Kernel::Graphic::ImageBuffer * imagem;

    SDL_Rect posicao;

    SDL_Rect tamanho;


  public:
    GBF::Imagem::Sprite::Animacao animacao;

};

} // namespace GBF::Imagem

} // namespace GBF
#endif
