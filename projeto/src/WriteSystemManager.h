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

#ifndef _WRITESYSTEMMANAGER_H
#define _WRITESYSTEMMANAGER_H

#include "WriteSystemBitmap.h"
#include <string>

#include <map>

#include "WriteSystemFontDefault.h"
#include "UserInterfaceTexto.h"

//Descri��o: 
//    Classe para gerenciamento do sistema de fontes (letras).
//Motiva��o:
//    Gerenciar o uso de fontes, facilitando o carregamento e acesso a escrita
class WriteSystemManager
{
  public:
    //Destrutor
    virtual ~WriteSystemManager();

    //Retorna uma fonte para manipula��o direta
    //Obs.: Ideal para casos em que se deseja manipula��es avan�adas
    WriteSystemBitmap * getFonte(std::string nome);

    //Pega uma Inst�ncia de FonteManager
    //Obs.: Esta classe � Singleton
    static WriteSystemManager * getInstance();

    //Carrega e adiciona uma fonte (WriteSystemBitmap)
    void carregar(std::string nome, std::string arquivo);

    //Escreve um texto na tela
    void escrever(std::string fonte, int x, int y, const char * texto, ...);

    //Escreve um texto na tela usando recursos de Localiza��o (Tradu��o)
    void escreverLocalizado(const std::string & fonte, int x, int y, std::string chave, ...);

    //Escreve na tela usando recursos de Localiza��o (Tradu��o), baseado na jun��o de dois segmentos de localiza��o
    void escreverLocalizadoSubChave(const std::string fonte, int x, int y, const std::string chave, const std::string subChave);

    //Remove uma fonte (WriteSystemFontBitmap)
    void apagar(std::string nome);


  protected:
    std::map<std::string,WriteSystemBitmap*> objetomap;


  private:
    //Construtor
    WriteSystemManager();


  protected:
    static WriteSystemManager * instance;


  public:
    UserInterfaceTexto * uiTexto;


};
#endif
