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

//Descrição:
//    Manipular informações de data do Sistema Operacional.
//Motivação:
//    Usado principalmente para obter informações como data e hora
//

class UtilDate
{
  public:
    //Retorna Dia da semana, mês, dia do mês, hora e ano
    static std::string getInfo();

};
#endif
