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
#include "SoundSystem.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
SoundSystem::~SoundSystem()
{
    if (musicManager){
        delete(musicManager);
    }

    if (fxManager){
        delete(fxManager);
    }
}

//Retorna uma inst�ncia de SoundSystem
SoundSystem * SoundSystem::getInstance()
{
    if (instance == NULL){
        instance = new SoundSystem();
    }

    return instance;
}

SoundSystem::SoundSystem()
{
    std::cout << "GBF::Kernel::Sound::SoundSystem" << std::endl;
    musicManager = new MusicManager();
    fxManager    = new FXManager();
}

SoundSystem * SoundSystem::instance;


} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
