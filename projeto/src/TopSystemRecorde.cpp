////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
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

#include "TopSystemRecorde.h"


void TopSystemRecorde::inicializar()
{
    id=0;
    fase=0;
    tempo=0;
    pontos=0;
    strcpy(nome,"");
    strcpy(dataPublicacao,"");
    strcpy(tipo,"Local");
}
