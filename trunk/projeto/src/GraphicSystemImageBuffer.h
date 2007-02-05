#ifndef _GRAPHICSYSTEMIMAGEBUFFER_H
#define _GRAPHICSYSTEMIMAGEBUFFER_H

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
#include <string>

#include "GBF_define.h"

class GraphicSystemImageBuffer : public GraphicSystemImage
{
  public:
    //Construtor
    GraphicSystemImageBuffer();

    //Destrutor
    virtual ~GraphicSystemImageBuffer();

    virtual bool carregarArquivo(std::string arquivo);

    //Desenha um sprite simples na tela 
    void desenhar(Ponto POSICAO);

    //Permite desenhar sprites animados  
    void desenhar(SDL_Rect POSICAO, SDL_Rect TAMANHO, int FRAME);

    //Permite desenhar sprites animados com corte 
    void desenhar(SDL_Rect POSICAO, SDL_Rect TAMANHO, int FRAME, SDL_Rect CORTE);

  friend class GraphicSystemImageBufferManager;
};
#endif
