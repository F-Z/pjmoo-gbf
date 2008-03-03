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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#ifndef _SOUNDSYSTEM_H
#define _SOUNDSYSTEM_H

#include "SoundSystemFxManager.h"
#include "SoundSystemMusicManager.h"

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
    SoundSystemFxManager * fxManager;


  protected:
    static SoundSystem * instance;


  public:
    SoundSystemMusicManager * musicManager;

  friend class SoundSystemCore;
};
#endif
