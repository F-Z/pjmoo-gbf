#ifndef _PERSONAGEM_H
#define _PERSONAGEM_H

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

#include <map>

#include <string>

#include "SpritePersonagem.h"
#include "GBF_define.h"
#include "InputSystem.h"
#include "ObjetoBase.h"

namespace Personagem {

//Definição de TypeDelay
struct TypeDelay
{
    float acao;

    float tiroA;

    float tiroB;

    float tiroC;

    float tiroD;

};
//Descrição: 
//    Classe para criação de personagens genéricos
//Motivação:
//    Fornecer uma interface padrão para criação de personagens 
//
// 
class Personagem : public GBF::ObjetoBase
{
  protected:
    bool ativo;

    bool vivo;

    unsigned int ID;

    std::map<std::string,GBF::Grafico::Sprite::SpritePersonagem*> sprites;

    TypeDelay delay;

    ::Ponto posicao;


  private:
    static unsigned int IDcontagem;

    ::Dimensao dimensao;


  public:
    //Destrutor 
    virtual ~Personagem();

    //Desenha o sprite principal do personagem
    virtual void desenhar();

    virtual void setAtivo(bool valor);

    virtual void setVivo(bool valor);

    virtual bool isAtivo();

    virtual bool isVivo();

    virtual bool isColisao(Personagem * personagem);

    virtual void setPosicao(int x, int y);

    virtual void setPosicao(::Ponto ponto);

    virtual ::Ponto getPosicao();

    //Adiciona o sprite principal do personagem
    bool adicionarSpritePrincipal(GBF::Grafico::Sprite::SpritePersonagem * sprite);

    //Adiciona o sprites extras do personagem
    bool adicionarSprite(GBF::Grafico::Sprite::SpritePersonagem * sprite, const std::string & nome);

    virtual void acao(GBF::Kernel::Input::InputSystem * input) = 0;

    ::Dimensao getDimensao();

    GBF::Grafico::Sprite::SpritePersonagem * getSpritePrincipal();

    GBF::Grafico::Sprite::SpritePersonagem * getSprite(const std::string & nome);


  protected:
    //Construtor 
    Personagem();

  friend class ListPersonagem;
};

} // namespace Personagem
#endif
