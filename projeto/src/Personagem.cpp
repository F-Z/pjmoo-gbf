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

#include "Personagem.h"

namespace Personagem {

unsigned int Personagem::IDcontagem=0;

//Destrutor 
Personagem::~Personagem() 
{
//  UtilLog::getInstance()->comentario("\tID:%d",ID);
}
//Desenha o sprite principal do personagem
void Personagem::desenhar() 
{
    sprites["principal"]->desenhar(posicao.x,posicao.y);
}
void Personagem::setAtivo(bool valor) 
{
    ativo=valor;
}
void Personagem::setVivo(bool valor) 
{
    vivo=valor;
}
bool Personagem::isAtivo() 
{
    return ativo;
}
bool Personagem::isVivo() 
{
    return vivo;
}
bool Personagem::isColisao(Personagem * personagem) 
{
    return sprites["principal"]->isColisao(personagem->sprites["principal"]);
}
void Personagem::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;

    if (sprites["principal"]!=NULL){
        sprites["principal"]->setPosicao(posicao.x,posicao.y);
    }
}
void Personagem::setPosicao(GBF::Ponto ponto) 
{
    setPosicao(ponto.x,ponto.y);
}
GBF::Ponto Personagem::getPosicao() 
{
    return posicao;
}
//Adiciona o sprite principal do personagem
bool Personagem::adicionarSpritePrincipal(GBF::Imagem::Sprite::SpritePersonagem * sprite) 
{
    return adicionarSprite(sprite,"principal");
}
//Adiciona o sprites extras do personagem
bool Personagem::adicionarSprite(GBF::Imagem::Sprite::SpritePersonagem * sprite, const std::string & nome) 
{
    if (sprite){
        sprite->animacao.setAutomatico(true);
        sprites[nome]=sprite;
        return true;
    } else {
        return false;
    }
}
GBF::Dimensao Personagem::getDimensao() 
{
    return sprites["principal"]->getTamanho();
}
GBF::Imagem::Sprite::SpritePersonagem * Personagem::getSpritePrincipal() 
{
    return sprites["principal"];
}
GBF::Imagem::Sprite::SpritePersonagem * Personagem::getSprite(const std::string & nome) 
{
    return sprites[nome];
}
//Construtor 
Personagem::Personagem() 
{
    vivo  = true;
    ativo = true;

    delay.acao  = 0;
    delay.tiroA = 0;
    delay.tiroB = 0;
    delay.tiroC = 0;
    delay.tiroD = 0;

    posicao.x   = 0;
    posicao.y   = 0;

    IDcontagem++;
    ID=IDcontagem;
}

} // namespace Personagem
