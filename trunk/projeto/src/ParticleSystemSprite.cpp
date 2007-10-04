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

#include "ParticleSystemSprite.h"

//Construtor
ParticleSystemSprite::ParticleSystemSprite()
{
}
//Destrutor
ParticleSystemSprite::~ParticleSystemSprite()
{
    for (unsigned int i=0; i<lista.size(); i++){
        try {
            if (lista[i]){
                delete lista[i];
                lista[i]=NULL;
            }
        } catch (...){
        }
    }
    lista.clear();
}
//Desenha todas as unidades
void ParticleSystemSprite::desenhar()
{
    if (!lista.empty()){
        for (unsigned int i=0; i<lista.size(); i++){
            if (!lista[i]->animacao.isFim()){
                lista[i]->desenhar();
            }
        }
    }
}
//Verifica se terminou a animação de todos os sprites
bool ParticleSystemSprite::isTerminou()
{
    if (!lista.empty()){
        for (unsigned int i=0; i<lista.size();i++){
            if (!lista[i]->animacao.isFim()){
                return false;
            }
        }
    }
    return true;
}
