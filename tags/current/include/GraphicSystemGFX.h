#ifndef _GRAPHICSYSTEMGFX_H
#define _GRAPHICSYSTEMGFX_H

#include <math.h>

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

#include "GBF_define.h"
#include "GraphicSystemScreen.h"

class GraphicSystemGFX
{
  public:
    //Destrutor 
    virtual ~GraphicSystemGFX();

    //Seta a cor a ser usada (Usado normalmente para transformar código r,g,b em uma cor)
    void setColor(CorPaleta R, CorPaleta G, CorPaleta B);

    //Seta a cor a ser usada (Usar somente se a cor já estiver sido mapeada para RGB)
    void setColor(Cor cor);

    //Desenha um pixel na tela (Usando cor padrão selecionada)
    inline void putPixel(int x, int y);

    //Desenha um pixel na tela (Usado para cores em formado decimal)
    void putPixel(int x, int y, CorPaleta R, CorPaleta G, CorPaleta B);

    //Desenha um pixel na tela (Usado apenas se a cor já estiver em formato RGB)
    void putPixel(int x, int y, Cor cor);

    //Pegar a cor de um pixel na tela
    Cor getPixel(int x, int y);

    //Desenha uma linha na tela
    void linha(int XI, int YI, int XF, int YF);

    //Desenha um circulo
    void circulo(int X, int Y, int RAIO);

    //Desenha um circulo preenchido
    void circuloPreenchido(int X, int Y, int RAIO);

    //Desenha um retangulo
    void retangulo(int X, int Y, int W, int H);

    //Desenha um retangulo preenchido
    void retanguloPreenchido(int X, int Y, int W, int H);

    //Desenha cruzamentos com fechamento na parte superior (rever utilidade)
    void gradeSuperior(int X, int Y, int W, int H);

    //Desenha cruzamentos com fechamento na parte inferior (rever utilidade)
    void gradeInferior(int X, int Y, int W, int H);


  protected:
    //Inicializa informações básicas
    void inicializar();

    //Verifica se o ponto (x,y) está dentro dos limites 
    bool offSetLimite(int x, int y);

    SDL_Surface * pScreen;

    Cor color;


  private:
    static GraphicSystemScreen * gsScreen;

    static void setGraphicSystemScreen(GraphicSystemScreen * screen);

    //Construtor 
    GraphicSystemGFX();

    int bpp;

  friend class GraphicSystemCore;
  friend class GraphicSystem;

  public:
    //Realiza um lock na surface
    bool travar();

    //Realiza um unlock na surface
    void destravar();

};
//Desenha um pixel na tela (Usando cor padrão selecionada)
inline void GraphicSystemGFX::putPixel(int x, int y) 
{
    if (offSetLimite(x,y)){
        Uint8 *pixel = (Uint8 *)pScreen->pixels + y * pScreen->pitch + x * bpp;

        switch(bpp) {
            case 1:
                    *pixel = color;
                break;
            case 2:
                    *(Uint16 *)pixel = color;
                break;
            case 3:
                    if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                        pixel[0] = (color >> 16) & 0xff;
                        pixel[1] = (color >> 8) & 0xff;
                        pixel[2] = color & 0xff;
                    } else {
                        pixel[0] = color & 0xff;
                        pixel[1] = (color >> 8) & 0xff;
                        pixel[2] = (color >> 16) & 0xff;
                    }
                break;
            case 4:
                    *(Uint32 *)pixel = color;
                break;
        }
    }
}
#endif
