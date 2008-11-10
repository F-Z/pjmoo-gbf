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

#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include <cstdarg>

#include <string>

#include "Date.h"
#include "StringExtract.h"

namespace GBF {

namespace Kernel {

namespace Util {

//Descrição:
//    Classe para criação de logs
//Motivação:
//     Catalogar informações de execução
//     Informar se todos os arquivos necessários foram carregados
//     Gerar relatório com indicações para descobrir erros
class Log
{
  public:

    static void setArquivo(std::string arquivo);

    static void setAutor(std::string autor);

    static void setProjeto(std::string projeto);

    static void iniciar();

    static void finalizar();

    static void cabecalho(const char * texto);

    static void sistema(const char * texto, ...);

    static void subSistema(const char * texto, ...);

    static void comentario(const char * texto, ...);

    static void comentarioComQuebra(const char * texto, ...);

    static void tracer(const char * texto, ...);


  protected:
    static std::string arquivo;

    static std::string autor;

    static std::string projeto;

    static FILE * handleArquivo;

    static void escrever(const char * texto, ...);

};

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
#endif
