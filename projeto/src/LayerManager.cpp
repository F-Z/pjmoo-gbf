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

#include "LayerManager.h"

namespace GBF {

namespace Image {

namespace Layer {

/** Destrutor */
LayerManager::~LayerManager()
{
    //UtilLog::subSistema("Removendo FrameLayerManager");

    std::map<std::string, FrameLayer*>::iterator it;
    std::string nome = "";

    for (it = objetomap.begin();it != objetomap.end(); it++) {
        nome = (*it).first;
        try {
            delete((*it).second);
            (*it).second = NULL;
            //util::Log::tracer("Removido: %s [Ok] ",nome.c_str());
        } catch (...) {
            //util::Log::tracer("Tentando Remover: %s [Falhou]",nome.c_str());
        }
    }

    objetomap.clear();
}

/** Retorna uma instancia de FrameLayerManager */
LayerManager * LayerManager::getInstance()
{
    if (instance == NULL) {
        instance = new LayerManager();
    }

    return instance;
}

/** Retorna FrameLayer para manipulação */
FrameLayer * LayerManager::getFrameLayer(std::string name)
{
    if (objetomap.find(name) != objetomap.end()) {
        return objetomap[name];
    } else {
        //UtilLog::tracer("FrameLayer não encontrado: %s [Falhou]",nome.c_str());
        return NULL;
    }
}

/** Adiciona FrameLayer no FrameLayerManager */
void LayerManager::add(std::string name, FrameLayer * frameLayer)
{
    std::cout << "\tLayerManager: " << name << std::endl;

    if ((name != "") && (frameLayer != NULL)) {
        objetomap[name] = frameLayer;
    }
    else {
        std::cerr << "[ERROR]LayerManager: Is Null or Undefined" << name << std::endl;
    }
}

/** Construtor */
LayerManager::LayerManager()
{
    std::cout << "GBF::Image::Layer::LayerManager" << std::endl;
}

LayerManager * LayerManager::instance;


} // namespace GBF::Image::Layer

} // namespace GBF::Image

} // namespace GBF
