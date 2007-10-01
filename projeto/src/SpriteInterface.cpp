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

#include "SpriteInterface.h"

//Construtor
Animacao::Animacao()
{
    automatico = false;

    frame.atual = 0;
    frame.total = 0;

    repeticao.atual = 0;
    repeticao.total = 0;
}
//Ajusta a area de corte do sprite - posicionamento nos frames
void Animacao::ajustarCorte(int direcao, int largura)
{
    areaCorte.x = (direcao) * (largura * frame.total);
}
//Informa se animação está no fim - último frame
bool Animacao::isFim()
{
//verificar se deve-se utilizar 'repeticao.total
//    if ((frame.atual==frame.total-1) && (repetica.atual==repeticao.total)){
    if (frame.atual==frame.total-1){
        return true;
    } else {
        return false;
    }
}
//Informa se animação está no inicio - primeiro frame
bool Animacao::isInicio()
{
    if (frame.atual==0){
        return true;
    } else {
        return false;
    }
}
SDL_Rect Animacao::getQuadro()
{
    return areaCorte;
}
int Animacao::processar()
{
    if (automatico){
        animar();
    }

    return frame.atual;
}
//Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem
void Animacao::processarManual()
{
    animar();
}
void Animacao::setAreaCorte(const SDL_Rect & area)
{
    areaCorte=area;
}
//Define se a animação é automática ou manual
void Animacao::setAutomatico(bool automatico)
{
    this->automatico=automatico;
}
//Informa a quantidade de quadros e a taxa de repetição
void Animacao::setFrame(int quantidade, int taxaRepeticao)
{
    frame.total     = quantidade;
    repeticao.total = taxaRepeticao;
}
//Coloca a animação no primeiro frame
void Animacao::setInicio()
{
    repeticao.atual = 0;
    frame.atual     = 0;
}
//Anima o Sprite de forma automática
int Animacao::animar()
{
    repeticao.atual++;

    if (repeticao.atual>repeticao.total){

        frame.atual++;

        if (frame.atual>=frame.total){
            frame.atual = 0;
        }

        repeticao.atual = 0;
    }

    return frame.atual;
/*
    personagem->frameRateAtual++;

    if (personagem->frameRateAtual>personagem->frameRateMaximo){
        personagem->frameAtual++;
        if (personagem->frameAtual>personagem->frameMaximo){
            personagem->frameAtual=0;
        }
        personagem->frameRateAtual=0;
    }
*/
}
//Destrutor
SpriteInterface::~SpriteInterface()
{

}
void SpriteInterface::criar(int left, int top, int largura, int altura, GraphicSystemImageBuffer * gsiBuffer)
{
    tamanho.w = largura;
    tamanho.h = altura;
    tamanho.x = left;
    tamanho.y = top;

    imagem = gsiBuffer;

    animacao.setAreaCorte(tamanho);
}
//Construtor
SpriteInterface::SpriteInterface()
{
}
