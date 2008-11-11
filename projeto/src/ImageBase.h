#ifndef _IMAGEBASE_H
#define _IMAGEBASE_H

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
    //Construtor
    ImageBase();

    //Destrutor
    virtual ~ImageBase();

    //Seta nível de transparência 
    void setAlpha(Uint8 ALPHA);

    //Seta cor transparente
    void setColorKey(Uint8 R, Uint8 G, Uint8 B);

    virtual bool carregarArquivo(std::string arquivo) = 0;

    double getTimer();

    SDL_Rect getTamanho();


  protected:
    SDL_Surface * imagem;

    static double time;

    SDL_Rect tamanho;

    SDL_Rect posicao;

    //Converte Surface para formato na inicialização do GraphicSystem 
    virtual void converterSurface();


  public:
    static void setGraphicSystemScreen(Screen * screen);


  private:
    static void setTimer(double TEMPO);


  protected:
    static Screen * gsScreen;

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
