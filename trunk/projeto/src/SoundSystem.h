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

#ifndef _SOUNDSYSTEM_H
#define _SOUNDSYSTEM_H

#include "SoundSystemMusicManager.h"
#include "SoundSystemFxManager.h"
#include "SoundSystemStatus.h"
#include "UtilLog.h"
#include "GBF_define.h"

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
class SoundSystem {
  public:
    //Destrutor
    virtual ~SoundSystem();

    //Retorna uma instância de SoundSystem
    static SoundSystem * getInstance();

    //Inicializa o sistema de som
    void iniciar(int frequencia, Uint16 formato, SoundSystemCanal canal, Uint16 cache, int quantidadeCanais);

    //Configura sistema sonoro para parar o som
    void setMute(bool mute);

    SoundSystemMusicManager * musicManager;

    SoundSystemFxManager * fxManager;


  protected:
    SoundSystemStatus * status;


  private:
    //Construtor
    SoundSystem();

    static SoundSystem * instance;

};
#endif
