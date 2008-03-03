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

#ifndef _SOUNDSYSTEMFX_H
#define _SOUNDSYSTEMFX_H

#include <SDL/SDL_mixer.h>
#include <string>


//Descrição: 
//    Classe para representação de um efeito sonoro
//Motivação:
//    Permitir manipular efeitos sonoros
class SoundSystemFx {
  public:
    //Destrutor
    virtual ~SoundSystemFx();

    //Lê arquivo de efeito sonoro
    bool carregarArquivo(std::string arquivo);

    //Toca Efeto sonoro
    int play();

    //Configura o volume do efeito, 
    //Obs.: Valor de 0 ate 128
    void setVolume(int valor);


  protected:
    Mix_Chunk * efeito;

    //Construtor
    SoundSystemFx();

  friend class SoundSystemFxManager;
};
#endif
