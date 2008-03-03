////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#ifndef _UTILDATE_H
#define _UTILDATE_H

#include <ctime>
#include <string>

//Descri��o:
//    Manipular informa��es de data do Sistema Operacional.
//Motiva��o:
//    Usado principalmente para obter informa��es como data e hora
//

class UtilDate
{
  public:
    //Retorna Dia da semana, m�s, dia do m�s, hora e ano
    static std::string getInfo();

};
#endif
