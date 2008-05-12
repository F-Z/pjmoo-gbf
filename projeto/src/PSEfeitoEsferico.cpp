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

#include "PSEfeitoEsferico.h"

namespace ParticleSystem {

//Construtor
PSEfeitoEsferico::PSEfeitoEsferico() 
{
    raio = 20;
}
//Destrutor
PSEfeitoEsferico::~PSEfeitoEsferico() 
{


}
//Configura o tamanho do raio de ação das particulas
void PSEfeitoEsferico::setRaio(int raio) 
{
    this->raio=raio;
}

} // namespace ParticleSystem
