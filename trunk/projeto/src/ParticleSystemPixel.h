////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#ifndef _PARTICLESYSTEMPIXEL_H
#define _PARTICLESYSTEMPIXEL_H

#include "GBF_define.h"
#include "UtilColor.h"
#include "ParticleSystemEfeito.h"
#include <deque>
#include "GraphicSystem.h"

//Descri��o:
//    Estrutura para representa��o de uma particula
//Motiva��o:
//    Permitir representar uma unidade com caracteristicas e ciclo de vida pr�prios
struct Particula
{
    PontoVirtual velocidade;

    PontoVirtual posicao;

    int energia;

    HSV cor;

    bool ativa;

};
class ParticleSystemPixel : public ParticleSystemEfeito
{
  public:
    ParticleSystemPixel();

    virtual ~ParticleSystemPixel();

    //Desenha todas as unidades
    virtual void desenhar();

    //Configura a quantidade de unidades que ser�o criadas
    void setQuantidade(int quantidade);

    //Indica se todas as unidades j� terminaram o ciclo de vida
    virtual bool isTerminou();


  protected:
    std::deque<Particula> lista;

    static GraphicSystem * graphicSystem;

};
#endif
