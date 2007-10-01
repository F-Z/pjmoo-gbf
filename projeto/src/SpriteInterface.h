#ifndef _SPRITEINTERFACE_H
#define _SPRITEINTERFACE_H

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

struct Frame
{
    int atual;

    int total;

};
class Animacao
{
  public:
    //Construtor
    Animacao();

    //Ajusta a area de corte do sprite - posicionamento nos frames
    void ajustarCorte(int direcao, int largura);

    //Informa se animação está no fim - último frame
    bool isFim();

    //Informa se animação está no inicio - primeiro frame
    bool isInicio();

    SDL_Rect getQuadro();

    int processar();

    //Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem 
    void processarManual();

    void setAreaCorte(const SDL_Rect & area);

    //Define se a animação é automática ou manual 
    void setAutomatico(bool automatico);

    //Informa a quantidade de quadros e a taxa de repetição
    void setFrame(int quantidade, int taxaRepeticao);

    //Coloca a animação no primeiro frame
    void setInicio();


  protected:
    bool automatico;

    SDL_Rect areaCorte;


  private:
    //Anima o Sprite de forma automática 
    int animar();


  protected:
    Frame repeticao;

    Frame frame;

};
class SpriteInterface
{
  public:
    //Destrutor
    virtual ~SpriteInterface();

    void criar(int left, int top, int largura, int altura, GraphicSystemImageBuffer * gsiBuffer);


  protected:
    //Construtor
    SpriteInterface();

    GraphicSystemImageBuffer * imagem;

    SDL_Rect posicao;

    SDL_Rect tamanho;


  public:
    Animacao animacao;

};
#endif
