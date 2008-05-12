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

#include "GraphicSystem.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

GraphicSystem::GraphicSystem() 
{
    imageBufferManager = new ImageBufferManager();
    gfx = new GFX();
}
GraphicSystem::~GraphicSystem() 
{
    if (imageBufferManager){
        delete(imageBufferManager);
    }
    if (gfx){
        delete(gfx);
    }
}
GraphicSystem * GraphicSystem::instance;

GraphicSystem * GraphicSystem::getInstance()
{
    if (instance == NULL){
        instance = new GraphicSystem();
    }

    return instance;
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
