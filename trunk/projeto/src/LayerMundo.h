/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _LAYERMUNDO_H
#define _LAYERMUNDO_H

#include "GBF.h"

namespace GBF {

namespace Image {

namespace Layer {

class LayerMundo {
    public:
        //Destrutor
        virtual ~LayerMundo();

        GBF::Dimension getPixelTile();

        int getPixelTileHorizontal();

        int getPixelTileVertical();

        GBF::Dimension getPixelVisivel();

        int getPixelVisivelHorizontal();

        int getPixelVisivelVertical();

        GBF::Dimension getTiles();

        int getTilesHorizontal();

        int getTilesVertical();

        void setPixelTile(int largura, int altura);

        void setPixelVisivel(int largura, int altura);

        void setTiles(int largura, int altura);


    private:
        GBF::Dimension areaVisivel;

        GBF::Dimension quantidadeTiles;

        GBF::Dimension tile;

        //Construtor
        LayerMundo();

        friend class FrameLayer;
};

} // namespace GBF::Image::Layer

} // namespace GBF::Image

} // namespace GBF

#endif
