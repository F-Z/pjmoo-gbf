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

#include "LayerCamera.h"

namespace GBF {

namespace Image {

namespace Layer {

//Destrutor
LayerCamera::~LayerCamera() {
    mundo = NULL;
}

//Retorna a Posição Atual da Camera
GBF::Ponto LayerCamera::getPosicao() {
    Ponto p;

    p.x = (int)ponto.x;
    p.y = (int)ponto.y;

    return p;
}

//Verifica se a Camera está no limite inferior do mapa
bool LayerCamera::isBottom() {
    if (ponto.y >= (mundo->getTilesVertical() * mundo->getPixelTileVertical() - mundo->getPixelVisivelVertical())) {
        return true;
    }
    else {
        return false;
    }
}

//Verifica se a Camera está no limite esquerdo do mapa
bool LayerCamera::isLeft() {
    if (ponto.x <= 0) {
        return true;
    }
    else {
        return false;
    }
}

//Verifica se a Camera está no limite direito do mapa
bool LayerCamera::isRight() {
    if (ponto.x >= (mundo->getTilesHorizontal() * mundo->getPixelTileHorizontal() - mundo->getPixelVisivelVertical())) {
        return true;
    }
    else {
        return false;
    }
}

//Verifica se a Camera está no limite superior do mapa
bool LayerCamera::isTop() {
    if (ponto.y <= 0) {
        return true;
    }
    else {
        return false;
    }
}

//Movimenta camera para Baixo
void LayerCamera::runDown(float deslocamento) {
    ponto.y += deslocamento;
    limiteDown();
}

//Movimenta camera para Esquerda
void LayerCamera::runLeft(float deslocamento) {
    ponto.x -= deslocamento;
    limiteLeft();
}

//Movimenta camera para Direita
void LayerCamera::runRight(float deslocamento) {
    ponto.x += deslocamento;
    limiteRight();
}

//Movimenta camera para Cima
void LayerCamera::runUp(float deslocamento) {
    ponto.y -= deslocamento;
    limiteUp();
}

//Posiciona a Camera no Final do mapa
void LayerCamera::setBottom() {
    ponto.x = 0;
    ponto.y = (mundo->getTilesVertical() - mundo->getTilesHorizontal()) * (mundo->getPixelTileVertical());
}

void LayerCamera::setMundo(LayerMundo * mundo) {
    this->mundo = mundo;
}

//Posiciona a Camera em um ponto do Mapa
void LayerCamera::setPosicao(int X, int Y) {
    ponto.x = X;
    ponto.y = Y;
}

//Posiciona a Camera no inicio do mapa
void LayerCamera::setTop() {
    ponto.x = 0;
    ponto.y = 0;
}

//Mostra o posicionamento da camera no mapa
void LayerCamera::show() {
    /*
        GraphicSystemGFX *gfx = GraphicSystemGFX::getInstance();
        gfx->setColor(0,255,0);
        gfx->circulo(ponto.x,ponto.y,10);
    */
}

//Não permite que a camera ultrapasse o limite do mapa pelo lado superior
void LayerCamera::limiteUp() {
    if (ponto.y <= 0) {
        ponto.y = 0;
    }
}

//Não permite que a camera ultrapasse o limite do mapa pelo lado inferior
void LayerCamera::limiteDown() {
    int limite = (mundo->getTilesVertical() * mundo->getPixelTileVertical()) - mundo->getPixelVisivelVertical();

    if (ponto.y >= limite) {
        ponto.y = limite;
    }
}

//Não permite que a camera ultrapasse o limite do mapa pelo lado esquerdo
void LayerCamera::limiteLeft() {
    if (ponto.x <= 0) {
        ponto.x = 0;
    }
}

//Não permite que a camera ultrapasse o limite do mapa pelo lado direito
void LayerCamera::limiteRight() {
    int limite = (mundo->getTilesHorizontal() * mundo->getPixelTileHorizontal()) - mundo->getPixelVisivelHorizontal();

    if (ponto.x >= limite) {
        ponto.x = limite;
    }
}

//Construtor
LayerCamera::LayerCamera() {
    setTop();
}

} // namespace GBF::Image::Layer

} // namespace GBF::Image

} // namespace GBF
