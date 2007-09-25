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

#include "UserInterfaceBotao.h"

UserInterfaceBotao::UserInterfaceBotao(std::string fonte, std::string chaveTexto, const SDLKey & tecla){
    botao.setFonte(fonte);
    botao.setChaveTexto(chaveTexto);
    this->tecla=tecla;
}

UserInterfaceBotao::~UserInterfaceBotao(){
}

//Desenha o botão

//Desenha o botão
void UserInterfaceBotao::desenhar(const Ponto & posicao) 
{
    Dimensao dimensao = wsManager->getFonte(botao.getFonte())->getDimensao();
    int tamanhoTexto = wsManager->getLarguraLinha(botao.getFonte(),botao.getChaveTexto());

    int posicaoTextoHorizontal = int(posicao.x - tamanhoTexto);
    int posicaoTextoVertical   = int(posicao.y - (dimensao.h * 1.2));

    wsManager->escreverLocalizado(botao.getFonte(),posicaoTextoHorizontal,posicaoTextoVertical,botao.getChaveTexto());
}
//Retorna a tecla correspondente ao botão

//Retorna a tecla correspondente ao botão
SDLKey UserInterfaceBotao::getTecla() 
{
    return tecla;
}
