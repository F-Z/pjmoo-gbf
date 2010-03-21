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

#ifndef _PSPIXEL_H
#define _PSPIXEL_H

#include "GBF.h"
#include "Color.h"
#include "PSEffect.h"
#include <deque>

namespace ParticleSystem
{

/** Estrutura para representação de uma particula
 Motivação:   Permitir representar uma unidade com caracteristicas e ciclo de vida próprios */
struct Particula
{
    GBF::PointFloat velocidade;

    GBF::PointFloat point;

    int energia;

    GBF::Color::HSV cor;

    bool ativa;

};
class PSPixel : public PSEffect
{
  public:
    PSPixel();

    virtual ~PSPixel();

    /** Desenha todas as unidades */
    virtual void draw();

    /** Configura a quantidade de unidades que serão criadas */
    void setQuantidade(int quantidade);

    /** Indica se todas as unidades já terminaram o ciclo de vida */
    virtual bool isFinish();


  protected:
    std::deque<Particula> lista;

};

} // namespace ParticleSystem
#endif
