/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
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

        virtual void update() = 0;

        //Deve ser chamado antes do loop principal do jogo
        virtual void start() = 0;

        //Retorna o valor do FPS
        virtual int getValue() = 0;

};

} // namespace GBF::Kernel::FPS

} // namespace GBF::Kernel

} // namespace GBF

#endif
