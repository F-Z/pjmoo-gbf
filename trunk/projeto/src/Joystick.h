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
#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <SDL/SDL.h>

#include <iostream>


namespace GBF {

namespace Kernel {

namespace Input {

/**Valores para indicação dos eixos
 Motivação: Fornecer um conjunto de valores para verificação dos eixos do joystick */
enum JoystickAxe {
    AXE_STOP,
    AXE_LEFT,
    AXE_RIGHT,
    AXE_UP,
    AXE_DOWN

};
/** Valores para indicação dos botões
 Motivação: Fornecer um conjunto de valores para verificação dos botões do joystick */
enum JoystickButton {
    JB_A,
    JB_B,
    JB_C,
    JB_D

};
/** Classe para controle do joystick
Motivação:  Prover o controle de eventos por meio do Joystick */

class Joystick
{

    public:
        /** Destrutor */
        virtual ~Joystick();

        /** Retorna se o direcional foi movido para o lado esquerdo */
        bool isAxeLeft();

        /** Retorna se o direcional foi movido para o lado direito */
        bool isAxeRight();

        /** Retorna se o direcional foi movido para cima */
        bool isAxeUp();

        /** Retorna se o direcional foi movido para baixo */
        bool isAxeDown();

        /** Retorna se o botão A foi pressionado */
        bool isButtonA();

        /** Retorna se o botão B foi pressionado */
        bool isButtonB();

        /** Retorna se o botão C foi pressionado (caso exista) */
        bool isButtonC();

        /** Retorna se o botão D foi pressionado (caso exista) */
        bool isButtonD();


    private:
        /** Construtor */
        Joystick();

        /** Processa os eventos do joystick */
        void update();

        SDL_Joystick * joystick;

        JoystickAxe axe_horizontal;

        JoystickAxe axe_vertical;

        friend class InputSystem;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF

#endif
