/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#include "InputSystem.h"

namespace GBF {

namespace Kernel {

namespace Input {

//Destrutor
InputSystem::~InputSystem()
{
    if (keyboard){
        delete(keyboard);
    }

    if (joystick){
        delete(joystick);
    }

    if (mouse){
        delete(mouse);
    }
}

//Retorna uma instancia de InputSystem
InputSystem * InputSystem::getInstance()
{
    if (instance == NULL){
        instance = new InputSystem();
    }

    return instance;
}

InputSystem * InputSystem::instance;

InputSystem::InputSystem()
{
    keyboard = new Keyboard();
    mouse    = new Mouse();
    joystick = new Joystick();
}

//Processa os eventos referentes aos mouse, teclado e joystick
void InputSystem::update()
{
    joystick->update();
    keyboard->update();
    mouse->update();
}

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
