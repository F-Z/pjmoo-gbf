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

#include "Sprite.h"

//Destrutor
Sprite::~Sprite() 
{
}
void Sprite::criar(int left, int top, int largura, int altura, int quantitadeQuadro, int repeticaoQuadro, GraphicSystemImageBuffer * gsiBuffer) 
{
    //chama o metodo criar da classe superclasse - SpriteInterface
    SpriteInterface::criar(left, top, largura, altura, gsiBuffer);
    //configura as informações de animação
    animacao.setFrame(quantitadeQuadro,repeticaoQuadro);
}
void Sprite::desenhar(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
    SDL_Rect pontoCorte=tamanho;
    pontoCorte.x+=animacao.getQuadro().x;

    imagem->desenhar(posicao,pontoCorte,animacao.processar());
}
//Desenha o sprite na tela, com base na última posição informada ou desenhada
void Sprite::desenhar() 
{
    desenhar(posicao.x,posicao.y);
}
//Retorna a dimensão do sprite 'width' e 'height' 
Dimensao Sprite::getTamanho() 
{
    Dimensao dimensao;
    dimensao.w=tamanho.w;
    dimensao.h=tamanho.h;

    return  dimensao;
}
//Colisão baseada no tamanho dos Sprites 
bool Sprite::isColisao(Sprite * spriteColisao) 
{
    if ((posicao.x + tamanho.w >= spriteColisao->posicao.x)&&
        (posicao.x <= spriteColisao->posicao.x + spriteColisao->tamanho.w)&&
        (posicao.y + tamanho.h >= spriteColisao->posicao.y)&&
        (posicao.y <= spriteColisao->posicao.y + spriteColisao->tamanho.h)){
            return true;
    } else {
        return false;
    }
}
//Posiciona o Sprite na tela 
void Sprite::setPosicao(Ponto ponto) 
{
    setPosicao(ponto.x,ponto.y);
}
//Posiciona o Sprite na tela 
void Sprite::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
}
//Construtor
Sprite::Sprite() 
{
    tamanho.x = tamanho.y = tamanho.h = tamanho.w = 0;
    posicao.x = posicao.y = posicao.h = posicao.w = 0;

    animacao.setAutomatico(true);
}
