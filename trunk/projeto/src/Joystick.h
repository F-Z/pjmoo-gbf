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

#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include "Log.h"
#include <SDL/SDL.h>


namespace GBF {

namespace Kernel {

namespace Input {

//Descri��o: 
//    Valores para indica��o dos eixos
//Motiva��o:
//    Fornecer um conjunto de valores para verifica��o dos eixos do joystick
enum JoystickAxe {
  AXE_STOP,
  AXE_LEFT,
  AXE_RIGHT,
  AXE_UP,
  AXE_DOWN

};
//Descri��o: 
//    Valores para indica��o dos bot�es
//Motiva��o:
//    Fornecer um conjunto de valores para verifica��o dos bot�es do joystick
enum JoystickBotao {
  JB_A,
  JB_B,
  JB_C,
  JB_D

};
//Descri��o: 
//    Classe para controle do joystick
//Motiva��o:
//    Prover o controle de eventos por meio do Joystick
class Joystick
{
  public:
    //Destrutor
    virtual ~Joystick();

    //Retorna se o direcional foi movido para o lado esquerdo
    bool isAxeLeft();

    //Retorna se o direcional foi movido para o lado direito
    bool isAxeRight();

    //* Retorna se o direcional foi movido para cima 
    bool isAxeUp();

    //Retorna se o direcional foi movido para baixo
    bool isAxeDown();

    //Retorna se o bot�o A foi pressionado
    bool isButtonA();

    //Retorna se o bot�o B foi pressionado
    bool isButtonB();

    //Retorna se o bot�o C foi pressionado (caso exista)
    bool isButtonC();

    //Retorna se o bot�o D foi pressionado (caso exista)
    bool isButtonD();


  private:
    //Construtor
    Joystick();

    //Processa os eventos do joystick
    void processar();

    SDL_Joystick * joystick;

    JoystickAxe axe_horizontal;

    JoystickAxe axe_vertical;

  friend class InputSystem;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
