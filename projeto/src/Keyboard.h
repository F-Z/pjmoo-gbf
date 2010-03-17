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

#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <SDL/SDL.h>


namespace GBF {

namespace Kernel {

namespace Input {

//Descrição:
//    Classe para controle do teclado
//Motivação:
//    Prover o controle de eventos por meio do Teclado

class Keyboard {
  public:
    //Destrutor
    virtual ~Keyboard();

    //Verifica se a tecla foi pressionada
    bool isKey(SDLKey tecla);


  private:
    //Construtor
    Keyboard();

    //Processa os eventos do teclado
    void update();

    //Limpa o estado das teclas
    void limparEstado();

    static Uint8 * ptecla;

  friend class InputSystem;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
