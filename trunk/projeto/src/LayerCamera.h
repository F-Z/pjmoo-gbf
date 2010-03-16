#ifndef _LAYERCAMERA_H
#define _LAYERCAMERA_H

////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#include "GBF.h"
#include "LayerMundo.h"

namespace GBF {

namespace Image {

namespace Layer {

class LayerCamera {
    public:
        //Destrutor
        virtual ~LayerCamera();

        //Retorna a Posição Atual da Camera
        GBF::Ponto getPosicao();

        //Verifica se a Camera está no limite inferior do mapa
        bool isBottom();

        //Verifica se a Camera está no limite esquerdo do mapa
        bool isLeft();

        //Verifica se a Camera está no limite direito do mapa
        bool isRight();

        //Verifica se a Camera está no limite superior do mapa
        bool isTop();

        //Movimenta camera para Baixo
        void runDown(float deslocamento);

        //Movimenta camera para Esquerda
        void runLeft(float deslocamento);

        //Movimenta camera para Direita
        void runRight(float deslocamento);

        //Movimenta camera para Cima
        void runUp(float deslocamento);

        //Posiciona a Camera no Final do mapa
        void setBottom();

        void setMundo(LayerMundo * mundo);

        //Posiciona a Camera em um ponto do Mapa
        void setPosicao(int X, int Y);

        //Posiciona a Camera no inicio do mapa
        void setTop();

        //Mostra o posicionamento da camera no mapa
        void show();


    protected:
        //Não permite que a camera ultrapasse o limite do mapa pelo lado superior
        void limiteUp();

        //Não permite que a camera ultrapasse o limite do mapa pelo lado inferior
        void limiteDown();

        //Não permite que a camera ultrapasse o limite do mapa pelo lado esquerdo
        void limiteLeft();

        //Não permite que a camera ultrapasse o limite do mapa pelo lado direito
        void limiteRight();


    private:
        LayerMundo * mundo;

        friend class FrameLayer;
        //Construtor
        LayerCamera();


    protected:
        GBF::PontoVirtual ponto;

};

} // namespace GBF::Image::Layer

} // namespace GBF::Image

} // namespace GBF

#endif
