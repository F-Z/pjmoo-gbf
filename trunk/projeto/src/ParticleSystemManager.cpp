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

#include "ParticleSystemManager.h"

//Construtor 
ParticleSystemManager::ParticleSystemManager() 
{

}
//Destrutor 
ParticleSystemManager::~ParticleSystemManager() 
{
    limpar();
}
//Adiciona um Sistema de Particulas
void ParticleSystemManager::adicionar(ParticleSystemEfeito * efeito) 
{
    lista.push_back(efeito);
}
//Desenha objetos que estao no container
void ParticleSystemManager::desenhar() 
{
    if (!lista.empty()){
        for (unsigned int t=0; t<lista.size(); t++){
            if (lista[t]){
                lista[t]->desenhar();
            }
        }
    }
}
//Atualiza o Sistema
void ParticleSystemManager::executar() 
{
    if (!lista.empty()){
        for (unsigned int t=0; t<lista.size(); t++){
            if (lista[t]){
                lista[t]->executar();
            }
        }
        removerMorto();
    }
}
//Retorna a quantidade de elementos 
int ParticleSystemManager::size() 
{
    return lista.size();
}
//Limpa o gerenciador, removendo todos os elementos
void ParticleSystemManager::limpar() 
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
//Pega uma Instância de ParticleSystemManager
ParticleSystemManager * ParticleSystemManager::getInstance()
{
    if (instance == NULL){
        instance = new ParticleSystemManager();
    }
    return instance;
}
ParticleSystemManager * ParticleSystemManager::instance=NULL;

//Remove os sistemas de particulas já finalizados
void ParticleSystemManager::removerMorto() 
{
    int total=size()-1;

    for (int i=total; i>=0; i--){
        if (lista[i]!=NULL){
            if (lista[i]->isTerminou()){
                delete lista[i];
                lista[i]=NULL;
                lista.erase(lista.begin()+i);
            }
        }
    }
}
