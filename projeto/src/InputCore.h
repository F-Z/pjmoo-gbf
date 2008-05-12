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

#ifndef _INPUTCORE_H
#define _INPUTCORE_H

#include <SDL/SDL.h>

#include "InputSystem.h"
#include "InputSystemUtility.h"
#include "BaseSystem.h"

namespace GBF {

namespace Kernel {

namespace Input {

//Descri��o: 
//    Classe para inicializa��o e gerenciamento do sistema de controle de intera��o do usu�rio
//Motiva��o:
//    Gerenciar o uso dos eventos do usu�rio

class InputCore : public GBF::BaseSystem {
  public:
    //Destrutor
    virtual ~InputCore();

    //Alterna entre input exclusivo e compartilhado
    void alternarControleExclusivo();

    //Retorna como est� configurado o modo de input
    SDL_GrabMode getControleExclusivo();

    //Retorna o evento lan�ado para o SubSistema de Input
    SDL_Event * getEvento();

    void iniciar();

    //Processa os eventos referentes aos mouse, teclado e joystick
    void processar();

    //Configura o controle do teclado, mouse e joystick como exclusivo da aplica��o
    void setControleExclusivo(SDL_GrabMode valor);


  protected:
    SDL_Event evento;


  private:
    SDL_GrabMode controleExclusivo;


  public:
    //Construtor
    InputCore();

    InputSystem * inputSystem;

};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
