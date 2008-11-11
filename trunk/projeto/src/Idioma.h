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

#ifndef _IDIOMA_H
#define _IDIOMA_H

#ifndef __gnu_linux__
#include <windows.h>
#endif

#include <fstream>

#include <map>
#include <iostream>
#include <string>


#include "Path.h"

namespace GBF {

namespace Kernel {

namespace Write {

//Descrição:
//    Classe para carregar textos
//Motivação:
//    Possibilitar que os textos usados no jogo possam ser carregados de arquivos externos
class Idioma
{
  protected:
    //Lista com os códigos e textos correspondentes

    std::map<std::string,std::string> mapaTexto;

    //Lista com os idiomas suportados
    std::map<std::string,std::string> idiomaSuportado;

    //Prefixo do idioma selecionado

    std::string idiomaPrefixo;

    static Idioma * instance;


  private:
    //arquivo de localização a ser carregado

    std::string arquivo;


  public:
    ~Idioma();

    static Idioma * getInstance();

    //Configura um idioma
    //Obs.: O idioma é configurado de acordo com a lista de idiomas suportado
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

    //Carrega o mapeamento de idiomas e os arquivos de texto
    void carregarIdioma();

    void parserIdioma(char * info);

    void limpar();


  private:
    Idioma();

};

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
#endif
