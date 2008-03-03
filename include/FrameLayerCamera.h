#ifndef _FRAMELAYERCAMERA_H
#define _FRAMELAYERCAMERA_H

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

#include "GBF_define.h"
#include "FrameLayerMundo.h"

class FrameLayerCamera
{
  public:
    //Destrutor
    virtual ~FrameLayerCamera();

    //Retorna a Posi��o Atual da Camera 
    Ponto getPosicao();

    //Verifica se a Camera est� no limite inferior do mapa 
    bool isBottom();

    //Verifica se a Camera est� no limite esquerdo do mapa 
    bool isLeft();

    //Verifica se a Camera est� no limite direito do mapa 
    bool isRight();

    //Verifica se a Camera est� no limite superior do mapa
    bool isTop();

    //Movimenta camera para Baixo 
    void runDown(int deslocamento);

    //Movimenta camera para Esquerda 
    void runLeft(int deslocamento);

    //Movimenta camera para Direita 
    void runRight(int deslocamento);

    //Movimenta camera para Cima 
    void runUp(int deslocamento);

    //Posiciona a Camera no Final do mapa 
    void setBottom();

    void setMundo(FrameLayerMundo * mundo);

    //Posiciona a Camera em um ponto do Mapa 
    void setPosicao(int X, int Y);

    //Posiciona a Camera no inicio do mapa 
    void setTop();

    //Mostra o posicionamento da camera no mapa 
    void show();


  protected:
    //N�o permite que a camera ultrapasse o limite do mapa pelo lado superior 
    void limiteUp();

    //N�o permite que a camera ultrapasse o limite do mapa pelo lado inferior 
    void limiteDown();

    //N�o permite que a camera ultrapasse o limite do mapa pelo lado esquerdo 
    void limiteLeft();

    //N�o permite que a camera ultrapasse o limite do mapa pelo lado direito 
    void limiteRight();


  private:
    FrameLayerMundo * mundo;

    Ponto ponto;

  friend class FrameLayer;
    //Construtor
    FrameLayerCamera();

};
#endif
