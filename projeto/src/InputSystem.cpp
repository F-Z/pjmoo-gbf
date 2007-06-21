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

#include "InputSystem.h"

//Destrutor
InputSystem::~InputSystem() 
{
    UtilLog::sistema("Removendo InputSystem");

    delete(teclado);
    delete(joystick);
    delete(mouse);
}
//Retorna uma instancia de InputSystem
InputSystem * InputSystem::getInstance()
{
    if (instance == NULL){
        instance = new InputSystem();
    }
    return instance;
}
//Processa os eventos referentes aos mouse, teclado e joystick
void InputSystem::processar() 
{
    joystick->processar();
    teclado->processar();
    mouse->processar();

    SDL_PollEvent(&evento);
}
//Retorna o evento lançado para o SubSistema de Input
SDL_Event * InputSystem::getEvento() 
{
    return &evento;
}
//Alterna entre input exclusivo e compartilhado
void InputSystem::alternarControleExclusivo() 
{
    SDL_GrabMode inputmode = getControleExclusivo();
    setControleExclusivo(inputmode ? SDL_GRAB_OFF : SDL_GRAB_ON);
}
//Configura o controle do teclado, mouse e joystick como exclusivo da aplicação
void InputSystem::setControleExclusivo(SDL_GrabMode valor) 
{
    controleExclusivo=valor;
    SDL_WM_GrabInput(controleExclusivo);
}
//Limpa o estado dos eventos do teclado, joystick
void InputSystem::limparEstado() 
{
    teclado->limparEstado();
    joystick->limparEstado();
}
//Retorna como está configurado o modo de input
SDL_GrabMode InputSystem::getControleExclusivo() 
{
    return controleExclusivo;
}
InputSystem * InputSystem::instance;

//Construtor
//Obs.: Inicializa os Sistemas de Input (Teclado, Mouse, Joystick)
InputSystem::InputSystem() 
{
    UtilLog::sistema("Instanciando InputSystem");
    teclado  = new InputSystemKeyboard();
    mouse    = new InputSystemMouse();
    joystick = new InputSystemJoystick();
}
