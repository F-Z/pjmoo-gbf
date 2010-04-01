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
#include "Score.h"

namespace Score {

void Score::inicializar()
{
    id = 0;
    fase = 0;
    tempo = 0;
    pontos = 0;
    strcpy(nome, "");
    strcpy(dataPublicacao, "");
    strcpy(tipo, "Local");
}

} // namespace Score
