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

#ifndef _DATE_H
#define _DATE_H

#include <ctime>
#include <string>

namespace GBF {

namespace Kernel {

namespace Util {

//Descri��o: 
//    Manipular informa��es de data do Sistema Operacional.
//Motiva��o:
//    Usado principalmente para obter informa��es como data e hora
//

class Date
{
  public:
    //Retorna Dia da semana, m�s, dia do m�s, hora e ano
    static std::string getInfo();

};

} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
#endif
