////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#include "Keyboard.h"

namespace GBF {

namespace Kernel {

namespace Input {

//Destrutor
Keyboard::~Keyboard()
{
//    UtilLog::subSistema("Removendo InputSystemKeyboard");
}
//Verifica se a tecla foi pressionada
bool Keyboard::isKey(SDLKey key)
{
   if (ptecla[key]){
        return true;
   } else {
        return false;
   }
}
//Construtor
Keyboard::Keyboard()
{
//    UtilLog::subSistema("Instanciando InputSystemKeyboard");
    update();
}
//Processa os eventos do teclado
void Keyboard::update()
{
   ptecla = SDL_GetKeyState(NULL);
}
//Limpa o estado das teclas
void Keyboard::limparEstado()
{
    for (int i=0; i<SDLK_LAST; i++){
        ptecla[i]=SDL_RELEASED;
    }
}
Uint8 * Keyboard::ptecla;


} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
