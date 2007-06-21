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

#include "SpriteAbstract.h"

//Destrutor
SpriteAbstract::~SpriteAbstract() 
{

}
//Posiciona o Sprite na tela 
void SpriteAbstract::setPosicao(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
}
//Define se a animação é automática ou manual 
void SpriteAbstract::setAutomatico(bool AUTOMATICO) 
{
    automatico=AUTOMATICO;
}
//Anima o Sprite de forma automática 
int SpriteAbstract::animar() 
{
    frameAtual++;
    if (frameAtual>frameRate){
        frameAtual=0;
        frameRateAtual++;
        if (frameRateAtual>=frameTotal){
            frameRateAtual=0;
        } else if (frameRateAtual < 0){
            frameRateAtual=0;
        }
    }
    return frameRateAtual;
}
//Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem 
void SpriteAbstract::animarManual() 
{
    animar();
}
void SpriteAbstract::criar(int left, int top, int largura, int altura, int quantitadeQuadro, int repeticaoQuadro, GraphicSystemImageBuffer * gsiBuffer) 
{
    SpriteInterface::criar(left, top, largura, altura, gsiBuffer);
    frameTotal = quantitadeQuadro;
    frameRate  = repeticaoQuadro;
}
void SpriteAbstract::desenhar(int x, int y) 
{
    posicao.x=x;
    posicao.y=y;
    SDL_Rect t=tamanho;
    t.x+=quadro.x;

    if (automatico){
        animar();
    }

    imagem->desenhar(posicao,t,frameRateAtual);
}
void SpriteAbstract::desenhar() 
{
    desenhar(posicao.x,posicao.y);
}
//Colisão baseada no tamanho dos Sprites 
bool SpriteAbstract::isColisao(SpriteAbstract * SPRITECOLISAO) 
{
    if ((posicao.x + tamanho.w >= SPRITECOLISAO->posicao.x)&&
        (posicao.x <= SPRITECOLISAO->posicao.x + SPRITECOLISAO->tamanho.w)&&
        (posicao.y + tamanho.h >= SPRITECOLISAO->posicao.y)&&
        (posicao.y <= SPRITECOLISAO->posicao.y + SPRITECOLISAO->tamanho.h)){
            //FILE* fp = fopen("sprite.log", "a");
            //if (!fp){ return false; }
            //fprintf(fp,"( %i + %i >= %i)\r\n",posicao.x,tamanho.w,SPRITECOLISAO->posicao.x);
            //fprintf(fp,"(%i <= %i + %i)\r\n",posicao.x , SPRITECOLISAO->posicao.x , SPRITECOLISAO->tamanho.w);
            //fprintf(fp,"(%i + %i >= %i)\r\n",posicao.y , tamanho.h , SPRITECOLISAO->posicao.y);
            //fprintf(fp,"(%i <= %i + %i)\r\n",posicao.y , SPRITECOLISAO->posicao.y, SPRITECOLISAO->tamanho.h);
            //fclose(fp);
            return true;
    } else {
        return false;
    }
}
//Retorna a dimensão do sprite 'width' e 'height' 
Dimensao SpriteAbstract::getTamanho() 
{
    Dimensao dimensao;
    dimensao.w=tamanho.w;
    dimensao.h=tamanho.h;

    return  dimensao;
}
bool SpriteAbstract::isAnimacaoInicio() 
{
    if (frameAtual==0){
        return true;
    } else {
        return false;
    }
}
bool SpriteAbstract::isAnimacaoFim() 
{
    if (frameRateAtual==frameTotal-1){
        return true;
    } else {
        return false;
    }
}
void SpriteAbstract::setAnimacaoInicio() 
{

    frameRateAtual=0;
}
SpriteAbstract::SpriteAbstract() 
{
    tamanho.x = tamanho.y = tamanho.h = tamanho.w = 0;
    posicao.x = posicao.y = posicao.h = posicao.w = 0;

    automatico = true;
}
