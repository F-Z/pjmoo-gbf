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

#include "ParticleSystemEfeitoEsferico.h"

//Construtor
ParticleSystemEfeitoEsferico::ParticleSystemEfeitoEsferico() 
{
    raio = 20;
}
//Destrutor
ParticleSystemEfeitoEsferico::~ParticleSystemEfeitoEsferico() 
{


}
//Configura o tamanho do raio de ação das particulas
void ParticleSystemEfeitoEsferico::setRaio(int raio) 
{
    this->raio=raio;
}
