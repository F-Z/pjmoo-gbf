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

#ifndef _INPUTSYSTEMKEYBOARD_H
#define _INPUTSYSTEMKEYBOARD_H

#include "UtilLog.h"
#include "GBF_define.h"

//Descrição: 
//    Classe para controle do teclado
//Motivação:
//    Prover o controle de eventos por meio do Teclado

class InputSystemKeyboard {
  public:
    //Destrutor
    virtual ~InputSystemKeyboard();

    //Verifica se a tecla foi pressionada
    bool isKey(SDLKey tecla);


  private:
    //Construtor
    InputSystemKeyboard();

    //Processa os eventos do teclado
    void processar();

    //Limpa o estado das teclas
    void limparEstado();

    static Uint8 * ptecla;

  friend class InputSystem;
};
#endif
