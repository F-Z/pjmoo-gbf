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

#ifndef _PSMANAGER_H
#define _PSMANAGER_H

#include "PSEffect.h"
#include <deque>
#include "BaseManager.h"

namespace ParticleSystem {

//Descrição:
//    Classe para gerenciamento do sistema de  particulas.
//Motivação:
//    Gerenciar o uso de vários sistemas de particulas
class PSManager : public GBF::BaseManager {
  private:
    //Construtor
    PSManager();


  public:
    //Destrutor
    ~PSManager();

    //Adiciona um Sistema de Particulas
    void adicionar(PSEffect * efeito);

    //Desenha objetos que estao no container
    void desenhar();

    //Atualiza o Sistema
    void executar();

    //Retorna a quantidade de elementos
    int size();

    //Limpa o gerenciador, removendo todos os elementos
    void limpar();

    //Pega uma Instância de ParticleSystemManager
    static PSManager * getInstance();


  protected:
    static PSManager * instance;

    std::deque<PSEffect*> lista;
    //Remove os sistemas de particulas já finalizados
    void removerMorto();

};

} // namespace ParticleSystem
#endif
