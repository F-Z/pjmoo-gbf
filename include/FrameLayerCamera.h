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
////////////////////////////////////////////////////////////////////////

#include "FrameLayerMundo.h"
#include "GBF_define.h"

class FrameLayerCamera
{
  public:
    //Destrutor
    virtual ~FrameLayerCamera();

    //Construtor
    FrameLayerCamera();

    void setMundo(FrameLayerMundo mundo);

    //Mostra o posicionamento da camera no mapa 
    void show();

    //Posiciona a Camera em um ponto do Mapa 
    void setPosicao(int X, int Y);

    //Posiciona a Camera no inicio do mapa 
    void setTop();

    //Posiciona a Camera no Final do mapa 
    void setBottom();

    //Retorna a Posição Atual da Camera 
    Ponto getPosicao();

    //Verifica se a Camera está no limite superior do mapa
    bool isTop();

    //Verifica se a Camera está no limite inferior do mapa 
    bool isBottom();

    //Verifica se a Camera está no limite direito do mapa 
    bool isRight();

    //Verifica se a Camera está no limite esquerdo do mapa 
    bool isLeft();

    //Movimenta camera para Cima 
    void runUp(int deslocamento);

    //Movimenta camera para Baixo 
    void runDown(int deslocamento);

    //Movimenta camera para Esquerda 
    void runLeft(int deslocamento);

    //Movimenta camera para Direita 
    void runRight(int deslocamento);


  private:
    Ponto ponto;

    FrameLayerMundo mundo;


  protected:
    //Não permite que a camera ultrapasse o limite do mapa pelo lado superior 
    void limiteUp();

    //Não permite que a camera ultrapasse o limite do mapa pelo lado inferior 
    void limiteDown();

    //Não permite que a camera ultrapasse o limite do mapa pelo lado esquerdo 
    void limiteLeft();

    //Não permite que a camera ultrapasse o limite do mapa pelo lado direito 
    void limiteRight();

};
#endif
