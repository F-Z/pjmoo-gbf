#ifndef _LISTPERSONAGEMABSTRACT_H
#define _LISTPERSONAGEMABSTRACT_H

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

#include "ObjectManager.h"
#include "InputSystem.h"
#include "PersonagemAbstract.h"
#include <deque>

//Descrição: 
//    Classe para criação de gerenciadores de personagens
//Motivação:
//    Fornecer uma interface padrão para criação de gerenciadores de personagens
class ListPersonagemAbstract : public ListManager
{
  public:
    //Construtor 
    ListPersonagemAbstract();

    //Destrutor 
    virtual ~ListPersonagemAbstract();

    //Desenha objetos que estao no container
    virtual void desenhar();

    //Retorna a quantidade de elementos 
    virtual int size();

    //Limpa o container, removendo todos os elementos
    virtual void limpar();

    //Executa as ações de cada elemento 
    virtual void acao(InputSystem * input = NULL);

    void adicionar(PersonagemAbstract * personagem);

    void remover(PersonagemAbstract * personagem);

    virtual void colisao(ListPersonagemAbstract * objeto);

    virtual void colisao(PersonagemAbstract * objeto);

    virtual PersonagemAbstract * getPersonagem(int indice);

    virtual void executar() = 0;


  protected:
    virtual void ordenar();

    std::deque<PersonagemAbstract*> lista;
};
#endif
