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

#ifndef _INPUTSYSTEMMOUSE_H
#define _INPUTSYSTEMMOUSE_H

#include "GBF_define.h"
#include <string>

#include "InputSystemMouseCursor.h"

//Descri��o: 
//    Valores para indica��o dos bot�es
//Motiva��o:
//    Fornecer um conjunto de valores para verifica��o dos bot�es do mouse
enum MOUSE_BOTAO {
  MS_NULL,
  MS_LEFT,
  MS_MIDDLE,
  MS_RIGHT

};
//Descri��o: 
//    Classe para controle do mouse
//Motiva��o:
//    Prover o controle de eventos por meio do Mouse
class InputSystemMouse {
  public:
    //Destrutor
    virtual ~InputSystemMouse();

    //Retorna a posi��o do mouse no eixo X
    int getX();

    //Retorna a posi��o do mouse no eixo Y
    int getY();

    //Retorna a posi��o do mouse
    Ponto getPosicao();

    //Carrega o curso do mouse do arquivo
    void carregarArquivo(std::string arquivo);

    //Retorna o InputSystemMouseCursor para manipula��o
    InputSystemMouseCursor * getMouseCursor();

    //Configura se exibe ou n�o o cursor do mouse
    void setMouse(bool show);

    //Retorna se o ponteiro est� ativo na tela
    bool isMouse();

    //Verifica se o bot�o esquerdo foi pressionado
    bool isButtonLeft();

    //Verifica se o bot�o do meio foi pressionado
    bool isButtonMiddle();

    //Verifica se o bot�o direito foi pressionado
    bool isButtonRight();

    //Verifica se a combina��o de bot�es foi pressionada
    bool isButton(bool left, bool middle, bool right);


  protected:
    InputSystemMouseCursor * cursor;


  private:
    //Construtor
    InputSystemMouse();

    //Processa os eventos do mouse
    void processar();

    Ponto ponto;

    Uint8 botao;

    bool mouse;

  friend class InputSystem;
};
#endif
