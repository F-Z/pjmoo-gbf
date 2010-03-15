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

#include "Character.h"

namespace Character {

unsigned int Character::IDCount=0;

//Destrutor
Character::~Character()
{
//  UtilLog::getInstance()->comentario("\tID:%d",ID);
}
//Desenha o sprite principal do personagem
void Character::desenhar()
{
    sprites["main"]->desenhar(point.x,point.y);
}
void Character::setActive(bool value)
{
    active=value;
}
void Character::setLife(bool value)
{
    life=value;
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
    return sprites["main"]->isColisao(character->sprites["main"]);
}
void Character::setPoint(int x, int y)
{
    point.x=x;
    point.y=y;

    if (sprites["main"]!=NULL){
        sprites["main"]->setPosicao(point.x,point.y);
    }
}
void Character::setPoint(GBF::Ponto point)
{
    setPoint(point.x,point.y);
}
GBF::Ponto Character::getPoint()
{
    return point;
}
//Adiciona o sprite principal do personagem
bool Character::addMainSprite(GBF::Imagem::Sprite::SpriteCharacter * sprite)
{
    return addSprite(sprite,"main");
}
//Adiciona o sprites extras do personagem
bool Character::addSprite(GBF::Imagem::Sprite::SpriteCharacter * sprite, const std::string & name)
{
    if (sprite){
        sprite->animacao.setAutomatico(true);
        sprites[name]=sprite;
        return true;
    } else {
        return false;
    }
}
GBF::Dimensao Character::getDimension()
{
    return sprites["main"]->getTamanho();
}
GBF::Imagem::Sprite::SpriteCharacter * Character::getMainSprite()
{
    return sprites["main"];
}
GBF::Imagem::Sprite::SpriteCharacter * Character::getSprite(const std::string & name)
{
    return sprites[name];
}
//Construtor
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
    ID=IDCount;
}

} // namespace Personagem
