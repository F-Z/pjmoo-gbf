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

#include "ImageBase.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

/** Construtor */
ImageBase::ImageBase()
{
    image = NULL;
}
/** Destrutor */
ImageBase::~ImageBase()
{
    if (image != NULL){
        SDL_FreeSurface(image);
        //UtilLog::getInstance()->status("Removendo Surfaces");
    }
}
/** Seta nível de transparência  */
void ImageBase::setAlpha(Uint8 ALPHA)
{
    SDL_SetAlpha(image, SDL_SRCALPHA, ALPHA);
}
/** Seta cor transparente */
void ImageBase::setColorKey(Uint8 R, Uint8 G, Uint8 B)
{
    SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(image->format, R, G, B));
}
double ImageBase::getTimer()
{
    return time;
}
GBF::Area ImageBase::getTamanho()
{
    return tamanho;
}
double ImageBase::time = 0.0f;

/** Converte Surface para formato na inicialização do GraphicSystem */
void ImageBase::converterSurface()
{
    SDL_Surface *tmp = SDL_DisplayFormat(image);
    SDL_FreeSurface(image);
    image = tmp;
}
void ImageBase::setGraphicSystemScreen(Screen * screen)
{
    ImageBase::screen = screen;
}

void ImageBase::setTimer(double time)
{
    ImageBase::time = time;
}

Screen * ImageBase::screen;


} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
