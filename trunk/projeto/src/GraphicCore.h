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

#ifndef _GRAPHICCORE_H
#define _GRAPHICCORE_H

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
        /** Limpa a tela */
        void clear();

        /** Salva uma imagem da tela */
        void saveScreenshot(std::string fileName);

        /** Destrutor */
        virtual ~GraphicCore();

        void start();

        /** Realiza o flip(troca) entre os buffers de vídeo */
        void flip();

        GraphicMode mode;

        Screen * screen;

        /** Inicializa SubSistema de suporte a Video */
        GraphicCore();

        GraphicSystem * graphicSystem;

};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF

#endif
