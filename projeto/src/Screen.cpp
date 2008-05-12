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

#include "Screen.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Destrutor
Screen::~Screen() 
{
//    UtilLog::subSistema("Removendo GraphicSystemScreen");
}
//Desenha uma surface na surface de vídeo
void Screen::blitSurface(SDL_Surface * origem, SDL_Rect * area, SDL_Rect * posicao) 
{
    SDL_BlitSurface(origem, area , pScreen, posicao);
}
//Retorna ponteiro para a surface de vídeo 
SDL_Surface * Screen::getScreen() 
{
    return pScreen;
}
//Trava a surface para desenhar
bool Screen::travar() 
{
    if (SDL_MUSTLOCK(pScreen)) {
        if (SDL_LockSurface(pScreen)<0) {
            return false;
        }
    }
    return true;
}
//Destrava a surface para desenhar
void Screen::destravar() 
{
    if (SDL_MUSTLOCK(pScreen)) {
        SDL_UnlockSurface(pScreen);
    }
}
//Construtor 
Screen::Screen() 
{
//    UtilLog::subSistema("Instanciando GraphicSystemScreen");
}
//Informa qual a surface a ser usada e a configuração
void Screen::setScreen(SDL_Surface * surface) 
{
    pScreen = surface;
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
