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

#include "ImageBuffer.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Construtor
ImageBuffer::ImageBuffer()
{
}
//Destrutor
ImageBuffer::~ImageBuffer()
{
    //UtilLog::getInstance()->status("[GraphicSystemImageBuffer Removido(a)]");
}
bool ImageBuffer::loadFromFile(std::string arquivo)
{
    imagem = IMG_Load(arquivo.c_str());

    if (imagem){
        converterSurface();
        setColorKey(255,0,255);
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;

        return false;
    }
}
//Desenha um sprite simples na tela
void ImageBuffer::desenhar(GBF::Ponto POSICAO)
{
    SDL_Rect rect,pos;

    rect  = this->tamanho;
    pos.x = POSICAO.x;  pos.y = POSICAO.y;
    pos.w = 0;          pos.h = 0;

    gsScreen->blitSurface(imagem,&rect,&pos);
}
//Permite desenhar sprites animados
void ImageBuffer::desenhar(SDL_Rect POSICAO, SDL_Rect TAMANHO, int FRAME)
{
    SDL_Rect rect;

    rect.x=(TAMANHO.x) + (FRAME * TAMANHO.w);
    rect.y=TAMANHO.y;
    rect.h=TAMANHO.h;
    rect.w=TAMANHO.w;

    gsScreen->blitSurface(imagem,&rect,&POSICAO);
}
//Permite desenhar sprites animados com corte
void ImageBuffer::desenhar(SDL_Rect POSICAO, SDL_Rect TAMANHO, int FRAME, SDL_Rect CORTE)
{
    SDL_Rect rect;

    rect.x=(TAMANHO.x) + (FRAME * TAMANHO.w);
    rect.y=TAMANHO.y;
    rect.h=TAMANHO.h;
    rect.w=TAMANHO.w;

    if (CORTE.x>0){ rect.x+= CORTE.x; }
    if (CORTE.y>0){ rect.y = CORTE.y; }
    if (CORTE.w>0){ rect.w = CORTE.w; }
    if (CORTE.h>0){ rect.h = CORTE.h; }

    gsScreen->blitSurface(imagem,&rect,&POSICAO);
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
