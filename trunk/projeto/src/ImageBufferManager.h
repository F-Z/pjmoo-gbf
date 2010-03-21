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

#ifndef _IMAGEBUFFERMANAGER_H
#define _IMAGEBUFFERMANAGER_H

#include "ImageBuffer.h"
#include <string>

#include <map>

#include "BaseManager.h"
#include "Path.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class ImageBufferManager : public GBF::BaseManager
{
  public:
    /** Destrutor */
    virtual ~ImageBufferManager();

    /** Retorna GraphicSystemImageBufferManager para manipulação */
    ImageBuffer * getImageBuffer(std::string name);

    /** Carregar ImageBuffer para o ImageBufferManager */
    void loadFromFile(std::string name, std::string fileName);

    /** Remove ImageBuffer */
    void remove(std::string name);


  protected:
    std::map<std::string,ImageBuffer*> objetomap;


  public:
    /** Construtor */
    ImageBufferManager();

  friend class GraphicSystem;
};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
