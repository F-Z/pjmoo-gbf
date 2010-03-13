////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#ifndef _COR_H
#define _COR_H

#include <math.h>

#include <SDL/SDL.h>


namespace GBF {

namespace Color {

//Estrutura para definição de cor
typedef Uint32 Cor;
//Estrutura para definição de paleta de cor.
//Obs.: Representa um dos canais de cor (RGB)
typedef Uint8 Pallete;
//Descrição:
//    Estrutura para representar cores no sistema RGB (Red, Green, Blue),  com
//    precisam de ponto flutuante.
//Motivo:
//    Usado para conversões entre sistemas de cores
struct RGBf
{
    float r;

    float g;

    float b;

};
//Descrição:
//    Estrutura para representar cores no sistema HSV (Hue,Saturation,Value).
//Motivação:
//    O sistema de cor HSV é mais próximo do entendimento humano
struct HSV
{
    float h;

    float s;

    float v;

};
//Descrição:
//    Estrutura para representar cores no sistema RGB (Red, Green, Blue).
//Motivação:
//    O sistema RGB é um sistema de cor nativo para computadores
struct RGB
{
    int r;

    int g;

    int b;

};
//Descrição:
//    Classe para conversão entre os sistemas de cores
//Motivação:
//     Converter cores de RGB para HSV
//     Converter cores de HSV para RGB
class Converter
{
  public:
    //Transforma de RGB para HSV
    static HSV forHSV(RGB cor);

    //Transforma de HSV para RGB
    static RGB forRGB(HSV cor);


  protected:
    //Retorna o menor valor
    static int menor(int valor1, int valor2);

    //Retorna o maior valor
    static int maior(int valor1, int valor2);

};

} // namespace GBF::Cor

} // namespace GBF
#endif
