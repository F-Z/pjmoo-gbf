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

#include "LayerManager.h"

namespace GBF {

namespace Imagem {

namespace Layer {

//Destrutor
LayerManager::~LayerManager()
{
    //UtilLog::subSistema("Removendo FrameLayerManager");

    std::map<std::string,FrameLayer*>::iterator it;
    std::string nome = "";

    for (it=objetomap.begin();it!=objetomap.end(); it++){

        nome = (*it).first;

        if (nome!=""){
            try {
                delete ((*it).second);
                (*it).second=NULL;
                //util::Log::tracer("Removido: %s [Ok] ",nome.c_str());
            } catch (...){
                //util::Log::tracer("Tentando Remover: %s [Falhou]",nome.c_str());
            }
        }
    }
    objetomap.clear();
}
//Retorna uma instancia de FrameLayerManager
LayerManager * LayerManager::getInstance()
{
    if (instance == NULL){
        instance = new LayerManager();
    }

    return instance;
}
//Retorna FrameLayer para manipulação
FrameLayer * LayerManager::getFrameLayer(std::string nome)
{
    if (objetomap.find(nome)!=objetomap.end()){
        return objetomap[nome];
    } else {
        //UtilLog::tracer("FrameLayer não encontrado: %s [Falhou]",nome.c_str());
        return NULL;
    }
}
//Adiciona FrameLayer no FrameLayerManager
void LayerManager::adicionar(std::string nome, FrameLayer * frameLayer)
{
    std::cout << "\tLayerManager: " << nome << std::endl;

    if ((nome!="")&&(frameLayer!=NULL)){
        objetomap[nome]=frameLayer;
    } else {
        std::cerr << "[ERROR]LayerManager: Is Null or Undefined" << nome << std::endl;
    }
}
//Construtor
LayerManager::LayerManager()
{
    std::cout << "GBF::Imagem::Layer::LayerManager" << std::endl;
//    UtilLog::subSistema("Instanciando FrameLayerManager");
}
LayerManager * LayerManager::instance;


} // namespace GBF::Imagem::Layer

} // namespace GBF::Imagem

} // namespace GBF
