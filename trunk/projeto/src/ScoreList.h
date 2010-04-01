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
#ifndef _SCORELIST_H
#define _SCORELIST_H

#include "Score.h"

namespace Score {

/**
 * Classe para gerenciamento de lista de recordes.
 * Gerenciar uma listagem de recordes.
 */
class ScoreList {
  public:
    static const int tamanho=  10;


  protected:
    Score recorde[10];


  public:
    //Construtor
    ScoreList();

    //Destrutor
    virtual ~ScoreList();

    //Retorna o Primeiro recorde
    Score getPrimeiro();

    //Retorna o Último recorde
    Score getUltimo();

    //Retorna um recorde
    Score getRecorde(int indice);

    //Pesquisa se o recorde ja existe
    bool pesquisar(Score pesquisa);

    //Adiciona um novo recorde
    bool adicionar(Score novo);


  protected:
    //Ordena os recorde, em ordem descrecente
    void ordenar();


  private:
    //Adiciona um recorde no final da listagem
    bool adicionarFinal(Score novo);


  public:
    //Retorna a lista de recordes (Utilizado para salvar a lista em arquivo)
    Score * getLista();

    //Seta uma lista de recordes (Utilizado para carregar a lista de um arquivo)
    void setLista(const Score lista[]);

};

} // namespace Score
#endif
