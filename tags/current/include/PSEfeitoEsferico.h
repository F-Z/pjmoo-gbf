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

#ifndef _PSEFEITOESFERICO_H
#define _PSEFEITOESFERICO_H

#include "GBF.h"
#include "PSPixel.h"

namespace ParticleSystem {

//Descrição: 
//    Classe abstrata que permite agrupamente de particulas esfericas
//Motivação:
//    Permitir gerenciar um grupo de unidades com movimento esferico
class PSEfeitoEsferico : public PSPixel {
  public:
    //Construtor
    PSEfeitoEsferico();

    //Destrutor
    virtual ~PSEfeitoEsferico();

    //Configura o tamanho do raio de ação das particulas
    void setRaio(int raio);


  protected:
    int raio;

    GBF::Ponto origem;

};

} // namespace ParticleSystem
#endif
