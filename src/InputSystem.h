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

#ifndef _INPUTSYSTEM_H
#define _INPUTSYSTEM_H

#include "InputSystemKeyboard.h"
#include "InputSystemMouse.h"
#include "InputSystemJoystick.h"
#include "GBF_define.h"

//Descrição: 
//    Classe para inicialização e gerenciamento do sistema de controle de interação do usuário
//Motivação:
//    Gerenciar o uso dos eventos do usuário

class InputSystem {
  public:
    //Destrutor
    virtual ~InputSystem();

    //Retorna uma instancia de InputSystem
    static InputSystem * getInstance();

    //Processa os eventos referentes aos mouse, teclado e joystick
    void processar();

    //Retorna o evento lançado para o SubSistema de Input
    SDL_Event * getEvento();

    //Alterna entre input exclusivo e compartilhado
    void alternarControleExclusivo();

    //Configura o controle do teclado, mouse e joystick como exclusivo da aplicação
    void setControleExclusivo(SDL_GrabMode valor);

    //Limpa o estado dos eventos do teclado, joystick
    void limparEstado();

    //Retorna como está configurado o modo de input
    SDL_GrabMode getControleExclusivo();

    InputSystemKeyboard * teclado;

    InputSystemMouse * mouse;

    InputSystemJoystick * joystick;


  protected:
    static InputSystem * instance;

    SDL_Event evento;


  private:
    //Construtor
    //Obs.: Inicializa os Sistemas de Input (Teclado, Mouse, Joystick)
    InputSystem();

    SDL_GrabMode controleExclusivo;

};
#endif
