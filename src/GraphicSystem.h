#ifndef _GRAPHICSYSTEM_H
#define _GRAPHICSYSTEM_H

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

#include "GraphicSystemGFX.h"
#include "GraphicSystemMode.h"
#include "GraphicSystemScreen.h"
#include "GraphicSystemImage.h"

//*
// * \class GraphicSystem
// * \brief Classe para inicialização e controle do vídeo
// * \author David de Almeida Ferreira
// * \date  24/10/2004
// * \warning Classe Singleton    

class GraphicSystem {
  public:
    //Destrutor 
    virtual ~GraphicSystem();

    //Retorna um objeto de GraphicSystem (Singleton) 
    static GraphicSystem * getInstance();

    void sincronizar();

    //Limpa a tela 
    void clear();

    //Realiza o flip(troca) entre os buffers de vídeo 
    void flip();

    //Salva uma imagem da tela 
    void salvarScreenShot(std::string arquivo);

    GraphicSystemGFX * gsGFX;

    GraphicSystemMode * gsMode;

    GraphicSystemScreen * gsScreen;


  protected:
    static GraphicSystem * instance;


  private:
    //Inicializa SubSistema de suporte a Video 
    GraphicSystem();

};
#endif
