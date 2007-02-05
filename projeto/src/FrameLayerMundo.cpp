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

#include "FrameLayerMundo.h"

//Destrutor
FrameLayerMundo::~FrameLayerMundo() 
{
}
//Construtor
FrameLayerMundo::FrameLayerMundo() 
{
}
void FrameLayerMundo::setTiles(int largura, int altura) 
{
    quantidadeTiles.w=largura;
    quantidadeTiles.h=altura;
}
Dimensao FrameLayerMundo::getTiles() 
{
    return quantidadeTiles;
}
int FrameLayerMundo::getTilesHorizontal() 
{
    return quantidadeTiles.w;
}
int FrameLayerMundo::getTilesVertical() 
{
    return quantidadeTiles.h;
}
void FrameLayerMundo::setPixelTile(int largura, int altura) 
{
    tile.w=largura;
    tile.h=altura;
}
Dimensao FrameLayerMundo::getPixelTile() 
{
    return tile;
}
int FrameLayerMundo::getPixelTileHorizontal() 
{
    return tile.w;
}
int FrameLayerMundo::getPixelTileVertical() 
{
    return tile.h;
}
void FrameLayerMundo::setPixelVisivel(int largura, int altura) 
{
    areaVisivel.w=largura;
    areaVisivel.h=altura;
}
Dimensao FrameLayerMundo::getPixelVisivel() 
{
    return areaVisivel;
}
int FrameLayerMundo::getPixelVisivelHorizontal() 
{
    return areaVisivel.w;
}
int FrameLayerMundo::getPixelVisivelVertical() 
{
    return areaVisivel.h;
}
