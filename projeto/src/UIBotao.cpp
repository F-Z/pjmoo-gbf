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

#include "UIBotao.h"

namespace UserInterface
{

namespace Componente
{

UIBotao::UIBotao(std::string fonte, std::string chaveTexto, const SDLKey & tecla)
{
    botao.setFont(fonte);
    botao.setKeyText(chaveTexto);
    this->tecla = tecla;

    dimension   = writeManager->getFonte(botao.getFont())->getDimensao();
    dimension.w = writeManager->getLarguraLinha(botao.getFont(), botao.getKeyText());
}

UIBotao::~UIBotao()
{
}

//Retorna a tecla correspondente ao botão
SDLKey UIBotao::getTecla()
{
    return tecla;
}

//Desenha os componentes visuais
void UIBotao::draw()
{
    writeManager->escreverLocalizado(botao.getFont(), position.x, position.y, botao.getKeyText());
}

} // namespace UserInterface::Componente

} // namespace UserInterface
