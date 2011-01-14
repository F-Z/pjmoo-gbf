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
#include "Joystick.h"

namespace GBF {

namespace Kernel {

namespace Input {

/** Destrutor */
Joystick::~Joystick()
{
    //    UtilLog::subSistema("Removendo InputSystemJoystick");
    SDL_JoystickClose(joystick);

    // Finaliza o subsistema de joystick
    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);

    joystick = NULL;
}

/** Retorna se o direcional foi movido para o lado esquerdo */
bool Joystick::isAxeLeft()
{
    if ((joystick) && (axe_horizontal == AXE_LEFT)){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o direcional foi movido para o lado direito */
bool Joystick::isAxeRight()
{
    if ((joystick) && (axe_horizontal == AXE_RIGHT)){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o direcional foi movido para cima */
bool Joystick::isAxeUp()
{

    if ((joystick) && (axe_vertical == AXE_UP)){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o direcional foi movido para baixo */
bool Joystick::isAxeDown()
{
    if ((joystick) && (axe_vertical == AXE_DOWN)){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o botão A foi pressionado */
bool Joystick::isButtonA()
{
    if ((joystick) && (SDL_JoystickGetButton(joystick, JB_A))){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o botão B foi pressionado */
bool Joystick::isButtonB()
{
    if ((joystick) && (SDL_JoystickGetButton(joystick, JB_B))){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o botão C foi pressionado (caso exista) */
bool Joystick::isButtonC()
{
    if ((joystick) && (SDL_JoystickGetButton(joystick, JB_C))){
        return true;
    } else {
        return false;
    }
}

/** Retorna se o botão D foi pressionado (caso exista) */
bool Joystick::isButtonD()
{
    if ((joystick) && (SDL_JoystickGetButton(joystick, JB_D))){
        return true;
    } else {
        return false;
    }
}

/** Construtor */
Joystick::Joystick()
{
    std::cout << "GBF::Kernel::Input::Joystick" << std::endl;

    joystick = NULL;

    if (SDL_InitSubSystem(SDL_INIT_JOYSTICK) >= 0){
        if (SDL_JoystickEventState(SDL_ENABLE) == SDL_ENABLE){
            if ((joystick = SDL_JoystickOpen(0)) != NULL){
                std::cout << "\tSDL: joystick: " << SDL_JoystickName(0) << std::endl;
            } else {
                std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
            }
        } else {
            std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
        }
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
    }
}

/** Processa os eventos do joystick */
void Joystick::update()
{
    int x = 0, y = 0;
    axe_horizontal = AXE_STOP;
    axe_vertical  = AXE_STOP;

    if (joystick){
        x = SDL_JoystickGetAxis(joystick, 0);
        y = SDL_JoystickGetAxis(joystick, 1);

        if (x > 20768){
            axe_horizontal = AXE_RIGHT;
        } else if (x < -20768){
            axe_horizontal = AXE_LEFT;
        }

        if (y > 20768){
            axe_vertical = AXE_DOWN;
        } else if (y < -20768){
            axe_vertical = AXE_UP;
        }
    }
}


} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
