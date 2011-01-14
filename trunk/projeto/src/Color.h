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
#ifndef _COLOR_H
#define _COLOR_H

#include <math.h>

#include <SDL/SDL.h>


namespace GBF {


/** Representação do sistema de cor */

namespace Color {

/** Estrutura para definição de cor */
typedef Uint32 Cor;

/** Estrutura para definição de paleta de cor.
 Representa um dos canais de cor (RGB) */
typedef Uint8 Pallete;

/** Estrutura para representar cores no sistema RGB (Red, Green, Blue),  com
    precisam de ponto flutuante.
    Usado para conversões entre sistemas de cores */

struct RGBf
{
    float r;

    float g;

    float b;
};

/** Estrutura para representar cores no sistema HSV (Hue,Saturation,Value).
O sistema de cor HSV é mais próximo do entendimento humano */

struct HSV
{
    float h;

    float s;

    float v;


};

/** Estrutura para representar cores no sistema RGB (Red, Green, Blue).
O sistema RGB é um sistema de cor nativo para computadores */

struct RGB
{
    int r;

    int g;

    int b;

};

/** Classe para conversão entre os sistemas de cores */

class Converter
{

    public:
        /** Transforma de RGB para HSV */
        static HSV forHSV(RGB cor);

        /** Transforma de HSV para RGB */
        static RGB forRGB(HSV cor);


    protected:
        /** Retorna o menor valor */
        static int menor(int valor1, int valor2);

        /** Retorna o maior valor */
        static int maior(int valor1, int valor2);

};

} // namespace GBF::Color

} // namespace GBF

#endif
