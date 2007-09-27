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

#include "UserInterfaceVisualImagem.h"

//Construtor
UserInterfaceVisualImagem::UserInterfaceVisualImagem(){
    tipoBackground=BACKGROUND_LINES;

    SpriteFactory *spriteFactory = new SpriteFactory(graphicSystem->imageBufferManager->getImageBuffer("gbf-window-background"));
    background = spriteFactory->criarFrameLayer(0,0,10,10);
    delete(spriteFactory);
}

//Destrutor
UserInterfaceVisualImagem::~UserInterfaceVisualImagem() 
{
    if (background){
        delete(background);
    }
}
//Aplica o efeito visual
void UserInterfaceVisualImagem::aplicar(const Ponto & posicao, const Dimensao & dimensao) 
{
    UserInterfaceVisual::aplicar(posicao,dimensao);

    if (background!=NULL){
        background->setFrame(posicao.x,posicao.y,dimensao.w,dimensao.h);
        background->setTiles((dimensao.w/10),(dimensao.h/10));
        background->setPixelTile(10,10);
        background->iniciarCom(tipoBackground);
    }
}
//Desenha o EstiloVisual do Componente

//Desenha o EstiloVisual do Componente
void UserInterfaceVisualImagem::desenhar() 
{
    if (background!=NULL){
        background->desenhar();
    }
    graphicSystem->gfx->setColor(corBorda.r,corBorda.g,corBorda.b);
    graphicSystem->gfx->retangulo(posicao.x,posicao.y,dimensao.w,dimensao.h);
}
//Retorna uma copia do objeto
UserInterfaceVisual * UserInterfaceVisualImagem::clone() 
{
    UserInterfaceVisualImagem * uivImagem = new UserInterfaceVisualImagem();
    uivImagem->setCorBorda(corBorda.r,corBorda.g,corBorda.b);
    uivImagem->setTipoBackground(tipoBackground);

    return uivImagem;
}
//Define o estilo de background a ser utilizado

//Define o estilo de background a ser utilizado
void UserInterfaceVisualImagem::setTipoBackground(UserInterfaceVisualTipoBackground tipo) 
{
    tipoBackground=tipo;
}
