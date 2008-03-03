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

#include "UtilDate.h"

//Retorna Dia da semana, mês, dia do mês, hora e ano
std::string UtilDate::getInfo()
{
    time_t ltime;
    time(&ltime);

    char * hora = ctime(&ltime);
    memcpy(hora+24, "\0", 1 );

    std::string retorno = hora;

//    free(hora);
//    delete(hora);

    return retorno;
}

