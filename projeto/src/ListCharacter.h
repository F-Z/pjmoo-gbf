#ifndef _LISTCHARACTER_H
#define _LISTCHARACTER_H

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
class ListCharacter : public GBF::ListManager
{
  public:
    //Construtor
    ListCharacter();

    //Destrutor
    virtual ~ListCharacter();

    //Desenha objetos que estao no container
    virtual void desenhar();

    //Retorna a quantidade de elementos
    virtual int size();

    //Limpa o container, removendo todos os elementos
    virtual void limpar();

    //Executa as ações de cada elemento
    virtual void acao(GBF::Kernel::Input::InputSystem * input = NULL);

    void add(Character * character);

    virtual void remove(Character * character);

    virtual void collision(ListCharacter * listCharacter);

    virtual void collision(Character * character);

    virtual Character * getCharacter(int index);


  protected:
    virtual void ordenar();

    std::deque<Character*> list;
};

} // namespace Character
#endif
