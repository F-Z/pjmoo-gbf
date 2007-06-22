#ifndef _GRAPHICSYSTEMIMAGEBUFFERMANAGER_H
#define _GRAPHICSYSTEMIMAGEBUFFERMANAGER_H

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

#include "GraphicSystemImageBuffer.h"
#include <string>

#include <map>


class GraphicSystemImageBufferManager
{
  public:
    //Destrutor
    virtual ~GraphicSystemImageBufferManager();

    // Retorna uma instancia de GraphicSystemImageBufferManager
    static GraphicSystemImageBufferManager * getInstance();

    // Retorna GraphicSystemImageBufferManager para manipulação
    GraphicSystemImageBuffer * getImageBuffer(std::string nome);

    // Carregar ImageBuffer para o ImageBufferManager 
    void carregar(std::string nome, std::string arquivo);

    // Remove ImageBuffer 
    void apagar(std::string nome);

    // Informa PathBase para leitura de arquivos
    static void setPathBase(std::string path);


  protected:
    static GraphicSystemImageBufferManager * instance;

    std::map<std::string,GraphicSystemImageBuffer*> objetomap;


  private:
    //Construtor
    GraphicSystemImageBufferManager();

    static std::string pathBase;

};
#endif
