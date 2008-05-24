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

#ifndef _STRINGEXTRACT_H
#define _STRINGEXTRACT_H

#include <string>


namespace GBF {

namespace Kernel {

namespace Util {

//Descrição: 
//    Classe utilitária para extração de informações relativas ao path de arquivos
//Motivação:
//    Descobrir caminhos de pastas
//    Extrair o nome de aplicativos
class StringExtract
{
  public:
    //Extrai o caminho do diretório base 
    static std::string extractPath(char * fullPath);

    //Extrai o nome do aplicativo
    static std::string extractApplication(char * fullPath);

};

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
#endif
