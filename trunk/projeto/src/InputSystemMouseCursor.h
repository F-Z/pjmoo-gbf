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

#ifndef _INPUTSYSTEMMOUSECURSOR_H
#define _INPUTSYSTEMMOUSECURSOR_H

#include "GraphicSystemImage.h"
#include <string>

#include "GBF_define.h"

//Descrição: 
//    Classe para representação do ponteiro do mouse
//Motivação:
//    Prover o gerenciamento do ponteiro do mouse

class InputSystemMouseCursor : public GraphicSystemImage {
  public:
    //Destrutor
    virtual ~InputSystemMouseCursor();

    //Carregar arquivo contendo a imagem do ponteiro
    virtual bool carregarArquivo(std::string arquivo);


  protected:
    //Desenha o ponteiro na tela
    void desenhar(int x, int y);


  private:
    //Construtor
    InputSystemMouseCursor();

    Ponto ponto;

  friend class InputSystemMouse;
};
#endif
