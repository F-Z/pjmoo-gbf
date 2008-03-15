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

#ifndef _TOPSYSTEMRECORDELISTA_H
#define _TOPSYSTEMRECORDELISTA_H

#include "TopSystemRecorde.h"

//Descrição: 
//    Classe para gerenciamento de lista de recordes
//Motivação:
//    Gerenciar uma listagem de recordes
class TopSystemRecordeLista {
  public:
    static const int tamanho=  10;


  protected:
    TopSystemRecorde recorde[10];


  public:
    //Construtor
    TopSystemRecordeLista();

    //Destrutor
    virtual ~TopSystemRecordeLista();

    //Retorna o Primeiro recorde
    TopSystemRecorde getPrimeiro();

    //Retorna o Último recorde
    TopSystemRecorde getUltimo();

    //Retorna um recorde
    TopSystemRecorde getRecorde(int indice);

    //Pesquisa se o recorde ja existe
    bool pesquisar(TopSystemRecorde pesquisa);

    //Adiciona um novo recorde
    bool adicionar(TopSystemRecorde novo);


  protected:
    //Ordena os recorde, em ordem descrecente
    void ordenar();


  private:
    //Adiciona um recorde no final da listagem
    bool adicionarFinal(TopSystemRecorde novo);


  public:
    //Retorna a lista de recordes (Utilizado para salvar a lista em arquivo)
    TopSystemRecorde* getLista();

    //Seta uma lista de recordes (Utilizado para carregar a lista de um arquivo)
    void setLista(const TopSystemRecorde lista[]);

};
#endif
