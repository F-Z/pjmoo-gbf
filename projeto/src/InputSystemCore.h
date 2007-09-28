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

#ifndef _INPUTSYSTEMCORE_H
#define _INPUTSYSTEMCORE_H

#include "GBF_define.h"
#include "InputSystem.h"
#include "InputSystemUtility.h"

//Descrição: 
//    Classe para inicialização e gerenciamento do sistema de controle de interação do usuário
//Motivação:
//    Gerenciar o uso dos eventos do usuário

class InputSystemCore {
  public:
    //Destrutor
    virtual ~InputSystemCore();

    //Alterna entre input exclusivo e compartilhado
    void alternarControleExclusivo();

    //Retorna como está configurado o modo de input
    SDL_GrabMode getControleExclusivo();

    //Retorna o evento lançado para o SubSistema de Input
    SDL_Event * getEvento();

    void iniciar();

    //Processa os eventos referentes aos mouse, teclado e joystick
    void processar();

    //Configura o controle do teclado, mouse e joystick como exclusivo da aplicação
    void setControleExclusivo(SDL_GrabMode valor);


  protected:
    SDL_Event evento;


  private:
    SDL_GrabMode controleExclusivo;

    //Construtor
    InputSystemCore();


  public:
    InputSystem * inputSystem;

  friend class GBF;
};
#endif
