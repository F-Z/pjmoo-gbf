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
#include "GraphicSystem.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

GraphicSystem::GraphicSystem()
{
    std::cout << "GBF::Kernel::Graphic::GraphicSystem" << std::endl;
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
