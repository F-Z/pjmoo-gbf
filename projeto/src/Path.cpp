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

#include "Path.h"

namespace GBF {

namespace Kernel {

namespace Util {

//Informa o Path para leitura de arquivos
void Path::setPath(const std::string path)
{
    Path::path=path;
}
//Caminho base da aplicação
std::string Path::path;

//Retorna o path base da aplicação
std::string Path::getPath()
{
    return Path::path;
}

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
