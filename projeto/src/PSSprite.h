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

#ifndef _PSSPRITE_H
#define _PSSPRITE_H

#include "PSEffect.h"
#include <deque>
#include "Sprite.h"

namespace ParticleSystem {

class PSSprite : public PSEffect {
    public:
        //Construtor
        PSSprite();

        //Destrutor
        virtual ~PSSprite();

        //Desenha todas as unidades
        virtual void desenhar();

        //Verifica se terminou a animação de todos os sprites
        virtual bool isTerminou();


    protected:
        std::deque<GBF::Image::Sprite::Sprite *> lista;

};

} // namespace ParticleSystem

#endif
