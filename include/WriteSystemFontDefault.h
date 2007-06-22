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

#ifndef _WRITESYSTEMFONTDEFAULT_H
#define _WRITESYSTEMFONTDEFAULT_H

#include <string>


//Descrição: 
//    Classe com as fontes padrões.
//Motivação:
//    Permitir a escrita de textos na tela com fontes padrões
class WriteSystemFontDefault
{
  public:
    static std::string console;

    static std::string pumpdemi;

    static std::string fixedsys;

    static std::string arial;

    static std::string comic;

    static std::string high;

    static std::string stac;

};
#endif
