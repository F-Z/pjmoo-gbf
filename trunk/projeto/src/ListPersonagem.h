#ifndef _LISTPERSONAGEM_H
#define _LISTPERSONAGEM_H

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

#include "ListManager.h"
#include "InputSystem.h"
#include "Character.h"
#include <deque>

namespace Character {

//Descrição:
//    Classe para criação de gerenciadores de personagens
//Motivação:
//    Fornecer uma interface padrão para criação de gerenciadores de personagens
class ListPersonagem : public GBF::ListManager
{
  public:
    //Construtor
    ListPersonagem();

    //Destrutor
    virtual ~ListPersonagem();

    //Desenha objetos que estao no container
    virtual void desenhar();

    //Retorna a quantidade de elementos
    virtual int size();

    //Limpa o container, removendo todos os elementos
    virtual void limpar();

    //Executa as ações de cada elemento
    virtual void acao(GBF::Kernel::Input::InputSystem * input = NULL);

    void adicionar(Character * personagem);

    virtual void remover(Character * personagem);

    virtual void colisao(ListPersonagem * objeto);

    virtual void colisao(Character * objeto);

    virtual Character * getPersonagem(int indice);


  protected:
    virtual void ordenar();

    std::deque<Character*> lista;
};

} // namespace Personagem
#endif
