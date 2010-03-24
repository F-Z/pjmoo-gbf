/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "StringExtract.h"

namespace GBF {

namespace Kernel {

namespace Util {

/** Extrai o caminho do diretório base */
std::string StringExtract::extractPath(char * fullPath)
{
    int i = 0;
    std::string path = fullPath;
    std::string pathBase  = "";

    for (i = path.length();i >= 0;i--){
        if ((path[i] == '\\') || (path[i] == '/')) {
            i++;
            break;
        }
    }

    if (i >= 0){
        pathBase = path.substr(0, i);
    }

    return pathBase;
}

/** Extrai o nome do aplicativo */
std::string StringExtract::extractApplication(char * fullPath)
{
    int i = 0;
    std::string path = fullPath;
    std::string nomeAplicacao = "";

    for (i = path.length();i >= 0;i--){
        if ((path[i] == '\\') || (path[i] == '/')) {
            break;
        }
    }

    if (i >= 0){
        nomeAplicacao = path.substr(i, path.length());
    }

    return nomeAplicacao;
}


} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
