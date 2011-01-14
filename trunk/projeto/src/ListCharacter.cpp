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
#include "ListCharacter.h"

namespace Character{

/** Construtor */
ListCharacter::ListCharacter()
{
}

/** Destrutor */
ListCharacter::~ListCharacter()
{
    clear();
}

/** Desenha objetos que estao no container */
void ListCharacter::draw()
{
    if (!list.empty())
    {
        for (unsigned int t = 0; t < list.size(); t++)
        {
            if (list[t])
            {
                list[t]->draw();
            }
        }
    }
}

/** Retorna a quantidade de personagens */
int ListCharacter::size()
{
    return list.size();
}

/** Limpa o container, removendo todos os personagens */
void ListCharacter::clear()
{
    for (unsigned int i = 0; i < list.size(); i++)
    {
        try
        {
            if (list[i])
            {
                delete list[i];
                list[i] = NULL;
            }
        }
        catch (...)
        {
        }
    }

    list.clear();
}

/** Executa as ações de cada personagem */
void ListCharacter::update(GBF::Kernel::Input::InputSystem * input)
{
    if (!list.empty())
    {
        for (unsigned int t = 0; t < list.size(); t++)
        {
            if (list[t] != NULL)
            {
                list[t]->update(input);
            }
        }
    }
}

/** Adiciona um personagem */
void ListCharacter::add(Character * character)
{
    list.push_back(character);
}

/** Remove um personagem */
void ListCharacter::remove(Character * character)
{
    for (int i = list.size() - 1; i >= 0; i--)
    {
        if (list[i] == character)
        {
            delete list[i];
            list[i] = NULL;
            list.erase(list.begin() + i);
        }
    }
}

/** Verifica a colisão entre dois container de personagem */
void ListCharacter::collision(ListCharacter * listCharacter)
{
    Character *l = NULL;
    Character *o = NULL;

    for (int i = 0; i < size(); i++)
    {
        if (((l = getCharacter(i)) != NULL) && (l->isLife()))
        {
            for (int ob = 0; ob < listCharacter->size(); ob++)
            {
                if (((o = listCharacter->getCharacter(ob)) != NULL) && (o->isActive()))
                {
                    if (l->isCollision(o))
                    {
                        l->setLife(false);
                        o->setLife(false);
                        break;
                    }
                }
            }
        }
    }
}

/** Verifica a colisão de um personagem com o container */
void ListCharacter::collision(Character * character)
{
    Character *l = NULL;

    for (int i = 0; i < size(); i++)
    {
        if ((l = getCharacter(i)) != NULL)
        {
            if ((l->isActive()) && (character != NULL))
            {
                if ((character->isActive()) && (l->isCollision(character)))
                {
                    l->setLife(false);
                    character->setLife(false);
                    break;
                }
            }
        }
    }
}

/** Retorna um personagem */
Character * ListCharacter::getCharacter(int index)
{
    return list[index];
}

/**
 * Ordena os personagens.
 * Ordenação padrão baseada no eixo Y, ou seja quanto menor seu Y, mais próximo do inicio da lista,
 * e consequentemente será atualizado(update) e desenhado (draw).
 */
void ListCharacter::sort()
{
    Character *buffer;

    for (unsigned int t = 0; t < list.size() - 1; t++)
    {
        if ((list[t] != NULL) && (list[t+1] != NULL))
        {
            if (list[t]->point.y > list[t+1]->point.y)
            {
                buffer = list[t+1];
                list.erase(list.begin() + (t + 1));
                list.insert(list.begin(), buffer);
            }
        }
    }
}

} // namespace Character
