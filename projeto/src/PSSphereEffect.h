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

#ifndef _PSSPHEREEFFECT_H
#define _PSSPHEREEFFECT_H

#include "GBF.h"
#include "PSPixel.h"

namespace ParticleSystem {

/** Classe abstrata que permite agrupamente de particulas esfericas
 Motivação: Permitir gerenciar um grupo de unidades com movimento esferico */
class PSSphereEffect : public PSPixel {
    public:
        /** Construtor */
        PSSphereEffect();

        /** Destrutor */
        virtual ~PSSphereEffect();

        /** Configura o tamanho do raio de ação das particulas */
        void setRadius(int radius);

    protected:
        int radius;

        GBF::Point origem;
};

} // namespace ParticleSystem
#endif
