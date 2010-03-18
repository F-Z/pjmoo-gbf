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

#ifndef _CURSOR_H
#define _CURSOR_H

#include "ImageBase.h"
#include <string>

#include "GBF.h"

namespace GBF {

namespace Kernel {

namespace Input {

//Descrição:
//    Classe para representação do ponteiro do mouse
//Motivação:
//    Prover o gerenciamento do ponteiro do mouse

class Cursor : public GBF::Kernel::Graphic::ImageBase {
  public:
    //Destrutor
    virtual ~Cursor();

    //Carregar arquivo contendo a imagem do ponteiro
    virtual bool loadFromFile(std::string arquivo);


  protected:
    //Desenha o ponteiro na tela
    void desenhar(int x, int y);


  private:
    //Construtor
    Cursor();

    GBF::Point ponto;

  friend class Mouse;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
