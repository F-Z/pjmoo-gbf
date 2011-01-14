/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#include "Path.h"

namespace GBF {

namespace Kernel {

namespace Util {

/** Informa o Path para leitura de arquivos */
void Path::setPath(const std::string path)
{
    Path::path = path;
}

/** Caminho base da aplicação */
std::string Path::path;

/** Retorna o path base da aplicação */
std::string Path::getPath()
{
    return Path::path;
}

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
