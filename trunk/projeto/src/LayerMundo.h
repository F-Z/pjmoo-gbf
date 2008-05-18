#ifndef _LAYERMUNDO_H
#define _LAYERMUNDO_H

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

#include "GBF.h"

namespace GBF {

namespace Imagem {

namespace Layer {

class LayerMundo
{
  public:
    //Destrutor
    virtual ~LayerMundo();

    GBF::Dimensao getPixelTile();

    int getPixelTileHorizontal();

    int getPixelTileVertical();

    GBF::Dimensao getPixelVisivel();

    int getPixelVisivelHorizontal();

    int getPixelVisivelVertical();

    GBF::Dimensao getTiles();

    int getTilesHorizontal();

    int getTilesVertical();

    void setPixelTile(int largura, int altura);

    void setPixelVisivel(int largura, int altura);

    void setTiles(int largura, int altura);


  private:
    GBF::Dimensao areaVisivel;

    GBF::Dimensao quantidadeTiles;

    GBF::Dimensao tile;

    //Construtor
    LayerMundo();

  friend class FrameLayer;
};

} // namespace GBF::Imagem::Layer

} // namespace GBF::Imagem

} // namespace GBF
#endif
