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

#define MAIN_SPRITE "main"

namespace Character {

/** Definição de TypeDelay */
struct TypeDelay {
    float action;

    float slotA;

    float slotB;

    float slotC;

    float slotD;

};

/**  Classe para criação de personagens genéricos
Motivação:
    Fornecer uma interface padrão para criação de personagens */
class Character : public GBF::Object {

    public:
        /** Destrutor */
        virtual ~Character();

        /** Desenha o sprite principal do personagem */
        virtual void draw();

        virtual void setActive(bool value);

        virtual void setLife(bool value);

        virtual bool isActive();

        virtual bool isLife();

        virtual bool isCollision(Character * character);

        virtual void setPoint(int x, int y);

        virtual void setPoint(GBF::Point point);

        virtual GBF::Point getPoint();

        /** Adiciona o sprite principal do personagem */
        bool addMainSprite(GBF::Image::Sprite::SpriteCharacter * sprite);

        /** Adiciona o sprites extras do personagem */
        bool addSprite(GBF::Image::Sprite::SpriteCharacter * sprite, const std::string & name);

        virtual void update(GBF::Kernel::Input::InputSystem * input) = 0;

        GBF::Dimension getDimension();

        GBF::Image::Sprite::SpriteCharacter * getMainSprite();

        GBF::Image::Sprite::SpriteCharacter * getSprite(const std::string & name);


    protected:
        /** Construtor */
        Character();

        friend class ListCharacter;

        bool active;

        bool life;

        unsigned int ID;

        std::map<std::string, GBF::Image::Sprite::SpriteCharacter*> sprites;

        TypeDelay delay;

        GBF::Point point;


    private:
        static unsigned int IDCount;

        GBF::Dimension dimension;
};

} // namespace Personagem

#endif
