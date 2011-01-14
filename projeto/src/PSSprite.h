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
#ifndef _PSSPRITE_H
#define _PSSPRITE_H

#include "PSEffect.h"
#include <deque>
#include "Sprite.h"

namespace ParticleSystem {

class PSSprite : public PSEffect {
    public:
        /** Construtor */
        PSSprite();

        /** Destrutor */
        virtual ~PSSprite();

        /** Desenha todas as unidades */
        virtual void draw();

        /** Verifica se terminou a animação de todos os sprites */
        virtual bool isFinish();


    protected:
        std::deque<GBF::Image::Sprite::Sprite *> lista;

};

} // namespace ParticleSystem

#endif
