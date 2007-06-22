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

#ifndef _PARTICLESYSTEMEFEITOESFERICO_H
#define _PARTICLESYSTEMEFEITOESFERICO_H

#include "ParticleSystemEfeito.h"
#include "GBF_define.h"

//Descrição: 
//    Classe abstrata que permite agrupamente de particulas esfericas
//Motivação:
//    Permitir gerenciar um grupo de unidades com movimento esferico
class ParticleSystemEfeitoEsferico : public ParticleSystemEfeito {
  public:
    //Construtor
    ParticleSystemEfeitoEsferico();

    //Destrutor
    virtual ~ParticleSystemEfeitoEsferico();

    //Configura o tamanho do raio de ação das particulas
    void setRaio(int raio);


  protected:
    int raio;

    Ponto origem;

};
#endif
