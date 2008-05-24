#ifndef _LAYERMANAGER_H
#define _LAYERMANAGER_H

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

#include "FrameLayer.h"
#include <string>

#include <map>

#include "Log.h"
#include "BaseManager.h"

namespace GBF {

namespace Imagem {

namespace Layer {

//Classe para Gerenciamento de FrameLayer

class LayerManager : public GBF::BaseManager
{
  public:
    //Destrutor
    virtual ~LayerManager();

    //Retorna uma instancia de FrameLayerManager 
    static LayerManager * getInstance();

    //Retorna FrameLayer para manipulação 
    FrameLayer * getFrameLayer(std::string nome);

    //Adiciona FrameLayer no FrameLayerManager 
    void adicionar(std::string nome, FrameLayer * frameLayer);


  protected:
    //Construtor
    LayerManager();

    static LayerManager * instance;

    std::map<std::string,FrameLayer*> objetomap;

};

} // namespace GBF::Imagem::Layer

} // namespace GBF::Imagem

} // namespace GBF
#endif
