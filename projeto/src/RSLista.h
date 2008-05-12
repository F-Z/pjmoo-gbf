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

#ifndef _RSLISTA_H
#define _RSLISTA_H

#include "RSRecorde.h"

namespace RankingSystem {

//Descrição: 
//    Classe para gerenciamento de lista de recordes
//Motivação:
//    Gerenciar uma listagem de recordes
class RSLista {
  public:
    static const int tamanho=  10;


  protected:
    RSRecorde recorde[10];


  public:
    //Construtor
    RSLista();

    //Destrutor
    virtual ~RSLista();

    //Retorna o Primeiro recorde
    RSRecorde getPrimeiro();

    //Retorna o Último recorde
    RSRecorde getUltimo();

    //Retorna um recorde
    RSRecorde getRecorde(int indice);

    //Pesquisa se o recorde ja existe
    bool pesquisar(RSRecorde pesquisa);

    //Adiciona um novo recorde
    bool adicionar(RSRecorde novo);


  protected:
    //Ordena os recorde, em ordem descrecente
    void ordenar();


  private:
    //Adiciona um recorde no final da listagem
    bool adicionarFinal(RSRecorde novo);


  public:
    //Retorna a lista de recordes (Utilizado para salvar a lista em arquivo)
    RSRecorde * getLista();

    //Seta uma lista de recordes (Utilizado para carregar a lista de um arquivo)
    void setLista(const RSRecorde lista[]);

};

} // namespace RankingSystem
#endif
