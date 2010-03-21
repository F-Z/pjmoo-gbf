/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _GBF_H
#define _GBF_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/** Namespace para representação básica do framework */
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
