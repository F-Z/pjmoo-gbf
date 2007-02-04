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

//Descrição: 
//    Valores para indicação dos botões
//Motivação:
//    Fornecer um conjunto de valores para verificação dos botões do mouse
enum MOUSE_BOTAO {
  MS_NULL,
  MS_LEFT,
  MS_MIDDLE,
  MS_RIGHT

};
//Descrição: 
//    Classe para controle do mouse
//Motivação:
//    Prover o controle de eventos por meio do Mouse
class InputSystemMouse {
  public:
    //Destrutor
    virtual ~InputSystemMouse();

    //Retorna a posição do mouse no eixo X
    int getX();

    //Retorna a posição do mouse no eixo Y
    int getY();

    //Retorna a posição do mouse
    Ponto getPosicao();

    //Carrega o curso do mouse do arquivo
    void carregarArquivo(std::string arquivo);

    //Retorna o InputSystemMouseCursor para manipulação
    InputSystemMouseCursor * getMouseCursor();

    //Configura se exibe ou não o cursor do mouse
    void setMouse(bool show);

    //Retorna se o ponteiro está ativo na tela
    bool isMouse();

    //Verifica se o botão esquerdo foi pressionado
    bool isButtonLeft();

    //Verifica se o botão do meio foi pressionado
    bool isButtonMiddle();

    //Verifica se o botão direito foi pressionado
    bool isButtonRight();

    //Verifica se a combinação de botões foi pressionada
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
