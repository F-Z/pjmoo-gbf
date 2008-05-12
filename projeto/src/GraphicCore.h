#ifndef _GRAPHICCORE_H
#define _GRAPHICCORE_H

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

#include <string>

#include "GraphicMode.h"
#include "Screen.h"
#include "ImageBase.h"
#include "GraphicSystem.h"
#include "GraphicSystemUtility.h"
#include "BaseSystem.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class GraphicCore : public GBF::BaseSystem
{
  public:
    //Limpa a tela 
    void clear();

    //Salva uma imagem da tela 
    void salvarScreenShot(std::string arquivo);

    //Destrutor 
    virtual ~GraphicCore();

    void iniciar();

    //Realiza o flip(troca) entre os buffers de vídeo 
    void flip();

    GraphicMode gsMode;

    Screen * gsScreen;

    //Inicializa SubSistema de suporte a Video 
    GraphicCore();

    GraphicSystem * graphicSystem;

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF
#endif
