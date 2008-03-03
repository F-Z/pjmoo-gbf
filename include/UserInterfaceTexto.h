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

#ifndef _USERINTERFACETEXTO_H
#define _USERINTERFACETEXTO_H

#ifndef __gnu_linux__
#include <windows.h>
#endif

#include <fstream>

#include <map>

#include <string>

#include "UtilLog.h"

//Descri��o: 
//    Classe para carregar textos
//Motiva��o:
//    Possibilitar que os textos usados no jogo possam ser carregados de arquivos externos
class UserInterfaceTexto
{
  protected:
    //Lista com os c�digos e textos correspondentes
    
    std::map<std::string,std::string> mapaTexto;

    //Lista com os idiomas suportados
    std::map<std::string,std::string> idiomaSuportado;

    //Prefixo do idioma selecionado
    
    std::string idiomaPrefixo;

    static UserInterfaceTexto * instance;


  private:
    //arquivo de localiza��o a ser carregado
    
    std::string arquivo;

    //Caminho padr�o de localiza��o dos arquivos
    static std::string pathBase;


  public:
    ~UserInterfaceTexto();

    static UserInterfaceTexto * getInstance();

    //Configura o caminho do arquivo de  mensagens
    static void setPathBase(std::string & path);

    //Configura um idioma
    //Obs.: O idioma � configurado de acordo com a lista de idiomas suportado
    bool setIdioma(const std::string & codigo);

    std::string getIdioma();

    //Seleciona o idioma automaticamente de acordo com o ambiente
    void detectarIdioma();

    bool atualizar();

    void setArquivo(const std::string & arquivo);

    int size();

    std::string getTexto(const std::string & chave);

    //Retorna se existe a chave de texto
    bool isChaveTexto(const std::string & chave);


  protected:
    void parser(char * info);

    void carregarIdioma();

    void parserIdioma(char * info);

    void limpar();


  private:
    UserInterfaceTexto();

};
#endif
