/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _IMAGEBUFFER_H
#define _IMAGEBUFFER_H

#include "ImageBase.h"
#include <string>

#include "GBF.h"

namespace GBF {

namespace Kernel {

namespace Graphic {

class ImageBuffer : public ImageBase
{

    public:
        /** Construtor */
        ImageBuffer();

        /** Destrutor */
        virtual ~ImageBuffer();

        virtual bool loadFromFile(std::string fileName);

        /** Desenha um sprite simples na tela */
        void draw(GBF::Point point);

        /** Permite desenhar sprites animados */
        void draw(GBF::Point POSICAO, GBF::Area TAMANHO, int FRAME);

        /** Permite desenhar sprites animados com corte */
        void draw(GBF::Point POSICAO, GBF::Area TAMANHO, int FRAME, GBF::Area CORTE);

        friend class ImageBufferManager;
};

} // namespace GBF::Kernel::Graphic

} // namespace GBF::Kernel

} // namespace GBF

#endif
