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

#include "LayerMundo.h"

namespace GBF {

namespace Imagem {

namespace Layer {

//Destrutor
LayerMundo::~LayerMundo() 
{
}
GBF::Dimensao LayerMundo::getPixelTile() 
{
    return tile;
}
int LayerMundo::getPixelTileHorizontal() 
{
    return tile.w;
}
int LayerMundo::getPixelTileVertical() 
{
    return tile.h;
}
GBF::Dimensao LayerMundo::getPixelVisivel() 
{
    return areaVisivel;
}
int LayerMundo::getPixelVisivelHorizontal() 
{
    return areaVisivel.w;
}
int LayerMundo::getPixelVisivelVertical() 
{
    return areaVisivel.h;
}
GBF::Dimensao LayerMundo::getTiles() 
{
    return quantidadeTiles;
}
int LayerMundo::getTilesHorizontal() 
{
    return quantidadeTiles.w;
}
int LayerMundo::getTilesVertical() 
{
    return quantidadeTiles.h;
}
void LayerMundo::setPixelTile(int largura, int altura) 
{
    tile.w=largura;
    tile.h=altura;
}
void LayerMundo::setPixelVisivel(int largura, int altura) 
{
    areaVisivel.w=largura;
    areaVisivel.h=altura;
}
void LayerMundo::setTiles(int largura, int altura) 
{
    quantidadeTiles.w=largura;
    quantidadeTiles.h=altura;
}
//Construtor
LayerMundo::LayerMundo() 
{
}

} // namespace GBF::Imagem::Layer

} // namespace GBF::Imagem

} // namespace GBF
