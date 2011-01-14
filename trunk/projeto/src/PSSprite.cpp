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
#include "PSSprite.h"

namespace ParticleSystem {

/** Construtor */
PSSprite::PSSprite()
{
}

/** Destrutor */
PSSprite::~PSSprite()
{
    for (unsigned int i = 0; i < lista.size(); i++) {
        try {
            if (lista[i]) {
                delete lista[i];
                lista[i] = NULL;
            }
        }
        catch (...) {
        }
    }

    lista.clear();
}

/** Desenha todas as unidades */
void PSSprite::draw()
{
    if (!lista.empty()) {
        for (unsigned int i = 0; i < lista.size(); i++) {
            if (!lista[i]->animation.isEnd()) {
                lista[i]->draw();
            }
        }
    }
}

/** Verifica se terminou a animação de todos os sprites */
bool PSSprite::isFinish()
{
    if (!lista.empty()) {
        for (unsigned int i = 0; i < lista.size();i++) {
            if (!lista[i]->animation.isEnd()) {
                return false;
            }
        }
    }

    return true;
}

} // namespace ParticleSystem
