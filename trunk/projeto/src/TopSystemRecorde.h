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

#ifndef _TOPSYSTEMRECORDE_H
#define _TOPSYSTEMRECORDE_H

#include <string>
//Descrição: 
//    Classe para representar um registro
//Motivação:
//    Armazenar informações sobre o pontuação do jogo
struct TopSystemRecorde
{
    unsigned int id;

    char nome[11];

    unsigned int pontos;

    char dataPublicacao[11];

    char tipo[6];

    unsigned int fase;

    unsigned int tempo;

    void inicializar();

};
#endif
