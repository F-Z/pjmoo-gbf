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
#include "Keyboard.h"

namespace GBF {

namespace Kernel {

namespace Input {

/** Destrutor */
Keyboard::~Keyboard()
{
//    UtilLog::subSistema("Removendo InputSystemKeyboard");
}
/** Verifica se a tecla foi pressionada */
bool Keyboard::isKey(SDLKey key)
{
    if (bufferKeys[key]){
        return true;
    } else {
        return false;
    }
}
/** Construtor */
Keyboard::Keyboard()
{
//    UtilLog::subSistema("Instanciando InputSystemKeyboard");
    update();
}
/** Processa os eventos do teclado */
void Keyboard::update()
{
    bufferKeys = SDL_GetKeyState(NULL);
}
/** Limpa o estado das teclas */
void Keyboard::clear()
{
    for (int i = 0; i < SDLK_LAST; i++){
        bufferKeys[i] = SDL_RELEASED;
    }
}
Uint8 * Keyboard::bufferKeys;


} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
