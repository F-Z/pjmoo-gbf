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
#ifndef _LISTCHARACTER_H
#define _LISTCHARACTER_H

#include "ListManager.h"
#include "InputSystem.h"
#include "Character.h"
#include <deque>

namespace Character {

/**
 * Classe para cria��o de gerenciadores de personagens.
 * Fornecer uma interface padr�o para cria��o de gerenciadores de personagens.
 */
class ListCharacter : public GBF::ListManager
{
    public:
        /** Construtor */
        ListCharacter();

        /** Destrutor */
        virtual ~ListCharacter();

        /** Desenha os personagens que est�o no container */
        virtual void draw();

        /** Retorna a quantidade de personagens */
        virtual int size();

        /** Limpa o container, removendo todos os personagens */
        virtual void clear();

        /** Executa as a��es de cada personagem */
        virtual void update(GBF::Kernel::Input::InputSystem * input = NULL);

        /** Adiciona um personagem */
        void add(Character * character);

        /** Remove um personagem */
        virtual void remove(Character * character);

        /** Verifica a colis�o entre dois container de personagem */
        virtual void collision(ListCharacter * listCharacter);

        /** Verifica a colis�o de um personagem com o container */
        virtual void collision(Character * character);

        /** Retorna um personagem */
        virtual Character * getCharacter(int index);


    protected:

        /**
         * Ordena os personagens.
         * Ordena��o padr�o baseada no eixo Y, ou seja quanto menor seu Y, mais pr�ximo do inicio da lista,
         * e consequentemente ser� atualizado(update) e desenhado (draw).
         */
        virtual void sort();

        /** Lista de personagem */
        std::deque<Character*> list;
};

} // namespace Character

#endif
