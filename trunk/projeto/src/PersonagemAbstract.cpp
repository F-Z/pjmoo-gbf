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

unsigned int PersonagemAbstract::IDcontagem=0;

//Destrutor 
PersonagemAbstract::~PersonagemAbstract() 
{
//  UtilLog::getInstance()->comentario("\tID:%d",ID);
}
//Desenha o sprite principal do personagem
void PersonagemAbstract::desenhar() 
{
    sprites["principal"]->desenhar(posicao.x,posicao.y);
}
void PersonagemAbstract::setAtivo(bool valor) 
{
    ativo=valor;
}
void PersonagemAbstract::setVivo(bool valor) 
{
    vivo=valor;
}
bool PersonagemAbstract::isAtivo() 
{
    return ativo;
}
bool PersonagemAbstract::isVivo() 
{
    return vivo;
}
bool PersonagemAbstract::isColisao(PersonagemAbstract * personagem) 
{
    return sprites["principal"]->isColisao(personagem->sprites["principal"]);
}
void PersonagemAbstract::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;

    if (sprites["principal"]!=NULL){
        sprites["principal"]->setPosicao(posicao.x,posicao.y);
    }
}
void PersonagemAbstract::setPosicao(Ponto ponto) 
{
    setPosicao(ponto.x,ponto.y);
}
Ponto PersonagemAbstract::getPosicao() 
{
    return posicao;
}
//Adiciona o sprite principal do personagem
bool PersonagemAbstract::adicionarSpritePrincipal(SpritePersonagem * sprite) 
{
    return adicionarSprite(sprite,"principal");
}
//Adiciona o sprites extras do personagem
bool PersonagemAbstract::adicionarSprite(SpritePersonagem * sprite, const std::string & nome) 
{
    if (sprite){
        sprite->animacao.setAutomatico(true);
        sprites[nome]=sprite;
        return true;
    } else {
        return false;
    }
}
Dimensao PersonagemAbstract::getDimensao() 
{
    return sprites["principal"]->getTamanho();
}
SpritePersonagem * PersonagemAbstract::getSpritePrincipal() 
{
    return sprites["principal"];
}
SpritePersonagem * PersonagemAbstract::getSprite(const std::string & nome) 
{
    return sprites[nome];
}
//Construtor 
PersonagemAbstract::PersonagemAbstract() 
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
