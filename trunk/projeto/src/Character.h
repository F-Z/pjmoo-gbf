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
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <map>

#include <string>

#include "SpriteCharacter.h"
#include "GBF.h"
#include "InputSystem.h"
#include "Object.h"


/** Namespace para personagens */
namespace Character {

/** Alias para nomeação interna do sprite principal (MainSprite) */
#define GBF_CHARACTER_MAIN_SPRITE "main"

/**
 * Estrutura auxiliar genérica para armazenamento de definições extras.
 * Pode ser usado para armazenar ou definir o intervalo entre tiros, pulos, corrida
 * e outras ações que o personagem possa necessitar.
 */
struct TypeDelay
{

    float action;

    float slotA;

    float slotB;

    float slotC;

    float slotD;

};

/**
 *  Classe para criação de personagens genéricos.
 *  Fornece uma interface padrão para criação de personagens.
 */
class Character : public GBF::Object {

    public:
        /** Destrutor */
        virtual ~Character();

        /** Desenha o personagem */
        virtual void draw();

        virtual void setActive(bool value);

        virtual void setLife(bool value);

        virtual bool isActive();

        virtual bool isLife();

        /** Verifica se houve colisão entre dois personagem */
        virtual bool isCollision(Character * character);

        /** Posiciona o personagem */
        virtual void setPoint(int x, int y);

        /** Posiciona o Character */
        virtual void setPoint(GBF::Point point);

        /** Retorna a posição do personagem */
        virtual GBF::Point getPoint();

        /** Adiciona o sprite principal (MainSprite) do personagem */
        bool addMainSprite(GBF::Image::Sprite::SpriteCharacter * sprite);

        /** Adiciona o sprites extras do personagem */
        bool addSprite(GBF::Image::Sprite::SpriteCharacter * sprite, const std::string & name);

        /** Atualiza o Personagem. Deve ser utilizado para mover ou fazer verificações do character */
        virtual void update(GBF::Kernel::Input::InputSystem * input) = 0;

        /** Retorna a dimensão do personagem (largura e altura) */
        GBF::Dimension getDimension();

        /** Retorna o sprite princial (MainSprite) do Personagem */
        GBF::Image::Sprite::SpriteCharacter * getMainSprite();

        /** Retorna um sprite
         * @param name Nome dado ao sprite do Personagem
         * @return Sprite
         */
        GBF::Image::Sprite::SpriteCharacter * getSprite(const std::string & name);


    protected:
        /** Construtor */
        Character();

        friend class ListCharacter;

        bool active;

        bool life;

        /** Identificador do personagem */
        unsigned int ID;

        std::map<std::string, GBF::Image::Sprite::SpriteCharacter*> sprites;

        TypeDelay delay;

        /** Posição do personagem */
        GBF::Point point;


    private:
        /** Contador de identificadores dos personagens */
        static unsigned int IDCount;

        /** Dimensão do personagem */
        GBF::Dimension dimension;
};

} // namespace Character

#endif
