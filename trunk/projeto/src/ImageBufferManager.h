#ifndef _IMAGEBUFFERMANAGER_H
#define _IMAGEBUFFERMANAGER_H

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

#include "ImageBuffer.h"
#include <string>

#include <map>

#include "BaseManager.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class ImageBufferManager : public GBF::BaseManager
{
  public:
    //Destrutor
    virtual ~ImageBufferManager();

    // Retorna GraphicSystemImageBufferManager para manipulação
    ImageBuffer * getImageBuffer(std::string nome);

    // Carregar ImageBuffer para o ImageBufferManager 
    void carregar(std::string nome, std::string arquivo);

    // Remove ImageBuffer 
    void apagar(std::string nome);

    // Informa PathBase para leitura de arquivos
    static void setPathBase(std::string path);


  protected:
    std::map<std::string,ImageBuffer*> objetomap;


  public:
    //Construtor
    ImageBufferManager();


  private:
    static std::string pathBase;

  friend class GraphicSystem;
};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
