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

#ifndef _RSMANAGER_H
#define _RSMANAGER_H

#include <string>

#include "RSLista.h"
#include "RSRecorde.h"

namespace RankingSystem {

//Descrição:
//    Classe para gerenciamento da listagem de recordes
//Motivação:
//    Permitir carregar e salvar em disco a listagem de recordes
class RSManager {
  protected:
    std::string arquivo;

    RSLista lista;


  private:
    static const int assCheckSize=  3;

    static int assCheck[assCheckSize];

    static std::string pathBase;


  public:
    //Construtor
    RSManager();

    //Destrutor
    ~RSManager();

    //Adiciona um recorde
    bool adicionar(RSRecorde recorde);

    //Retorna um recorde com base no indice
    RSRecorde getRecorde(int indice);

    //Salva recordes em arquivo
    bool salvar();

    //Carrega recordes de um arquivo
    bool carregar();

    //Adiciona uma lista de recordes
    void setRecordeLista(RSLista lista);

    //Informa o arquivo para carregar e salvar os recordes
    void setArquivo(std::string arquivo);

    //Configura o caminho do arquivo de recordes
    static void setPathBase(std::string path);

    //Configura a assinatura do arquivo de recordes
    void setAssinatura(int jogoNome, int jogoSigla, int jogoVersao);

    //Verificar se um recorde já existe
    bool pesquisar(RSRecorde pesquisa);

};

} // namespace RankingSystem
#endif
