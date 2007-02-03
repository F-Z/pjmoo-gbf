#ifndef _PERSONAGEMABSTRACT_H
#define _PERSONAGEMABSTRACT_H

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

#include <map>

#include <string>

#include "SpritePersonagem.h"
#include "GBF_define.h"
#include "InputSystem.h"

//Definição de TypeDelay
struct TypeDelay {
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
class PersonagemAbstract {
  protected:
    bool ativo;

    bool vivo;

    unsigned int ID;

    std::map<std::string,SpritePersonagem*> sprites;

    TypeDelay delay;

    Ponto posicao;


  private:
    static unsigned int IDcontagem;

    Dimensao dimensao;


  public:
    //Destrutor 
    virtual ~PersonagemAbstract();

    //Desenha o sprite principal do personagem
    virtual void desenhar();

    virtual void setAtivo(bool valor);

    virtual void setVivo(bool valor);

    virtual bool isAtivo();

    virtual bool isVivo();

    virtual bool isColisao(PersonagemAbstract * personagem);

    virtual void setPosicao(int x, int y);

    virtual void setPosicao(Ponto ponto);

    virtual Ponto getPosicao();

    //Adiciona o sprite principal do personagem
    bool adicionarSpritePrincipal(SpritePersonagem * sprite);

    //Adiciona o sprites extras do personagem
    bool adicionarSprite(SpritePersonagem * sprite, const std::string & nome);

    virtual void acao(InputSystem * input) = 0;

    Dimensao getDimensao();

    SpritePersonagem * getSpritePrincipal();

    SpritePersonagem * getSprite(const std::string & nome);


  protected:
    //Construtor 
    PersonagemAbstract();

  friend class ListPersonagemAbstract;
};
#endif
