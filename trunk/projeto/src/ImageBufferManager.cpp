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
#include "ImageBufferManager.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

/** Destrutor */
ImageBufferManager::~ImageBufferManager()
{
//    UtilLog::subSistema("Removendo GraphicSystemImageBufferManager");

    std::map<std::string,ImageBuffer*>::iterator it;

    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
        //    UtilLog::tracer("ImagemTable=%s",((*it).first).c_str());
        } catch(...){
          //  UtilLog::tracer("ImagemTable=Desconhecido(a)");
        }
        delete ((*it).second);
        (*it).second=NULL;
       // UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
/** Retorna GraphicSystemImageBufferManager para manipulação */
ImageBuffer * ImageBufferManager::getImageBuffer(std::string name)
{
    if (objetomap.find(name)!=objetomap.end()){
        return objetomap[name];
    } else {
        return NULL;
    //DAFs gerar log de erro
    }
}
/** Carregar ImageBuffer para o ImageBufferManager */
void ImageBufferManager::loadFromFile(std::string name, std::string fileName)
{
    std::string fullpath=Kernel::Util::Path::getPath()+fileName;

    ImageBuffer* tab = new ImageBuffer();

    std::cout << "\tImageBufferManager: " << name << "=" << fullpath << std::endl;

    if (tab->loadFromFile(fullpath)){
        objetomap[name]=tab;
    }
}
/** Remove ImageBuffer */
void ImageBufferManager::remove(std::string name)
{
    if (objetomap[name]){
        delete(objetomap[name]);
        objetomap[name]=NULL;
        objetomap.erase(name);
    }
}
/** Construtor */
ImageBufferManager::ImageBufferManager()
{
    std::cout << "GBF::Kernel::Graphic::ImageBufferManager" << std::endl;
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
