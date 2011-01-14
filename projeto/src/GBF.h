/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
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

/** Representação do framework */
namespace GBF {

/** Estrutura para representar um ponto na tela */
struct Point
{
    int x;

    int y;

};

/** Estrutura para representar dimensões */
struct Dimension
{
    int w;

    int h;

};

/** Estrutura para representar um ponto (precisão flutuante) na tela */
struct PointFloat
{
    float x;

    float y;

};

/** Definição de uma Área Virtual */
struct Area
{
    /** Representa um ponto no eixo y*/
    int top;

    /** Representa um ponto no eixo x*/
    int left;

    /** Representa um ponto no eixo y + altura*/
    int bottom;

    /** Representa um ponto no eixo x + largura*/
    int right;

};


} // namespace GBF

#endif
