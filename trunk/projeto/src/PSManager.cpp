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

#include "PSManager.h"

namespace ParticleSystem {

/** Construtor */
PSManager::PSManager()
{
}
/** Destrutor */
PSManager::~PSManager()
{
    clear();
}
/** Adiciona um Sistema de Particulas */
void PSManager::add(PSEffect * efeito)
{
    lista.push_back(efeito);
}
/** Desenha objetos que estao no container */
void PSManager::draw()
{
    if (!lista.empty()){
        for (unsigned int t = 0; t < lista.size(); t++){
            if (lista[t]){
                lista[t]->draw();
            }
        }
    }
}
/** Atualiza o Sistema */
void PSManager::update()
{
    if (!lista.empty()){
        for (unsigned int t = 0; t < lista.size(); t++){
            if (lista[t]){
                lista[t]->execute();
            }
        }
        remove();
    }
}
/** Retorna a quantidade de elementos */
int PSManager::size()
{
    return lista.size();
}
/** Limpa o gerenciador, removendo todos os elementos */
void PSManager::clear()
{
    for (unsigned int i = 0; i < lista.size(); i++){
        try {
            if (lista[i]){
                delete lista[i];
                lista[i] = NULL;
            }
        } catch (...){
        }
    }
    lista.clear();
}
/** Pega uma Instância de ParticleSystemManager */
PSManager * PSManager::getInstance()
{
    if (instance == NULL){
        instance = new PSManager();
    }
    return instance;
}
PSManager * PSManager::instance = NULL;
/** Remove os sistemas de particulas já finalizados */
void PSManager::remove()
{
    int total = size() - 1;

    for (int i = total; i >= 0; i--){
        if (lista[i] != NULL){
            if (lista[i]->isFinish()){
                delete lista[i];
                lista[i] = NULL;
                lista.erase(lista.begin() + i);
            }
        }
    }
}

} // namespace ParticleSystem
