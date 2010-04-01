/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _SCORE_H
#define _SCORE_H

#include <string>
#include <cstring>

namespace Score {

/**
 * Estrutura para representar um registro.
 * Armazenar informações sobre o pontuação do jogo.
 */
struct Score
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

} // namespace Score
#endif
