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

#ifndef _PSEFEITO_H
#define _PSEFEITO_H

#include "GraphicSystemUtility.h"
#include "ObjetoBase.h"

namespace ParticleSystem {

//Descrição: 
//    Classe abstrata que permite agrupamente de particulas
//Motivação:
//    Permitir gerenciar um grupo de unidades com ciclo de vida semelhantes
class PSEfeito : public GBF::Kernel::Graphic::GraphicSystemUtility, public GBF::ObjetoBase {
  public:
    //Construtor
    PSEfeito();

    //Destrutor
    virtual ~PSEfeito();

    //Desenha todas as unidades
    virtual void desenhar() = 0;

    //Inicializa o sistema de particulas
    virtual void criar(int x, int y) = 0;

    //Executa as unidades do sistema
    virtual void executar() = 0;

    virtual bool isTerminou() = 0;

};

} // namespace ParticleSystem
#endif
