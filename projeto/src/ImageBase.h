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

#ifndef _IMAGEBASE_H
#define _IMAGEBASE_H

#include <string>

#include "Screen.h"
#include <SDL/SDL.h>

#include <iostream>


namespace GBF {

namespace Kernel {

namespace Graphic {

class ImageBase
{
    public:
        /** Construtor */
        ImageBase();

        /** Destrutor */
        virtual ~ImageBase();

        /** Seta nível de transparência */
        void setAlpha(Uint8 ALPHA);

        /** Seta cor transparente */
        void setColorKey(Uint8 R, Uint8 G, Uint8 B);

        virtual bool loadFromFile(std::string fileName) = 0;

        double getTimer();

        GBF::Area getTamanho();


    protected:
        SDL_Surface * image;

        static double time;

        GBF::Area tamanho;

        GBF::Point point;

        /** Converte Surface para formato na inicialização do GraphicSystem */
        virtual void convertSurface();


    public:
        static void setGraphicSystemScreen(Screen * screen);


    private:
        static void setTimer(double time);


    protected:
        static Screen * screen;

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
