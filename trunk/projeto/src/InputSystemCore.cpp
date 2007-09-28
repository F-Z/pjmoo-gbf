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

#include "InputSystemCore.h"

//Destrutor
InputSystemCore::~InputSystemCore() 
{
    UtilLog::sistema("Removendo InputSystem");

    delete(inputSystem);
}
//Alterna entre input exclusivo e compartilhado
void InputSystemCore::alternarControleExclusivo() 
{
    SDL_GrabMode inputmode = getControleExclusivo();
    setControleExclusivo(inputmode ? SDL_GRAB_OFF : SDL_GRAB_ON);
}
//Retorna como está configurado o modo de input
SDL_GrabMode InputSystemCore::getControleExclusivo() 
{
    return controleExclusivo;
}
//Retorna o evento lançado para o SubSistema de Input
SDL_Event * InputSystemCore::getEvento() 
{
    return &evento;
}
void InputSystemCore::iniciar() 
{
    inputSystem = InputSystem::getInstance();

    InputSystemUtility::setInputSystem(inputSystem);
}
//Processa os eventos referentes aos mouse, teclado e joystick
void InputSystemCore::processar() 
{
    inputSystem->processar();

    SDL_PollEvent(&evento);
}
//Configura o controle do teclado, mouse e joystick como exclusivo da aplicação
void InputSystemCore::setControleExclusivo(SDL_GrabMode valor) 
{
    controleExclusivo=valor;
    SDL_WM_GrabInput(controleExclusivo);
}
//Construtor
InputSystemCore::InputSystemCore() 
{
}
