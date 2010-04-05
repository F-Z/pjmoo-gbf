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
#include "ScoreManager.h"

namespace Score {

const int ScoreManager::assCheckSize;

int ScoreManager::assCheck[assCheckSize] = {'N' + 'a' + 'o' + 'E' + 'V' + 'a' + 'l' + 'i' + 'd' + 'o', 'N' + 'E' + 'V', '0' + '.' + '0'};

std::string ScoreManager::pathBase;

/** Construtor */
ScoreManager::ScoreManager()
{
}

/** Destrutor */
ScoreManager::~ScoreManager()
{
}

/** Adiciona um recorde */
bool ScoreManager::add(Score recorde)
{
    return list.add(recorde);
}

/** Retorna um recorde com base no indice */
Score ScoreManager::getScore(int index)
{
    return list.getScore(index);
}

/** Salva recordes em arquivo */
bool ScoreManager::save()
{
    FILE *handleArquivo;
    bool retorno = false;

    handleArquivo = fopen(fileName.c_str(), "wb");

    if (handleArquivo != NULL){
        fwrite(assCheck, sizeof(int), assCheckSize, handleArquivo);
        //fwrite(&lista.recorde, sizeof(TopSystemRecorde[10]), 1, handleArquivo);
        fwrite(list.getArray(), sizeof(Score[10]), 1, handleArquivo);
        fclose(handleArquivo);
        retorno = true;
    } else {
        // UtilLog::tracer("Salvando %s",arquivo.c_str());
    }

    if (retorno){
        // UtilLog::comentario("[Ok]");
    } else {
        //UtilLog::comentario("[Falhou]");
    }

    return retorno;
}

/** Carrega recordes de um arquivo */
bool ScoreManager::load()
{
    FILE *handleArquivo;
    bool retorno = false;
    int assLocal[assCheckSize];

    handleArquivo = fopen(fileName.c_str(), "rb");

    //UtilLog::tracer("Carregando TopSystemGaleria...");
    if (handleArquivo != NULL){
        fread(assLocal, sizeof(int), assCheckSize, handleArquivo);
        //fread(&lista.recorde, sizeof(TopSystemRecorde[10]), 1, handleArquivo);

        Score scores[10];
        fread(&scores, sizeof(Score[10]), 1, handleArquivo);
        list.setArray(scores);

        fclose(handleArquivo);
        retorno  = true;

        for (int a = 0; a < assCheckSize; a++){
            if (assLocal[a] != assCheck[a]){
                retorno = false;
                break;
            }
        }
    } else {
        //UtilLog::tracer("Nao foi possivel carregar o arquivo %s",arquivo.c_str());
    }

    if (retorno){
        //UtilLog::comentario("[Ok]");
    } else {
        //UtilLog::comentario("[Falhou]");
    }

    return retorno;
}

/** Adiciona uma lista de scores */
void ScoreManager::setScoreList(ScoreList list)
{
    this->list = list;
}

/** Informa o arquivo para carregar e salvar os recordes */
void ScoreManager::setFileName(std::string fileName)
{
    this->fileName = pathBase;
    this->fileName += fileName;
}

/** Configura o caminho do arquivo de recordes */
void ScoreManager::setPathBase(std::string path)
{
    pathBase = path;
}

/** Configura a assinatura do arquivo de recordes */
void ScoreManager::setCheck(int gameName, int gameInfo, int gameVersion)
{
    assCheck[0] = gameName;
    assCheck[1] = gameInfo;
    assCheck[2] = gameVersion;
}
/** Verificar se um recorde já existe */
bool ScoreManager::search(Score score)
{
    return list.isExist(score);
}

} // namespace RankingSystem
