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

#include "GraphicSystemImage.h"

//Construtor
GraphicSystemImage::GraphicSystemImage() 
{
    imagem=NULL;

}
//Destrutor
GraphicSystemImage::~GraphicSystemImage() 
{
    if (imagem!=NULL){
        SDL_FreeSurface(imagem);
        //UtilLog::getInstance()->status("Removendo Surfaces");
    }
}
//Seta nível de transparência 
void GraphicSystemImage::setAlpha(Uint8 ALPHA) 
{
    SDL_SetAlpha(imagem,SDL_SRCALPHA,ALPHA);
}
//Seta cor transparente
void GraphicSystemImage::setColorKey(Uint8 R, Uint8 G, Uint8 B) 
{
    SDL_SetColorKey(imagem,SDL_SRCCOLORKEY,SDL_MapRGB(imagem->format,R,G,B));
}
double GraphicSystemImage::getTimer() 
{
    return time;
}
SDL_Rect GraphicSystemImage::getTamanho() 
{
    return tamanho;
}
double GraphicSystemImage::time=0.0f;

//Converte Surface para formato na inicialização do GraphicSystem 
void GraphicSystemImage::converterSurface() 
{
    SDL_Surface *tmp = SDL_DisplayFormat(imagem);
    SDL_FreeSurface(imagem);
    imagem=tmp;
}
void GraphicSystemImage::setGraphicSystemScreen(GraphicSystemScreen * screen)
{
    gsScreen = screen;
}

void GraphicSystemImage::setTimer(double TEMPO)
{
    time=TEMPO;
}

GraphicSystemScreen * GraphicSystemImage::gsScreen;

