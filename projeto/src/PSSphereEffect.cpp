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

#include "PSSphereEffect.h"

namespace ParticleSystem {

//Construtor
PSSphereEffect::PSSphereEffect()
{
    radius = 20;
}
//Destrutor
PSSphereEffect::~PSSphereEffect()
{


}
//Configura o tamanho do raio de ação das particulas
void PSSphereEffect::setRadius(int radius)
{
    this->radius=radius;
}

} // namespace ParticleSystem
