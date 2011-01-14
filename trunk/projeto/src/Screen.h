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
#ifndef _SCREEN_H
#define _SCREEN_H

#include <SDL/SDL.h>
#include "GBF.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Representa��o do Buffer de V�deo

class Screen
{
  public:
    //Destrutor
    virtual ~Screen();

    //Desenha uma surface na surface de v�deo
    void blitSurface(SDL_Surface * origem, GBF::Point posicao);

    //Desenha uma surface na surface de v�deo
    void blitSurface(SDL_Surface * origem, GBF::Area area, GBF::Point posicao);

    //Retorna ponteiro para a surface de v�deo
    SDL_Surface * getScreen();

    //Trava a surface para desenhar
    bool lock();

    //Destrava a surface para desenhar
    void unlock();

    //Construtor
    Screen();


  private:
    SDL_Surface * pScreen;

    SDL_Rect toRect(GBF::Area area);

    SDL_Rect toRect(GBF::Point point);

  public:
    //Informa qual a surface a ser usada e a configura��o
    void setScreen(SDL_Surface * surface);

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
