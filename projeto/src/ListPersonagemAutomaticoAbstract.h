#ifndef _LISTPERSONAGEMAUTOMATICOABSTRACT_H
#define _LISTPERSONAGEMAUTOMATICOABSTRACT_H

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

#include "ListPersonagemAbstract.h"

//Descrição: 
//    Classe para criação de gerenciadores de personagens NPC
//Motivação:
//    Fornecer uma interface padrão para criação de gerenciadores de personagens NPC
//
// 
class ListPersonagemAutomaticoAbstract : public ListPersonagemAbstract
{
  public:
    //Destrutor 
    virtual ~ListPersonagemAutomaticoAbstract();


  protected:
    //Construtor 
    ListPersonagemAutomaticoAbstract();

};
#endif
