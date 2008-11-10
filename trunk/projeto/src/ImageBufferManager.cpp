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

#include "ImageBufferManager.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

//Destrutor
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
// Retorna GraphicSystemImageBufferManager para manipulação
ImageBuffer * ImageBufferManager::getImageBuffer(std::string nome)
{
    if (objetomap.find(nome)!=objetomap.end()){
        return objetomap[nome];
    } else {
        return NULL;
    //DAFs gerar log de erro
    }
}
// Carregar ImageBuffer para o ImageBufferManager
void ImageBufferManager::carregar(std::string nome, std::string arquivo)
{
    std::string fullpath=Kernel::Util::Path::getPath()+arquivo;

    ImageBuffer* tab = new ImageBuffer();

    std::cout << "\tImageBufferManager: " << nome << "=" << fullpath << std::endl;

    if (tab->carregarArquivo(fullpath)){
        objetomap[nome]=tab;
    }
}
// Remove ImageBuffer
void ImageBufferManager::apagar(std::string nome)
{
    if (objetomap[nome]){
        delete(objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
//Construtor
ImageBufferManager::ImageBufferManager()
{
//    UtilLog::subSistema("Instanciando GraphicSystemImageBufferManager");
    std::cout << "GBF::Kernel::Graphic::ImageBufferManager" << std::endl;
}

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
