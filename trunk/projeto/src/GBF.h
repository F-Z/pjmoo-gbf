#ifndef _GBF_H
#define _GBF_H

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

namespace GBF {

//Estrutura para posicionamento na tela
struct Point
{
    int x;

    int y;

};
//Estrutura para representar dimensões
struct Dimension
{
    int w;

    int h;

};
//Estrutura para posicionamento virtual na tela
struct PointFloat
{
    float x;

    float y;

};
//Definição de area
struct Area
{
    int top;

    int left;

    int bottom;

    int right;

};

} // namespace GBF
#endif
