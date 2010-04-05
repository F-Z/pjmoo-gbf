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
#include "ScoreList.h"

namespace Score {

const int ScoreList::size;

/** Construtor */
ScoreList::ScoreList()
{
    for (int i = 0; i < size; i++){
        scores[i].initialize();
    }
}

/** Destrutor */
ScoreList::~ScoreList()
{
}

/** Retorna o Primeiro recorde */
Score ScoreList::getFirst()
{
    return scores[0];
}

/** Retorna o Último recorde */
Score ScoreList::getLast()
{
    return scores[(size-1)];
}

/** Retorna um score */
Score ScoreList::getScore(int index)
{
    if ((index < 0) || (index >= size)){
        throw "ScoreList:: Indice não existente ";
    } else {
        return scores[index];
    }
}

/** Pesquisa se o recorde ja existe */
bool ScoreList::isExist(Score score)
{
    bool retorno = false;

    for (int i = 0; i < size; i++){
        if ((scores[i].id == score.id) &&
                (scores[i].score == score.score) &&
                (scores[i].stage == score.stage)){
            retorno = true;
        }
    }

    return retorno;
}

/** Adiciona um novo recorde */
bool ScoreList::add(Score score)
{
    bool retorno = false;

    if (!isExist(score)){
        if (score.score > getLast().score){
            retorno = addLast(score);
        }
    }

    return retorno;
}

/** Ordena os recorde, em ordem descrecente. */
void ScoreList::sort()
{
    int passo, Pi, j, indice;
    Score recordeAuxiliar;
    int Ppasso[4] = {5, 3, 2, 1};

    for (Pi = 0; Pi < 4; Pi++){

        passo = Ppasso[Pi];

        for (indice = passo; indice < size; indice++){

            recordeAuxiliar = scores[indice];

            for (j = indice - passo; recordeAuxiliar.score > scores[j].score &&
                    j >= 0; j -= passo){
                scores[j+passo] = scores[j];
            }

            scores[j+passo] = recordeAuxiliar;
        }
    }
}

/** Adiciona um recorde no final da listagem */
bool ScoreList::addLast(Score score)
{
    bool retorno = true;

    try {
        scores[size-1] = score;
        sort();
    } catch (std::exception& e){
        retorno = false;
        //log do exception = e.what();
    }

    return retorno;
}

/** Retorna a lista de recordes. Utilizado para salvar a lista em arquivo. */
Score * ScoreList::getArray()
{
    return &scores[0];
}

/** Seta uma lista de recordes. Utilizado para carregar a lista de um arquivo. */
void ScoreList::setArray(const Score list[])
{
    for (int i = 0; i < size; i++){
        scores[i] = list[i];
    }
}

} // namespace RankingSystem
