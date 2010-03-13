////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2009 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://www.davidferreira.com.br
////////////////////////////////////////////////////////////////////////

#ifndef _LANGUAGE_H
#define _LANGUAGE_H

#ifndef __gnu_linux__
#include <windows.h>
#endif

#include <cstdlib>
#include <fstream>

#include <map>

#include <string>

#include "Path.h"
#include <iostream>


namespace GBF {

namespace Kernel {

namespace Write {

//Descrição:
//    Classe para carregar textos
//Motivação:
//    Possibilitar que os textos usados no jogo possam ser carregados de arquivos externos
class Language
{
  protected:
    //Lista com os códigos e textos correspondentes

    std::map<std::string,std::string> mapaTexto;

    //Lista com os idiomas suportados
    std::map<std::string,std::string> idiomaSuportado;

    //Prefixo do idioma selecionado

    std::string prefix;

    static Language * instance;


  private:
    //arquivo de localização a ser carregado

    std::string fileName;


  public:
    ~Language();

    static Language * getInstance();

    //Configura um idioma
    //Obs.: O idioma é configurado de acordo com a lista de idiomas suportado
    bool setLanguage(const std::string & codigo);

    std::string getLanguage();

    //Seleciona o idioma automaticamente de acordo com o ambiente
    void autodetect();

    bool refresh();

    void setFileName(const std::string & fileName);

    int size();

    std::string getText(const std::string & key);

    //Retorna se existe a chave de texto
    bool isKey(const std::string & key);


  protected:
    void parser(char * info);

    //Carrega o mapeamento de idiomas e os arquivos de texto
    void load();

    void parserLanguage(char * info);

    void clear();


  private:
    Language();

};

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
#endif
