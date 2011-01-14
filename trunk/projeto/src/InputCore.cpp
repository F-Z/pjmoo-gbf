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
#include "InputCore.h"

namespace GBF {

namespace Kernel {

namespace Input {


/** Construtor */
InputCore::InputCore()
{
}

/** Destrutor */
InputCore::~InputCore()
{
//    UtilLog::sistema("Removendo InputSystem");
    delete(inputSystem);
}

/** Alterna entre input exclusivo e compartilhado */
void InputCore::alternarControleExclusivo()
{
    SDL_GrabMode inputmode = getControleExclusivo();
    setControleExclusivo(inputmode ? SDL_GRAB_OFF : SDL_GRAB_ON);
}

/** Retorna como está configurado o modo de input */
SDL_GrabMode InputCore::getControleExclusivo()
{
    return controleExclusivo;
}

/** Retorna o evento lançado para o SubSistema de Input */
SDL_Event * InputCore::getEvento()
{
    return &evento;
}

void InputCore::start()
{
    std::cout << "GBF::Kernel::Input::InputCore::start()" << std::endl;
    inputSystem = InputSystem::getInstance();

    InputSystemUtility::setInputSystem(inputSystem);
}

/** Processa os eventos referentes aos mouse, teclado e joystick */
void InputCore::update()
{
    inputSystem->update();

    SDL_PollEvent(&evento);
}

/** Configura o controle do teclado, mouse e joystick como exclusivo da aplicação */
void InputCore::setControleExclusivo(SDL_GrabMode valor)
{
    controleExclusivo = valor;
    std::cout << "\tSDL: SDL_WM_GrabInput: " << (bool)controleExclusivo << std::endl;
    SDL_WM_GrabInput(controleExclusivo);
}

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
