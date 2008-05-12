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
    ImageBuffer* tab = new ImageBuffer();
//    UtilLog::getInstance()->inicializando("ImagemTableManager::Carregar()");

    std::string fullPath=pathBase+arquivo;

  //  UtilLog::tracer("ImagemTable=%s Arquivo=%s",nome.c_str(),fullPath.c_str());
    if (tab->carregarArquivo(fullPath)){
        objetomap[nome]=tab;
        //UtilLog::comentario("[Ok]");
    } else {
        //UtilLog::comentario("[Falhou]");
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
// Informa PathBase para leitura de arquivos
void ImageBufferManager::setPathBase(std::string path)
{
    pathBase=path;
}

//Construtor
ImageBufferManager::ImageBufferManager() 
{
//    UtilLog::subSistema("Instanciando GraphicSystemImageBufferManager");
}
std::string ImageBufferManager::pathBase;


} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
