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

#include "Date.h"

namespace GBF {

namespace Kernel {

namespace Util {

//Retorna Dia da semana, mês, dia do mês, hora e ano
std::string Date::getInfo()
{
    time_t tmpTime;
    time(&tmpTime);

    return std::string(ctime(&tmpTime));
}

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
