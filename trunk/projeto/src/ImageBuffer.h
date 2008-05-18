#ifndef _IMAGEBUFFER_H
#define _IMAGEBUFFER_H

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
#include <string>

#include "GBF.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class ImageBuffer : public ImageBase
{
  public:
    //Construtor
    ImageBuffer();

    //Destrutor
    virtual ~ImageBuffer();

    virtual bool carregarArquivo(std::string arquivo);

    //Desenha um sprite simples na tela 
    void desenhar(GBF::Ponto POSICAO);

    //Permite desenhar sprites animados  
    void desenhar(SDL_Rect POSICAO, SDL_Rect TAMANHO, int FRAME);

    //Permite desenhar sprites animados com corte 
    void desenhar(SDL_Rect POSICAO, SDL_Rect TAMANHO, int FRAME, SDL_Rect CORTE);

  friend class ImageBufferManager;
};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
