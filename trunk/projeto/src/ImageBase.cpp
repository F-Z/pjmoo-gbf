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

#include "ImageBase.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Construtor
ImageBase::ImageBase() 
{
    imagem=NULL;

}
//Destrutor
ImageBase::~ImageBase() 
{
    if (imagem!=NULL){
        SDL_FreeSurface(imagem);
        //UtilLog::getInstance()->status("Removendo Surfaces");
    }
}
//Seta nível de transparência 
void ImageBase::setAlpha(Uint8 ALPHA) 
{
    SDL_SetAlpha(imagem,SDL_SRCALPHA,ALPHA);
}
//Seta cor transparente
void ImageBase::setColorKey(Uint8 R, Uint8 G, Uint8 B) 
{
    SDL_SetColorKey(imagem,SDL_SRCCOLORKEY,SDL_MapRGB(imagem->format,R,G,B));
}
double ImageBase::getTimer() 
{
    return time;
}
SDL_Rect ImageBase::getTamanho() 
{
    return tamanho;
}
double ImageBase::time=0.0f;

//Converte Surface para formato na inicialização do GraphicSystem 
void ImageBase::converterSurface() 
{
    SDL_Surface *tmp = SDL_DisplayFormat(imagem);
    SDL_FreeSurface(imagem);
    imagem=tmp;
}
void ImageBase::setGraphicSystemScreen(Screen * screen)
{
    gsScreen = screen;
}

void ImageBase::setTimer(double TEMPO)
{
    time=TEMPO;
}

Screen * ImageBase::gsScreen;


} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
