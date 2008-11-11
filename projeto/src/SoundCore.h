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

#ifndef _SOUNDCORE_H
#define _SOUNDCORE_H

#include "SoundSystem.h"
#include "SoundStatus.h"
#include <SDL/SDL.h>

#include "SoundSystemUtility.h"
#include "BaseSystem.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição: 
//    Valores para indicação dos canais de audio
//Motivação:
//    Fornecer um conjunto de valores para configuração do modo de audio
enum Canal {
  CANAL_MONO= 1,
  CANAL_STEREO=2

};
//Descrição: 
//    Classe para inicialização e gerenciamento do sistema de som
//Motivação:
//    Gerenciar o uso do sistema de som
class SoundCore : public GBF::BaseSystem {
  public:
    //Destrutor
    virtual ~SoundCore();

    //Inicializa o sistema de som
    void iniciar(int frequencia, Uint16 formato, Canal canal, Uint16 cache, int quantidadeCanais);

    //Configura sistema sonoro para parar o som
    void setMute(bool mute);

    SoundSystem * soundSystem;


  protected:
    SoundStatus * status;


  public:
    //Construtor
    SoundCore();

};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
#endif
