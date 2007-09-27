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
////////////////////////////////////////////////////////////////////////

#include "GraphicSystemImageBufferManager.h"

//Destrutor
GraphicSystemImageBufferManager::~GraphicSystemImageBufferManager() 
{
    UtilLog::subSistema("Removendo GraphicSystemImageBufferManager");

    std::map<std::string,GraphicSystemImageBuffer*>::iterator it;

    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
            UtilLog::tracer("ImagemTable=%s",((*it).first).c_str());
        } catch(...){
            UtilLog::tracer("ImagemTable=Desconhecido(a)");
        }
        delete ((*it).second);
        (*it).second=NULL;
        UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
// Retorna GraphicSystemImageBufferManager para manipulação
GraphicSystemImageBuffer * GraphicSystemImageBufferManager::getImageBuffer(std::string nome) 
{
    if (objetomap.find(nome)!=objetomap.end()){
        return objetomap[nome];
    } else {
        return NULL;
    //DAFs gerar log de erro
    }
}
// Carregar ImageBuffer para o ImageBufferManager 
void GraphicSystemImageBufferManager::carregar(std::string nome, std::string arquivo) 
{
    GraphicSystemImageBuffer* tab = new GraphicSystemImageBuffer();
//    UtilLog::getInstance()->inicializando("ImagemTableManager::Carregar()");

    std::string fullPath=pathBase+arquivo;

    UtilLog::tracer("ImagemTable=%s Arquivo=%s",nome.c_str(),fullPath.c_str());
    if (tab->carregarArquivo(fullPath)){
        objetomap[nome]=tab;
        UtilLog::comentario("[Ok]");
    } else {
        UtilLog::comentario("[Falhou]");
    }
}
// Remove ImageBuffer 
void GraphicSystemImageBufferManager::apagar(std::string nome) 
{
    if (objetomap[nome]){
        delete(objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
// Informa PathBase para leitura de arquivos
void GraphicSystemImageBufferManager::setPathBase(std::string path)
{
    pathBase=path;
}

//Construtor
GraphicSystemImageBufferManager::GraphicSystemImageBufferManager() 
{
    UtilLog::subSistema("Instanciando GraphicSystemImageBufferManager");
}
std::string GraphicSystemImageBufferManager::pathBase;

