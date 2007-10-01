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

#include "FrameLayerCamera.h"

//Destrutor
FrameLayerCamera::~FrameLayerCamera() 
{
    mundo=NULL;
}
//Retorna a Posição Atual da Camera 
Ponto FrameLayerCamera::getPosicao() 
{
    return ponto;
}
//Verifica se a Camera está no limite inferior do mapa 
bool FrameLayerCamera::isBottom() 
{
    if (ponto.y>=(mundo->getTilesVertical() * mundo->getPixelTileVertical() - mundo->getPixelVisivelVertical())){
        return true;
    } else {
        return false;
    }
}
//Verifica se a Camera está no limite esquerdo do mapa 
bool FrameLayerCamera::isLeft() 
{
    if (ponto.x<=0){
        return true;
    } else {
        return false;
    }
}
//Verifica se a Camera está no limite direito do mapa 
bool FrameLayerCamera::isRight() 
{
    if (ponto.x>=(mundo->getTilesHorizontal() * mundo->getPixelTileHorizontal() - mundo->getPixelVisivelVertical())){
        return true;
    } else {
        return false;
    }
}
//Verifica se a Camera está no limite superior do mapa
bool FrameLayerCamera::isTop() 
{
    if (ponto.y<=0){
        return true;
    } else {
        return false;
    }
}
//Movimenta camera para Baixo 
void FrameLayerCamera::runDown(int deslocamento) 
{
    ponto.y+=deslocamento;
    limiteDown();
}
//Movimenta camera para Esquerda 
void FrameLayerCamera::runLeft(int deslocamento) 
{
    ponto.x-=deslocamento;
    limiteLeft();
}
//Movimenta camera para Direita 
void FrameLayerCamera::runRight(int deslocamento) 
{
    ponto.x+=deslocamento;
    limiteRight();
}
//Movimenta camera para Cima 
void FrameLayerCamera::runUp(int deslocamento) 
{
    ponto.y-=deslocamento;
    limiteUp();
}
//Posiciona a Camera no Final do mapa 
void FrameLayerCamera::setBottom() 
{
    ponto.x=0;
    ponto.y=(mundo->getTilesVertical() - mundo->getTilesHorizontal()) * (mundo->getPixelTileVertical());
}
void FrameLayerCamera::setMundo(FrameLayerMundo * mundo) 
{
    this->mundo=mundo;
}
//Posiciona a Camera em um ponto do Mapa 
void FrameLayerCamera::setPosicao(int X, int Y) 
{
    ponto.x=X;
    ponto.y=Y;
}
//Posiciona a Camera no inicio do mapa 
void FrameLayerCamera::setTop() 
{
    ponto.x=0;
    ponto.y=0;
}
//Mostra o posicionamento da camera no mapa 
void FrameLayerCamera::show() 
{
/*
    GraphicSystemGFX *gfx = GraphicSystemGFX::getInstance();
    gfx->setColor(0,255,0);
    gfx->circulo(ponto.x,ponto.y,10);
*/
}
//Não permite que a camera ultrapasse o limite do mapa pelo lado superior 
void FrameLayerCamera::limiteUp() 
{
    if (ponto.y<=0){
        ponto.y=0;
    }
}
//Não permite que a camera ultrapasse o limite do mapa pelo lado inferior 
void FrameLayerCamera::limiteDown() 
{
    int limite = (mundo->getTilesVertical() * mundo->getPixelTileVertical()) - mundo->getPixelVisivelVertical();
    if (ponto.y>=limite){
        ponto.y =limite;
    }
}
//Não permite que a camera ultrapasse o limite do mapa pelo lado esquerdo 
void FrameLayerCamera::limiteLeft() 
{
    if (ponto.x<=0){
        ponto.x=0;
    }
}
//Não permite que a camera ultrapasse o limite do mapa pelo lado direito 
void FrameLayerCamera::limiteRight() 
{
    int limite = (mundo->getTilesHorizontal() * mundo->getPixelTileHorizontal()) - mundo->getPixelVisivelHorizontal();
    if (ponto.x>=limite){
        ponto.x =limite;
    }
}
//Construtor
FrameLayerCamera::FrameLayerCamera() 
{
    setTop();
}
