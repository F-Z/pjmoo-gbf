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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#ifndef _INPUTSYSTEM_H
#define _INPUTSYSTEM_H

#include "Joystick.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace GBF {

namespace Kernel {

namespace Input {

class InputSystem
{
  public:
    Joystick * joystick;

    Keyboard * teclado;

    Mouse * mouse;

    //Destrutor
    ~InputSystem();

    //Retorna uma instancia de InputSystem
    static InputSystem * getInstance();


  protected:
    static InputSystem * instance;

    InputSystem();


  private:
    //Processa os eventos referentes aos mouse, teclado e joystick
    void processar();

  friend class InputCore;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
