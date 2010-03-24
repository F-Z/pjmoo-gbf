/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _LISTMANAGER_H
#define _LISTMANAGER_H

#include "InputSystem.h"
#include "BaseManager.h"

namespace GBF {

/** Classe para criação de gerenciadores
  Fornecer uma interface padrão para criação de gerenciadores */

class ListManager : public BaseManager
{

    public:
        /** Construtor */
        ListManager();

        /** Destrutor */
        virtual ~ListManager();

        /** Desenha objetos que estao no container */
        virtual void draw() = 0;

        /** Retorna a quantidade de elementos */
        virtual int size() = 0;

        /** Limpa o container, removendo todos os elementos */
        virtual void clear() = 0;

        /** Executa as ações de cada elemento */
        virtual void update(GBF::Kernel::Input::InputSystem * input) = 0;


    protected:
        //Ordena os elementos */
        virtual void sort() = 0;

};

} // namespace GBF

#endif
