#ifndef _SPRITE_H
#define _SPRITE_H

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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "GraphicSystemImageBuffer.h"
#include "GBF_define.h"
#include "SpriteInterface.h"

//Definição de direções
enum SpriteDirecao {
  DR_CIMA,
  DR_DIREITA,
  DR_BAIXO,
  DR_ESQUERDA,
  DR_CIMADIREITA,
  DR_BAIXODIREITA,
  DR_BAIXOESQUERDA,
  DR_CIMAESQUERDA
};
//Definição de Status
struct SpriteDirecaoStatus
{
    bool cima;

    bool direita;

    bool baixo;

    bool esquerda;

    bool cimaDireita;

    bool baixoDireita;

    bool baixoEsquerda;

    bool cimaEsquerda;

};
class Sprite : public SpriteInterface
{
  public:
    //Destrutor
    virtual ~Sprite();

    void criar(int left, int top, int largura, int altura, int quantitadeQuadro, int repeticaoQuadro, GraphicSystemImageBuffer * gsiBuffer);

    virtual void desenhar(int x, int y);

    //Desenha o sprite na tela, com base na última posição informada ou desenhada
    virtual void desenhar();

    //Retorna a dimensão do sprite 'width' e 'height' 
    Dimensao getTamanho();

    //Colisão baseada no tamanho dos Sprites 
    bool isColisao(Sprite * spriteColisao);

    //Posiciona o Sprite na tela 
    void setPosicao(Ponto ponto);

    //Posiciona o Sprite na tela 
    virtual void setPosicao(int x, int y);


  protected:
    //Construtor
    Sprite();

};
#endif
