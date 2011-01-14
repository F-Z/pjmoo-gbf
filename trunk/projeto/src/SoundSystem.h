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
#ifndef _SOUNDSYSTEM_H
#define _SOUNDSYSTEM_H

#include "FXManager.h"
#include "MusicManager.h"

namespace GBF {

namespace Kernel {

namespace Sound {

class SoundSystem
{

    public:
        //Destrutor
        ~SoundSystem();

        //Retorna uma instância de SoundSystem
        static SoundSystem * getInstance();


    private:
        SoundSystem();


    public:
        FXManager * fxManager;


    protected:
        static SoundSystem * instance;


    public:
        MusicManager * musicManager;

        friend class SoundCore;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF

#endif
