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

#include "TopSystemGaleria.h"

const int TopSystemGaleria::assCheckSize;

int TopSystemGaleria::assCheck[assCheckSize]={'N'+'a'+'o'+'E'+'V'+'a'+'l'+'i'+'d'+'o','N'+'E'+'V','0'+'.'+'0'};

std::string TopSystemGaleria::pathBase;

//Construtor
TopSystemGaleria::TopSystemGaleria() 
{
//não implementado
}
//Destrutor
TopSystemGaleria::~TopSystemGaleria() 
{
//não implementado
}
//Adiciona um recorde
bool TopSystemGaleria::adicionar(TopSystemRecorde recorde) 
{
    return lista.adicionar(recorde);
}
//Retorna um recorde com base no indice
TopSystemRecorde TopSystemGaleria::getRecorde(int indice) 
{
    return lista.getRecorde(indice);
}
//Salva recordes em arquivo
bool TopSystemGaleria::salvar() 
{
    FILE *handleArquivo;
    bool retorno = false;

    handleArquivo = fopen(arquivo.c_str(),"wb");

    if (handleArquivo!=NULL){
        fwrite(assCheck,sizeof(int),assCheckSize,handleArquivo);
        //fwrite(&lista.recorde, sizeof(TopSystemRecorde[10]), 1, handleArquivo);
        fwrite(lista.getLista(), sizeof(TopSystemRecorde[10]), 1, handleArquivo);
        fclose(handleArquivo);
        retorno = true;
    } else {
        UtilLog::tracer("Salvando %s",arquivo.c_str());
    }

    if (retorno){
        UtilLog::comentario("[Ok]");
    } else {
        UtilLog::comentario("[Falhou]");
    }

    return retorno;
}
//Carrega recordes de um arquivo
bool TopSystemGaleria::carregar() 
{
    FILE *handleArquivo;
    bool retorno = false;
    int assLocal[assCheckSize];

    handleArquivo = fopen(arquivo.c_str(),"rb");

    UtilLog::tracer("Carregando TopSystemGaleria...");
    if (handleArquivo!=NULL){
        fread(assLocal,sizeof(int),assCheckSize,handleArquivo);
        //fread(&lista.recorde, sizeof(TopSystemRecorde[10]), 1, handleArquivo);

        TopSystemRecorde recorde[10];
        fread(&recorde, sizeof(TopSystemRecorde[10]), 1, handleArquivo);
        lista.setLista(recorde);

        fclose(handleArquivo);
        retorno  = true;

        for (int a=0; a<assCheckSize; a++){
            if (assLocal[a]!=assCheck[a]){
                retorno = false;
                break;
            }
        }
    } else {
        UtilLog::tracer("Nao foi possivel carregar o arquivo %s",arquivo.c_str());
    }

    if (retorno){
       UtilLog::comentario("[Ok]");
    } else {
       UtilLog::comentario("[Falhou]");
    }

    return retorno;
}
//Adiciona uma lista de recordes
void TopSystemGaleria::setRecordeLista(TopSystemRecordeLista lista) 
{
    this->lista=lista;
}
//Informa o arquivo para carregar e salvar os recordes
void TopSystemGaleria::setArquivo(std::string arquivo) 
{
    this->arquivo=pathBase;
    this->arquivo+=arquivo;
}
//Configura o caminho do arquivo de recordes
void TopSystemGaleria::setPathBase(std::string path)

{
      pathBase=path;
}

//Configura a assinatura do arquivo de recordes
void TopSystemGaleria::setAssinatura(int jogoNome, int jogoSigla, int jogoVersao) 
{

    assCheck[0]=jogoNome;
    assCheck[1]=jogoSigla;
    assCheck[2]=jogoVersao;
}
//Verificar se um recorde já existe
bool TopSystemGaleria::pesquisar(TopSystemRecorde pesquisa) 
{
    return lista.pesquisar(pesquisa);
}
