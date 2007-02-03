#ifndef _PERSONAGEMCONTROLADO_H
#define _PERSONAGEMCONTROLADO_H

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

#include "PersonagemAbstract.h"
#include "InputSystem.h"

//Descri��o: 
//    Classe para cria��o de personagens jogaveis
//Motiva��o:
//    Fornecer uma interface padr�o para cria��o de personagens jogaveis
// 
////TODO: Estudar a possibilidade para unificar PersonagemAutomatico e
//// PersonagemControlado pois hoje j� n�o existe mais diferen�a
class PersonagemControlado : public PersonagemAbstract {
  public:
    //Construtor 
    PersonagemControlado();

    //* Destrutor 
    virtual ~PersonagemControlado();

    virtual void acao(InputSystem * input) = 0;

};
#endif
