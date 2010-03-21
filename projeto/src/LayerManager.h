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

#ifndef _LAYERMANAGER_H
#define _LAYERMANAGER_H

#include "FrameLayer.h"
#include <string>

#include <map>

#include "BaseManager.h"

namespace GBF {

namespace Image {

namespace Layer {

/** Classe para Gerenciamento de FrameLayer */
class LayerManager : public GBF::BaseManager {
    public:
        /** Destrutor */
        virtual ~LayerManager();

        /** Retorna uma instancia de FrameLayerManager */
        static LayerManager * getInstance();

        /** Retorna FrameLayer para manipulação */
        FrameLayer * getFrameLayer(std::string name);

        /** Adiciona FrameLayer no FrameLayerManager */
        void add(std::string name, FrameLayer * frameLayer);


    protected:
        /** Construtor */
        LayerManager();

        static LayerManager * instance;

        std::map<std::string, FrameLayer*> objetomap;

};

} // namespace GBF::Image::Layer

} // namespace GBF::Image

} // namespace GBF

#endif
