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
#include "SoundManagerAbstract.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
SoundManagerAbstract::~SoundManagerAbstract()
{
    status = NULL;
}

//Construtor
SoundManagerAbstract::SoundManagerAbstract()
{
    if (status->isActive()){
        //UtilLog::getInstance()->status("[Ok]");
    } else {
        //UtilLog::getInstance()->status("[Falhou]");
    }
}

void SoundManagerAbstract::setStatus(SoundStatus * instance)
{
    status = instance;
}

SoundStatus * SoundManagerAbstract::status = NULL;


} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
