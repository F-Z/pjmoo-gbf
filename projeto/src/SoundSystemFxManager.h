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

#ifndef _SOUNDSYSTEMFXMANAGER_H
#define _SOUNDSYSTEMFXMANAGER_H

#include <string>

#include "SoundSystemStatus.h"
#include <map>

#include "SoundSystemFx.h"
#include "SoundSystemInterfaceManager.h"

//Descrição: 
//    Classe para gerenciamento de Efeitos sonoros
//Motivação:
//    Fornecer mecanismos para gerenciamento de efeitos sonoros
class SoundSystemFxManager : public SoundSystemInterfaceManager {
  public:
    //Destrutor
    virtual ~SoundSystemFxManager();

    //Toca uma efeito sonoro
    virtual void play(std::string nome);

    //Carregar um arquivo de efeito sonoro para o gerenciador
    virtual void carregar(std::string nome, std::string arquivo);

    //Remove um efeito sonoro do gerenciador
    virtual void apagar(std::string nome);

    //Pausa o efeito sonoro
    virtual void pause();

    //Continuar a tocar o efeito sonoro
    virtual void resume();

    //Toca um efeito sonoro de acordo com as coordenadas
    void playPanEffect(std::string nome, int left, int right);

    //Toca um efeito sonoro detectando em qual caixa está mais próximo
    void playPanEffect(std::string nome, int posicao);

    //Determina a área para calculo de efeito sonoro
    void setLimite(int left, int right);

    //Configura o volume do efeito sonoro
    //Obs.: Valor do volume de 0 ate 128
    virtual void setVolume(std::string nome, int volume);


  private:
    //Construtor
    SoundSystemFxManager(SoundSystemStatus * status);


  protected:
    std::map<std::string,SoundSystemFx*> objetomap;

    int area_left;

    int area_right;

  friend class SoundSystem;
};
#endif
