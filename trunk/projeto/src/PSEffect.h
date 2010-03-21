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

#ifndef _PSEFFECT_H
#define _PSEFFECT_H

#include "GraphicSystemUtility.h"
#include "Object.h"

namespace ParticleSystem {

/** Classe abstrata que permite agrupamente de particulas
Motivação:
    Permitir gerenciar um grupo de unidades com ciclo de vida semelhantes */
class PSEffect : public GBF::Kernel::Graphic::GraphicSystemUtility, public GBF::Object {
    public:
        /** Construtor */
        PSEffect();

        /** Destrutor */
        virtual ~PSEffect();

        /** Desenha todas as unidades */
        virtual void draw() = 0;

        /** Inicializa o sistema de particulas */
        virtual void create(int x, int y) = 0;

        /** Executa as unidades do sistema */
        virtual void execute() = 0;

        virtual bool isFinish() = 0;

};

} // namespace ParticleSystem
#endif
