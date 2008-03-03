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
////////////////////////////////////////////////////////////////////////

#ifndef _SOUNDSYSTEMCORE_H
#define _SOUNDSYSTEMCORE_H

#include "SoundSystem.h"
#include "SoundSystemStatus.h"
#include "UtilLog.h"
#include "GBF_define.h"
#include "SoundSystemUtility.h"
#include "BaseSystem.h"

//Descrição: 
//    Valores para indicação dos canais de audio
//Motivação:
//    Fornecer um conjunto de valores para configuração do modo de audio
enum SoundSystemCanal {
  CANAL_MONO = 1,
  CANAL_STEREO =2

};
//Descrição: 
//    Classe para inicialização e gerenciamento do sistema de som
//Motivação:
//    Gerenciar o uso do sistema de som
class SoundSystemCore : public BaseSystem {
  public:
    //Destrutor
    virtual ~SoundSystemCore();

    //Inicializa o sistema de som
    void iniciar(int frequencia, Uint16 formato, SoundSystemCanal canal, Uint16 cache, int quantidadeCanais);

    //Configura sistema sonoro para parar o som
    void setMute(bool mute);

    SoundSystem * soundSystem;


  protected:
    SoundSystemStatus * status;


  private:
    //Construtor
    SoundSystemCore();

  friend class GBF;
};
#endif
