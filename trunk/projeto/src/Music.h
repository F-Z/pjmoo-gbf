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

//Descri��o: 
//    Classe para representa��o de m�sicas
//Motiva��o:
//    Permitir manipular m�sicas (trila sonora)
class Music {
  public:
    //Destrutor
    virtual ~Music();

    //L� arquivo de m�sica
    bool carregarArquivo(std::string arquivo);

    //Toca M�sica de Fundo
    void play();

    //Toca M�sica de Fundo de forma infinita
    void playInfinity();

    //Toca M�sica de Fundo v�rias vezes
    void playLoop(int vezes);

    //Configura o volume da m�sica
    //Obs.: Valor de 0 ate 128 
    void setVolume(int valor);

    //Para a m�sica
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
