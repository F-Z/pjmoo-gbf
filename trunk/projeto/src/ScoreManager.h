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
#ifndef _SCOREMANAGER_H
#define _SCOREMANAGER_H

#include <string>
#include <cstdio>

#include "ScoreList.h"
#include "Score.h"

namespace Score {

/**
 * Classe para gerenciamento da listagem de recordes.
 * Permitir carregar e salvar em disco a listagem de recordes
 */
class ScoreManager
{
    public:

        /** Construtor */
        ScoreManager();

        /** Destrutor */
        ~ScoreManager();

        /** Adiciona um recorde */
        bool add(Score score);

        /** Retorna um recorde com base no indice */
        Score getScore(int index);

        /** Salva recordes em arquivo */
        bool save();

        /** Carrega recordes de um arquivo */
        bool load();

        /** Adiciona uma lista de scores */
        void setScoreList(ScoreList list);

        /** Informa o arquivo para carregar e salvar os recordes */
        void setFileName(std::string fileName);

        /** Configura o caminho do arquivo de recordes */
        static void setPathBase(std::string path);

        /** Configura a assinatura do arquivo de recordes */
        void setCheck(int gameName, int gameInfo, int gameVersion);

        /** Verificar se um recorde já existe */
        bool search(Score score);

    protected:

        std::string fileName;

        ScoreList list;


    private:

        static const int assCheckSize =  3;

        static int assCheck[assCheckSize];

        static std::string pathBase;

};

} // namespace Score
#endif
