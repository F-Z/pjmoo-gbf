#ifndef _SCREEN_H
#define _SCREEN_H

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

#include <SDL/SDL.h>


namespace GBF {

namespace Kernel {

namespace Graphic {

//Representação do Buffer de Vídeo

class Screen
{
  public:
    //Destrutor
    virtual ~Screen();

    //Desenha uma surface na surface de vídeo
    void blitSurface(SDL_Surface * origem, SDL_Rect * area, SDL_Rect * posicao);

    //Retorna ponteiro para a surface de vídeo 
    SDL_Surface * getScreen();

    //Trava a surface para desenhar
    bool travar();

    //Destrava a surface para desenhar
    void destravar();

    //Construtor 
    Screen();


  private:
    SDL_Surface * pScreen;


  public:
    //Informa qual a surface a ser usada e a configuração
    void setScreen(SDL_Surface * surface);

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
