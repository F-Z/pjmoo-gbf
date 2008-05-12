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

#ifndef _MUSIC_H
#define _MUSIC_H

#include <SDL/SDL_mixer.h>
#include <string>


namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição: 
//    Classe para representação de músicas
//Motivação:
//    Permitir manipular músicas (trila sonora)
class Music {
  public:
    //Destrutor
    virtual ~Music();

    //Lê arquivo de música
    bool carregarArquivo(std::string arquivo);

    //Toca Música de Fundo
    void play();

    //Toca Música de Fundo de forma infinita
    void playInfinity();

    //Toca Música de Fundo várias vezes
    void playLoop(int vezes);

    //Configura o volume da música
    //Obs.: Valor de 0 ate 128 
    void setVolume(int valor);

    //Para a música
    void stop();


  protected:
    Mix_Music * musica;

    //Construtor
    Music();

  friend class MusicManager;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
#endif
