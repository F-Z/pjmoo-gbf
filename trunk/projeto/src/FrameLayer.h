#ifndef _FRAMELAYER_H
#define _FRAMELAYER_H

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

#include "SpriteInterface.h"
#include "FrameLayerCamera.h"
#include "GraphicSystemImage.h"
#include <string>

#include "FrameLayerMundo.h"

//Classe para Desenho de TileMaps
class FrameLayer : public SpriteInterface
{
  public:
    FrameLayerCamera camera;

    //Construtor
    FrameLayer();

    //Destrutor
    virtual ~FrameLayer();

    //Desenha o mapa
    void desenhar();

    //Desenha a grade de tiles do mapa
    void showGrade();

    //Informa o posicionamento da area de desenho e as suas dimensões internas
    void setFrame(int left, int top, int largura, int altura);

    //Informa o tamanho do mundo em tiles horizontais e verticais
    void setTiles(int largura, int altura);

    //Informa o tamanho em pixels dos tiles usados no layer
    void setPixelTile(int largura, int altura);

    //Retorna a area do layer relacionado com o ponto de desenho (x e y) e  o tamanho interno (w e h)
    Area getArea();

    //Inicializa tiles com valores do arquivo
    void iniciarArquivo(std::string arquivo);

    //Inicializa tiles de forma aleatória
    void iniciarRandomico(int range);

    //Iniciar ordenado até o quadro informado
    void iniciarOrdenado(int quadroMaximo);

    //Iniciar preenchendo apenas com o quadro informado
    void iniciarCom(int quadro);

    //Porcentagem percorrida do Scroll Vertical
    int getPorcentagemScrollVertical();

    //Porcentagem percorrida do Scroll Horizontal
    int getPorcentagemScrollHorizontal();

    //Distancia restante para finalizar Scrolling Vertical
    int getDistanciaScrollVertical();

    //Distancia total do Scrolling Vertical
    int getTotalScrollVertical();


  protected:
    int * mapa;

    Area screen_dimensao;

    FrameLayerMundo mundo;

  friend class FrameLayerManager;
};
#endif
