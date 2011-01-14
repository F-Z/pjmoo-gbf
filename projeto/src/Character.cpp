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
#include "Character.h"

namespace Character {

unsigned int Character::IDCount = 0;

/** Destrutor */
Character::~Character()
{
//  UtilLog::getInstance()->comentario("\tID:%d",ID);
}

/** Desenha o sprite principal do personagem */
void Character::draw()
{
    sprites[GBF_CHARACTER_MAIN_SPRITE]->draw(point.x, point.y);
}

void Character::setActive(bool value)
{
    active = value;
}

void Character::setLife(bool value)
{
    life = value;
}

bool Character::isActive()
{
    return active;
}

bool Character::isLife()
{
    return life;
}

bool Character::isCollision(Character * character)
{
    return sprites[GBF_CHARACTER_MAIN_SPRITE]->isCollision(character->sprites[GBF_CHARACTER_MAIN_SPRITE]);
}

void Character::setPoint(int x, int y)
{
    point.x = x;
    point.y = y;

    if (sprites[GBF_CHARACTER_MAIN_SPRITE] != NULL) {
        sprites[GBF_CHARACTER_MAIN_SPRITE]->setPoint(point.x, point.y);
    }
}

void Character::setPoint(GBF::Point point)
{
    setPoint(point.x, point.y);
}

GBF::Point Character::getPoint()
{
    return point;
}

/** Adiciona o sprite principal do personagem */
bool Character::addMainSprite(GBF::Image::Sprite::SpriteCharacter * sprite)
{
    return addSprite(sprite, GBF_CHARACTER_MAIN_SPRITE);
}

/** Adiciona o sprites extras do personagem */
bool Character::addSprite(GBF::Image::Sprite::SpriteCharacter * sprite, const std::string & name)
{
    if (sprite) {
        sprite->animation.setAutomatic(true);
        sprites[name] = sprite;
        return true;
    } else {
        return false;
    }
}

GBF::Dimension Character::getDimension()
{
    return sprites[GBF_CHARACTER_MAIN_SPRITE]->getTamanho();
}

GBF::Image::Sprite::SpriteCharacter * Character::getMainSprite()
{
    return sprites[GBF_CHARACTER_MAIN_SPRITE];
}

GBF::Image::Sprite::SpriteCharacter * Character::getSprite(const std::string & name)
{
    return sprites[name];
}

/** Construtor */
Character::Character()
{
    life  = true;
    active = true;

    delay.action  = 0;
    delay.slotA = 0;
    delay.slotB = 0;
    delay.slotC = 0;
    delay.slotD = 0;

    point.x   = 0;
    point.y   = 0;

    IDCount++;
    ID = IDCount;
}

} // namespace Character
