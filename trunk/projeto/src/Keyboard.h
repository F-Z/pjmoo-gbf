/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <SDL/SDL.h>


namespace GBF {

namespace Kernel {

namespace Input {

/** Classe para controle do teclado
Motivação:    Prover o controle de eventos por meio do Teclado */

class Keyboard {
    public:
        /** Destrutor */
        virtual ~Keyboard();

        /** Verifica se a tecla foi pressionada */
        bool isKey(SDLKey key);


    private:
        /** Construtor */
        Keyboard();

        /** Processa os eventos do teclado */
        void update();

        /** Limpa o estado das teclas */
        void clear();

        static Uint8 * bufferKeys;

        friend class InputSystem;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
