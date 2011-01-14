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
#ifndef _GRAPHICSYSTEM_H
#define _GRAPHICSYSTEM_H

#include "ImageBufferManager.h"
#include "GFX.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class GraphicSystem
{
  public:
    ImageBufferManager * imageBufferManager;

    GFX * gfx;


  protected:
    GraphicSystem();


  public:
    ~GraphicSystem();


  protected:
    static GraphicSystem * instance;


  public:
    static GraphicSystem * getInstance();

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
