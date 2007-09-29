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

#ifndef _SOUNDSYSTEMINTERFACEMANAGER_H
#define _SOUNDSYSTEMINTERFACEMANAGER_H

#include <string>

#include "SoundSystemStatus.h"
#include "UtilLog.h"

//Descrição: 
//    Classe para criação de gerenciados de som
//Motivação:
//    Fornecer uma interface padrão para gerenciamento de som
class SoundSystemInterfaceManager {
  public:
    //Destrutor
    virtual ~SoundSystemInterfaceManager();

    //Construtor
    SoundSystemInterfaceManager();

    //Apaga o arquivo de som do gerenciador
    virtual void apagar(std::string nome) = 0;

    //Carrega no manager o arquivo de som
    virtual void carregar(std::string nome, std::string arquivo) = 0;

    //Pausa o sistema de som
    virtual void pause() = 0;

    //Toca um som
    virtual void play(std::string nome) = 0;

    //Continua a tocar o som
    virtual void resume() = 0;

    //Configura o volume do som
    //Obs.: Valor do volume de 0 ate 128
    virtual void setVolume(std::string nome, int volume) = 0;

    //Informa PathBase para leitura de arquivos
    static void setPathBase(std::string path);


  private:
    static void setStatus(SoundSystemStatus * instance);


  protected:
    static std::string pathBase;

    static SoundSystemStatus * status;

  friend class SoundSystemCore;
};
#endif
