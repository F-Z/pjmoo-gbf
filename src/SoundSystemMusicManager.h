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

#ifndef _SOUNDSYSTEMMUSICMANAGER_H
#define _SOUNDSYSTEMMUSICMANAGER_H

#include <map>

#include <string>

#include "SoundSystemMusic.h"
#include "SoundSystemStatus.h"
#include "SoundSystemInterfaceManager.h"

//Descrição: 
//    Classe para gerenciamento de Música
//Motivação:
//    Fornecer mecanismos para gerenciamento de músicas de fundo
class SoundSystemMusicManager : public SoundSystemInterfaceManager {
  protected:
    std::map<std::string,SoundSystemMusic*> objetomap;


  private:
    std::string musicaTocando;


  public:
    //Destrutor
    virtual ~SoundSystemMusicManager();

    //Toca uma música
    virtual void play(std::string nome);

    //Carregar um arquivo de música para o gerenciador
    virtual void carregar(std::string nome, std::string arquivo);

    //Remove uma música do gerenciador
    virtual void apagar(std::string nome);

    //Pausa a música
    virtual void pause();

    //Continuar a tocar a música
    virtual void resume();

    //Toca uma música uma certa quantidade de vezes
    void playLoop(const std::string & nome, int vezes);

    //Toca uma música de repetitiva
    void playInfinity(const std::string & nome);

    //Para uma música
    void stop(const std::string & nome);


  private:
    //Construtor
    SoundSystemMusicManager(SoundSystemStatus * status);

  friend class SoundSystem;
};
#endif
