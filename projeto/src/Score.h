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
#ifndef _SCORE_H
#define _SCORE_H

#include <string>
#include <cstring>

/** Namespace para Galeria de Recordes (Top 10). */
namespace Score {

/**
 * Estrutura para representar um registro.
 * Armazenar informações sobre o pontuação do jogo.
 */
struct Score
{
    unsigned int id;

    char name[11];

    unsigned int score;

    char date[11];

    char type[6];

    unsigned int stage;

    unsigned int time;

    /** Inicializa todos os atributos */
    void initialize();

};

} // namespace Score
#endif
