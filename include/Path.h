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

#ifndef _PATH_H
#define _PATH_H

#include <string>


namespace GBF {

namespace Kernel {

namespace Util {

//Descrição: 
//    Informa o Path da aplicação
//Motivação:
//    Possibilitar que o caminho da aplicação seja obtido em runtime para a leitura ou gravação de arquivos
class Path
{
  public:
    //Informa o Path para leitura de arquivos
    static void setPath(const std::string path);


  private:
    //Caminho base da aplicação
    static std::string path;


  public:
    //Retorna o path base da aplicação
    static std::string getPath();

};

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
#endif
