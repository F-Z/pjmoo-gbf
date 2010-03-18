////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

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
