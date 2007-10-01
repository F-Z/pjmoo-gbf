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

#include "FrameLayerManager.h"

//Destrutor
FrameLayerManager::~FrameLayerManager() 
{
    UtilLog::subSistema("Removendo FrameLayerManager");

    std::map<std::string,FrameLayer*>::iterator it;
    std::string nome = "";

    for (it=objetomap.begin();it!=objetomap.end(); it++){

        nome = (*it).first;

        try {
            delete ((*it).second);
            (*it).second=NULL;
            UtilLog::tracer("Removido: %s [Ok] ",nome.c_str());
        } catch (...){
            UtilLog::tracer("Tentando Remover: %s [Falhou]",nome.c_str());
        }
    }
    objetomap.clear();
}
//Retorna uma instancia de FrameLayerManager 
FrameLayerManager * FrameLayerManager::getInstance()
{
    if (instance == NULL){
        instance = new FrameLayerManager();
    }

    return instance;
}
//Retorna FrameLayer para manipulação 
FrameLayer * FrameLayerManager::getFrameLayer(std::string nome) 
{
    if (objetomap.find(nome)!=objetomap.end()){
        return objetomap[nome];
    } else {
        UtilLog::tracer("FrameLayer não encontrado: %s [Falhou]",nome.c_str());
        return NULL;
    }
}
//Adiciona FrameLayer no FrameLayerManager 
void FrameLayerManager::adicionar(std::string nome, FrameLayer * frameLayer) 
{
    if ((nome!="")&&(frameLayer!=NULL)){
        objetomap[nome]=frameLayer;
    } else {
        UtilLog::comentario("Adicionando FrameLayer %s [Falhou]",nome.c_str());
    }
}
//Construtor
FrameLayerManager::FrameLayerManager() 
{
    UtilLog::subSistema("Instanciando FrameLayerManager");
}
FrameLayerManager * FrameLayerManager::instance;

