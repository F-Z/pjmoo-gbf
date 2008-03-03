#ifndef _FRAMELAYERMUNDO_H
#define _FRAMELAYERMUNDO_H

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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "GBF_define.h"

class FrameLayerMundo
{
  public:
    //Destrutor
    virtual ~FrameLayerMundo();

    Dimensao getPixelTile();

    int getPixelTileHorizontal();

    int getPixelTileVertical();

    Dimensao getPixelVisivel();

    int getPixelVisivelHorizontal();

    int getPixelVisivelVertical();

    Dimensao getTiles();

    int getTilesHorizontal();

    int getTilesVertical();

    void setPixelTile(int largura, int altura);

    void setPixelVisivel(int largura, int altura);

    void setTiles(int largura, int altura);


  private:
    Dimensao areaVisivel;

    Dimensao quantidadeTiles;

    Dimensao tile;

    //Construtor
    FrameLayerMundo();

  friend class FrameLayer;
};
#endif
