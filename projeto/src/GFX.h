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
#ifndef _GFX_H
#define _GFX_H

#include <iostream>
#include <math.h>
#include "Color.h"
#include "Screen.h"


namespace GBF {

namespace Kernel {

namespace Graphic {
/**
 * Classe para desenho de primitivas gr�ficas
 */
class GFX
{
    public:
        /** Realiza um lock na surface */
        bool lock();

        /** Realiza um unlock na surface */
        void unlock();

        /** Destrutor */
        virtual ~GFX();

        /** Seta a cor a ser usada (Usado normalmente para transformar c�digo r,g,b em uma cor) */
        void setColor(GBF::Color::Pallete R, GBF::Color::Pallete G, GBF::Color::Pallete B);

        /** Seta a cor a ser usada (Usar somente se a cor j� estiver sido mapeada para RGB) */
        void setColor(GBF::Color::Cor cor);

        /** Desenha um pixel na tela (Usando cor padr�o selecionada) */
        inline void putPixel(int x, int y);

        /** Desenha um pixel na tela (Usado para cores em formado decimal) */
        void putPixel(int x, int y, GBF::Color::Pallete R, GBF::Color::Pallete G, GBF::Color::Pallete B);

        /** Desenha um pixel na tela (Usado apenas se a cor j� estiver em formato RGB) */
        void putPixel(int x, int y, GBF::Color::Cor cor);

        /** Pegar a cor de um pixel na tela */
        GBF::Color::Cor getPixel(int x, int y);

        /** Desenha uma linha na tela */
        void line(int XI, int YI, int XF, int YF);

        /** Desenha um circulo */
        void circle(int x, int y, int radius);

        /** Desenha um circulo preenchido */
        void circleFill(int x, int y, int radius);

        /** Desenha um retangulo */
        void rectangle(int x, int y, int e, int h);

        /** Desenha um retangulo preenchido */
        void rectangleFill(int x, int y, int w, int h);

        /** Desenha cruzamentos com fechamento na parte superior (rever utilidade) */
        void gradeSuperior(int X, int Y, int W, int H);

        /** Desenha cruzamentos com fechamento na parte inferior (rever utilidade) */
        void gradeInferior(int X, int Y, int W, int H);

    protected:

        /** Inicializa informa��es b�sicas */
        void start();

        /** Verifica se o ponto (x,y) est� dentro dos limites */
        bool offSetLimite(int x, int y);

        SDL_Surface * pScreen;

        GBF::Color::Cor color;


    private:

        static Screen * gsScreen;

        static void setGraphicSystemScreen(Screen * screen);

        /** Construtor */
        GFX();

        int bpp;

        friend class GraphicCore;

        friend class GraphicSystem;
};

/** Desenha um pixel na tela (Usando cor padr�o selecionada) */
inline void GFX::putPixel(int x, int y)
{
    if (offSetLimite(x, y)){
        Uint8 *pixel = (Uint8 *)pScreen->pixels + y * pScreen->pitch + x * bpp;

        switch (bpp) {

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

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF

#endif
