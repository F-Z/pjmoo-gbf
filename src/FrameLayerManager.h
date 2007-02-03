#ifndef _FRAMELAYERMANAGER_H
#define _FRAMELAYERMANAGER_H

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

#include "FrameLayer.h"
#include <string>

#include <map>

#include "UtilLog.h"

//Classe para Gerenciamento de FrameLayer

class FrameLayerManager {
  public:
    //Destrutor
    virtual ~FrameLayerManager();

    //Retorna uma instancia de FrameLayerManager 
    static FrameLayerManager * getInstance();

    //Retorna FrameLayer para manipulação 
    FrameLayer * getFrameLayer(std::string nome);

    //Adiciona FrameLayer no FrameLayerManager 
    void adicionar(std::string nome, FrameLayer * frameLayer);


  protected:
    //Construtor
    FrameLayerManager();

    static FrameLayerManager * instance;

    std::map<std::string,FrameLayer*> objetomap;

};
#endif
