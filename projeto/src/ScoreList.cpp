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

const int ScoreList::tamanho;

//Construtor
ScoreList::ScoreList()
{
    for (int i=0; i<tamanho; i++){
        recorde[i].inicializar();
    }
}
//Destrutor
ScoreList::~ScoreList()
{
//não implementado
}
//Retorna o Primeiro recorde
Score ScoreList::getPrimeiro()
{
    return recorde[0];
}
//Retorna o Último recorde
Score ScoreList::getUltimo()
{
    return recorde[(tamanho-1)];
}
//Retorna um recorde
Score ScoreList::getRecorde(int indice)
{
    if ((indice<0)||(indice>=tamanho)){
        throw "Indice não existente";
    } else {
        return recorde[indice];
    }
}
//Pesquisa se o recorde ja existe
bool ScoreList::pesquisar(Score pesquisa)
{
    bool retorno = false;

    for (int i=0; i<tamanho; i++){
        if ((recorde[i].id==pesquisa.id) &&
            (recorde[i].pontos==pesquisa.pontos) &&
            (recorde[i].pontos==pesquisa.pontos) &&
            (recorde[i].fase==pesquisa.fase)){
            retorno=true;
        }
    }

    return retorno;
}
//Adiciona um novo recorde
bool ScoreList::adicionar(Score novo)
{
    bool retorno = false;

    if (!pesquisar(novo)){
        if (novo.pontos > getUltimo().pontos){
            retorno = adicionarFinal(novo);
        }
    }

    return retorno;
}
//Ordena os recorde, em ordem descrecente
void ScoreList::ordenar()
{
    int passo,Pi,j,indice;
    Score recordeAuxiliar;
    int Ppasso[4]={5,3,2,1};

    for (Pi=0; Pi<4; Pi++ ){

        passo=Ppasso[Pi];

        for (indice=passo; indice < tamanho; indice++){

            recordeAuxiliar=recorde[indice];

            for (j=indice-passo; recordeAuxiliar.pontos > recorde[j].pontos &&
                j >=0; j-=passo){
                    recorde[j+passo] = recorde[j];
            }

            recorde[j+passo] = recordeAuxiliar;
        }
    }
}
//Adiciona um recorde no final da listagem
bool ScoreList::adicionarFinal(Score novo)
{
    bool retorno = true;

    try {
        recorde[tamanho-1]=novo;
        ordenar();
    } catch (std::exception& e){
        retorno = false;
        //log do exception = e.what();
    }

    return retorno;
}
//Retorna a lista de recordes (Utilizado para salvar a lista em arquivo)
Score * ScoreList::getLista()
{
    return &recorde[0];
}
//Seta uma lista de recordes (Utilizado para carregar a lista de um arquivo)
void ScoreList::setLista(const Score lista[])
{
    for (int i=0; i<tamanho; i++){
        recorde[i]=lista[i];
    }
}

} // namespace RankingSystem
