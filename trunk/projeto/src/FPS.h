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

#ifndef _FPS_H
#define _FPS_H

#include <SDL/SDL.h>

#include <iostream>


namespace GBF {

namespace Kernel {

namespace FPS {

//Descrição: 
//    Classe para controle da quantidade de quadros por segundo
//Motivação:
//    Fornecer um mecanismo para controlar a  velocidade de processamento da aplicação
class FPS {
  public:
    //Construtor
    FPS();

    //Destrutor
    virtual ~FPS();

    virtual void processar() = 0;

    //Deve ser chamado antes do loop principal do jogo
    virtual void iniciar() = 0;

    //Retorna o valor do FPS
    virtual int getValor() = 0;

};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF
#endif
