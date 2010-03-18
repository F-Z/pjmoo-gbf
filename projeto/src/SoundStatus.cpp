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

#include "SoundStatus.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
SoundStatus::~SoundStatus()
{

}

//Verifica se sistema de som está funcionando
bool SoundStatus::isActive()
{
    return active;
}

//Verifica se o som está desligado
bool SoundStatus::isMute()
{
    return mute;
}

//Configurar se o sistema de som está funcionando
void SoundStatus::setActive(bool active)
{
    this->active = active;

    if (!active){
        mute = true;
    }
}

//Configura o sistema de som
void SoundStatus::setMute(bool mute)
{
    if (active){
        this->mute = mute;
    }
}

//Construtor
SoundStatus::SoundStatus()
{
    active = false;
    mute   = false;
}

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
