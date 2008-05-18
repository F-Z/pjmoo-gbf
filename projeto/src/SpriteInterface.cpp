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

#include "SpriteInterface.h"

namespace GBF {

namespace Imagem {

//Destrutor
SpriteInterface::~SpriteInterface() 
{

}
void SpriteInterface::criar(int left, int top, int largura, int altura, GBF::Kernel::Graphic::ImageBuffer * gsiBuffer) 
{
    tamanho.w = largura;
    tamanho.h = altura;
    tamanho.x = left;
    tamanho.y = top;

    imagem = gsiBuffer;

    animacao.setDimensaoFrame(tamanho);
}
//Construtor
SpriteInterface::SpriteInterface() 
{
}

} // namespace GBF::Imagem

} // namespace GBF
