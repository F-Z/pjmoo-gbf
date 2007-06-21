#ifndef _GBF_DEFINE_H
#define _GBF_DEFINE_H

//SDL
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


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

//Estrutura para posicionamento na tela
struct Ponto
{
    int x;

    int y;

};
//Estrutura para representar dimensões
struct Dimensao
{
    int w;

    int h;

};
//Estrutura para definição de cor
typedef Uint32 Cor;
//Estrutura para definição de paleta de cor.
//Obs.: Representa um dos canais de cor (RGB)
typedef Uint8 CorPaleta;
//Estrutura para posicionamento virtual na tela
struct PontoVirtual
{
    float x;

    float y;

};
#endif
