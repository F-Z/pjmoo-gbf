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
#ifndef _INPUTCORE_H
#define _INPUTCORE_H

#include <SDL/SDL.h>

#include "InputSystem.h"
#include "InputSystemUtility.h"
#include "BaseSystem.h"

namespace GBF {

namespace Kernel {

namespace Input {

/** Classe para inicialização e gerenciamento do sistema de controle de interação do usuário */

class InputCore : public GBF::BaseSystem {

    public:
        /** Construtor */
        InputCore();

        InputSystem * inputSystem;

        /** Destrutor */
        virtual ~InputCore();

        /** Alterna entre input exclusivo e compartilhado */
        void alternarControleExclusivo();

        /** Retorna como está configurado o modo de input */
        SDL_GrabMode getControleExclusivo();

        /** Retorna o evento lançado para o SubSistema de Input */
        SDL_Event * getEvento();

        void start();

        /** Processa os eventos referentes aos mouse, teclado e joystick */
        void update();

        /** Configura o controle do teclado, mouse e joystick como exclusivo da aplicação */
        void setControleExclusivo(SDL_GrabMode valor);


    protected:
        SDL_Event evento;


    private:
        SDL_GrabMode controleExclusivo;

};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF

#endif
