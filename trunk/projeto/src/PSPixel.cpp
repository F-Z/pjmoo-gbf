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

#include "PSPixel.h"

namespace ParticleSystem {

PSPixel::PSPixel()
{
}
PSPixel::~PSPixel()
{
    lista.clear();
}
/** Desenha todas as unidades */
void PSPixel::draw()
{
    GBF::Point ponto;

    if (!lista.empty()){

        GBF::Color::RGB tcor;
        graphicSystem->gfx->setColor(255, 255, 255);
        graphicSystem->gfx->travar();

        for (unsigned int i = 0; i < lista.size(); i++){
            if (lista[i].ativa){
                tcor = GBF::Color::Converter::forRGB(lista[i].cor);
                graphicSystem->gfx->setColor(tcor.r, tcor.g, tcor.b);
                ponto.x = int(lista[i].point.x);
                ponto.y = int(lista[i].point.y);
                graphicSystem->gfx->putPixel(ponto.x, ponto.y);
            }
        }

        graphicSystem->gfx->destravar();
    }
}
/** Configura a quantidade de unidades que serão criadas */
void PSPixel::setQuantidade(int quantidade)
{
    for (int i = 0; i < quantidade; i++){
        Particula particula;

        particula.point.x    = 0;
        particula.point.y    = 0;
        particula.velocidade.x = 0;
        particula.velocidade.y = 0;
        particula.energia      = 0;
        particula.ativa        = false;
        particula.cor.h = 0;
        particula.cor.s = 0.0;
        particula.cor.v = 0.0;

        lista.push_back(particula);
    }
}
/** Indica se todas as unidades já terminaram o ciclo de vida */
bool PSPixel::isFinish()
{
    if (!lista.empty()){
        for (unsigned int i = 0; i < lista.size();i++){
            if (lista[i].ativa){
                return false;
            }
        }
    }
    return true;
}

} // namespace ParticleSystem
