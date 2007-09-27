#ifndef _GRAPHICSYSTEMCORE_H
#define _GRAPHICSYSTEMCORE_H

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

#include <string>

#include "GraphicSystemMode.h"
#include "GraphicSystemScreen.h"
#include "GraphicSystemImage.h"
#include "GraphicSystem.h"
#include "GraphicSystemUtility.h"

class GraphicSystemCore
{
  public:
    //Limpa a tela 
    void clear();

    //Salva uma imagem da tela 
    void salvarScreenShot(std::string arquivo);

    //Destrutor 
    virtual ~GraphicSystemCore();

    void sincronizar();

    //Realiza o flip(troca) entre os buffers de vídeo 
    void flip();

    GraphicSystemMode gsMode;

    GraphicSystemScreen * gsScreen;


  private:
    //Inicializa SubSistema de suporte a Video 
    GraphicSystemCore();


  public:
    GraphicSystem * graphicSystem;

  friend class GBF;
};
#endif
