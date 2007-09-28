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

#include "InputSystem.h"

//Destrutor
InputSystem::~InputSystem() 
{
    if (teclado){
        delete(teclado);
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
    teclado  = new InputSystemKeyboard();
    mouse    = new InputSystemMouse();
    joystick = new InputSystemJoystick();
}
//Processa os eventos referentes aos mouse, teclado e joystick
void InputSystem::processar() 
{
    joystick->processar();
    teclado->processar();
    mouse->processar();
}
