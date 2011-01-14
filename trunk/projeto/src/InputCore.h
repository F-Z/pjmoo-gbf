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

/** Classe para inicializa��o e gerenciamento do sistema de controle de intera��o do usu�rio */

class InputCore : public GBF::BaseSystem {

    public:
        /** Construtor */
        InputCore();

        InputSystem * inputSystem;

        /** Destrutor */
        virtual ~InputCore();

        /** Alterna entre input exclusivo e compartilhado */
        void alternarControleExclusivo();

        /** Retorna como est� configurado o modo de input */
        SDL_GrabMode getControleExclusivo();

        /** Retorna o evento lan�ado para o SubSistema de Input */
        SDL_Event * getEvento();

        void start();

        /** Processa os eventos referentes aos mouse, teclado e joystick */
        void update();

        /** Configura o controle do teclado, mouse e joystick como exclusivo da aplica��o */
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
