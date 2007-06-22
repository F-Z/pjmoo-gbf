#ifndef _SPRITEABSTRACT_H
#define _SPRITEABSTRACT_H

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

#include "GraphicSystemImageBuffer.h"
#include "GBF_define.h"
#include "SpriteInterface.h"

//Definição de direções
enum DIRECAO {
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
struct DIRECAO_STATUS
{
    bool cima;

    bool direita;

    bool baixo;

    bool esquerda;

    bool cimadireita;

    bool baixodireita;

    bool baixoesquerda;

    bool cimaesquerda;

};
class SpriteAbstract : protected SpriteInterface
{
  public:
    //Destrutor
    virtual ~SpriteAbstract();

    //Posiciona o Sprite na tela 
    virtual void setPosicao(int x, int y);

    //Define se a animação é automática ou manual 
    void setAutomatico(bool AUTOMATICO);

    //Anima o Sprite de forma automática 
    int animar();

    //Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem 
    void animarManual();

    void criar(int left, int top, int largura, int altura, int quantitadeQuadro, int repeticaoQuadro, GraphicSystemImageBuffer * gsiBuffer);

    virtual void desenhar(int x, int y);

    virtual void desenhar();

    //Colisão baseada no tamanho dos Sprites 
    bool isColisao(SpriteAbstract * SPRITECOLISAO);

    //Retorna a dimensão do sprite 'width' e 'height' 
    Dimensao getTamanho();

    bool isAnimacaoInicio();

    bool isAnimacaoFim();

    void setAnimacaoInicio();


  protected:
    SpriteAbstract();

};
#endif
