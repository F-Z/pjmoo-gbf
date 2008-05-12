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

#include "RSLista.h"

namespace RankingSystem {

const int RSLista::tamanho;

//Construtor
RSLista::RSLista() 
{
    for (int i=0; i<tamanho; i++){
        recorde[i].inicializar();
    }
}
//Destrutor
RSLista::~RSLista() 
{
//não implementado
}
//Retorna o Primeiro recorde
RSRecorde RSLista::getPrimeiro() 
{
    return recorde[0];
}
//Retorna o Último recorde
RSRecorde RSLista::getUltimo() 
{
    return recorde[(tamanho-1)];
}
//Retorna um recorde
RSRecorde RSLista::getRecorde(int indice) 
{
    if ((indice<0)||(indice>=tamanho)){
        throw "Indice não existente";
    } else {
        return recorde[indice];
    }
}
//Pesquisa se o recorde ja existe
bool RSLista::pesquisar(RSRecorde pesquisa) 
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
bool RSLista::adicionar(RSRecorde novo) 
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
void RSLista::ordenar() 
{
    int passo,Pi,j,indice;
    RSRecorde recordeAuxiliar;
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
bool RSLista::adicionarFinal(RSRecorde novo) 
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
RSRecorde * RSLista::getLista() 
{
    return &recorde[0];
}
//Seta uma lista de recordes (Utilizado para carregar a lista de um arquivo)
void RSLista::setLista(const RSRecorde lista[]) 
{
    for (int i=0; i<tamanho; i++){
        recorde[i]=lista[i];
    }
}

} // namespace RankingSystem
