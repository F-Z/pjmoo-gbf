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

#include "SpriteInterface.h"

//Destrutor
SpriteInterface::~SpriteInterface() 
{

}
void SpriteInterface::criar(int left, int top, int largura, int altura, GraphicSystemImageBuffer * gsiBuffer) 
{
    tamanho.w = largura;
    tamanho.h = altura;
    tamanho.x = left;
    tamanho.y = top;

    quadro = tamanho;
    imagem = gsiBuffer;
}
//Construtor
SpriteInterface::SpriteInterface() 
{
    automatico = false;

    frameAtual     = 0;
    frameTotal     = 0;
    frameRate      = 0;
    frameRateAtual = 0;
}
