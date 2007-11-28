#ifndef _OBJECTMANAGER_H
#define _OBJECTMANAGER_H

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

#include "InputSystemCore.h"
#include "BaseManager.h"

//Descrição: 
//    Classe para criação de gerenciadores
//Motivação:
//    Fornecer uma interface padrão para criação de gerenciadores
class ListManager : public BaseManager
{
  public:
    //Construtor 
    ListManager();

    //Destrutor 
    virtual ~ListManager();

    //Desenha objetos que estao no container
    virtual void desenhar() = 0;

    //Retorna a quantidade de elementos 
    virtual int size() = 0;

    //Limpa o container, removendo todos os elementos
    virtual void limpar() = 0;

    //Executa as ações de cada elemento 
    virtual void acao(InputSystemCore * input) = 0;


  protected:
    //Ordena os elementos 
    virtual void ordenar() = 0;

};
#endif
