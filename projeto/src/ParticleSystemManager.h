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

#ifndef _PARTICLESYSTEMMANAGER_H
#define _PARTICLESYSTEMMANAGER_H

#include "ParticleSystemEfeito.h"
#include <deque>

//Descrição: 
//    Classe para gerenciamento do sistema de  particulas.
//Motivação:
//    Gerenciar o uso de vários sistemas de particulas
class ParticleSystemManager {
  private:
    //Construtor 
    ParticleSystemManager();


  public:
    //Destrutor 
    ~ParticleSystemManager();

    //Adiciona um Sistema de Particulas
    void adicionar(ParticleSystemEfeito * efeito);

    //Desenha objetos que estao no container
    void desenhar();

    //Atualiza o Sistema
    void executar();

    //Retorna a quantidade de elementos 
    int size();

    //Limpa o gerenciador, removendo todos os elementos
    void limpar();

    //Pega uma Instância de ParticleSystemManager
    static ParticleSystemManager * getInstance();


  protected:
    static ParticleSystemManager * instance;

    std::deque<ParticleSystemEfeito*> lista;
    //Remove os sistemas de particulas já finalizados
    void removerMorto();

};
#endif
