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
#ifndef _STRINGEXTRACT_H
#define _STRINGEXTRACT_H

#include <string>


namespace GBF {

namespace Kernel {

namespace Util {

/** Classe utilitária para extração de informações relativas ao path de arquivos */

class StringExtract
{

    public:
        /** Extrai o caminho do diretório base */
        static std::string extractPath(char * fullPath);

        /** Extrai o nome do aplicativo */
        static std::string extractApplication(char * fullPath);

};

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF

#endif
