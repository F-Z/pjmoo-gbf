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

#ifndef _PARTICLESYSTEMEFEITO_H
#define _PARTICLESYSTEMEFEITO_H

#include "GraphicSystemUtility.h"

//Descrição: 
//    Classe abstrata que permite agrupamente de particulas
//Motivação:
//    Permitir gerenciar um grupo de unidades com ciclo de vida semelhantes
class ParticleSystemEfeito : public GraphicSystemUtility {
  public:
    //Construtor
    ParticleSystemEfeito();

    //Destrutor
    virtual ~ParticleSystemEfeito();

    //Desenha todas as unidades
    virtual void desenhar() = 0;

    //Inicializa o sistema de particulas
    virtual void criar(int x, int y) = 0;

    //Executa as unidades do sistema
    virtual void executar() = 0;

    virtual bool isTerminou() = 0;

};
#endif
