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

#include "InputSystemKeyboard.h"

//Destrutor
InputSystemKeyboard::~InputSystemKeyboard() 
{
    UtilLog::subSistema("Removendo InputSystemKeyboard");
}
//Verifica se a tecla foi pressionada
bool InputSystemKeyboard::isKey(SDLKey tecla) 
{
   if (ptecla[tecla]){
        return true;
   } else {
        return false;
   }
}
//Construtor
InputSystemKeyboard::InputSystemKeyboard() 
{
    UtilLog::subSistema("Instanciando InputSystemKeyboard");
    processar();
}
//Processa os eventos do teclado
void InputSystemKeyboard::processar() 
{
   ptecla = SDL_GetKeyState(NULL);
}
//Limpa o estado das teclas
void InputSystemKeyboard::limparEstado() 
{
    for (int i=0; i<SDLK_LAST; i++){
        ptecla[i]=SDL_RELEASED;
    }
}
Uint8 * InputSystemKeyboard::ptecla;

