/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
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
class ScoreList
{
    public:

        static const int size =  10;

        /** Construtor */
        ScoreList();

        /** Destrutor */
        virtual ~ScoreList();

        /** Retorna o Primeiro recorde */
        Score getFirst();

        /** Retorna o Último recorde */
        Score getLast();

        /** Retorna um score */
        Score getScore(int index);

        /** Pesquisa se o recorde ja existe */
        bool isExist(Score score);

        /** Adiciona um novo recorde */
        bool add(Score score);

        /** Retorna a lista de recordes. Utilizado para salvar a lista em arquivo. */
        Score * getArray();

        /** Seta uma lista de recordes. Utilizado para carregar a lista de um arquivo. */
        void setArray(const Score list[]);

    protected:

        Score scores[10];

        /** Ordena os recorde, em ordem descrecente. */
        void sort();

    private:

        /** Adiciona um recorde no final da listagem */
        bool addLast(Score score);
};

} // namespace Score
#endif
