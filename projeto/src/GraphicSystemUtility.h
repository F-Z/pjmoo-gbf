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
#ifndef _GRAPHICSYSTEMUTILITY_H
#define _GRAPHICSYSTEMUTILITY_H

#include "GraphicSystem.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class GraphicSystemUtility
{
  protected:
    static GraphicSystem * graphicSystem;


  private:
    static void setGraphicSystem(GraphicSystem * instance);

  friend class GraphicCore;
};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
