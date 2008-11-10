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

#ifndef _FX_H
#define _FX_H

#include <SDL/SDL_mixer.h>
#include <string>
#include <iostream>

namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição:
//    Classe para representação de um efeito sonoro
//Motivação:
//    Permitir manipular efeitos sonoros
class FX {
  public:
    //Destrutor
    virtual ~FX();

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
    FX();

  friend class FXManager;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
#endif
