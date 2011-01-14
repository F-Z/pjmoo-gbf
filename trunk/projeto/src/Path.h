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
#ifndef _PATH_H
#define _PATH_H

#include <string>


namespace GBF {

namespace Kernel {

namespace Util {

/** Informa o Path da aplica��o.
 Possibilitar que o caminho da aplica��o seja obtido em runtime para a leitura ou grava��o de arquivos */

class Path
{

    public:
        /** Informa o Path para leitura de arquivos */
        static void setPath(const std::string path);

        /** Retorna o path base da aplica��o */
        static std::string getPath();

    private:
        /** Caminho base da aplica��o */
        static std::string path;

};

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF

#endif
