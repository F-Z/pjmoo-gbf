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

#include "UIItemTexto.h"

namespace UserInterface {

namespace Menu {

GBF::Kernel::Write::WriteManager * UIItemTexto::wsManager=NULL;

UIItemTexto::UIItemTexto(const std::string & texto, const std::string & fonteTexto)
{
    this->texto=texto;
    this->fonteTexto=fonteTexto;

    tempo.setTempoOriginal(0);
    tempo.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    tempo.setResetar();

    if (wsManager==NULL){
        wsManager = GBF::Kernel::Write::WriteManager::getInstance();
    }
}
UIItemTexto::~UIItemTexto()
{
}
void UIItemTexto::desenhar(int x, int y)
{
    if (isAtivo()){
        tempo.processar();
        if (tempo.getTempo()%2==0){
            wsManager->escreverLocalizado(fonteTexto,x,y,texto.c_str());
        }
    } else {
        wsManager->escreverLocalizado(fonteTexto,x,y,texto.c_str());
    }
}
int UIItemTexto::getQuantidadeLetras()
{
    return wsManager->idioma->getText(texto).length();
}
GBF::Dimensao UIItemTexto::getDimensaoLetra()
{
    return wsManager->getFonte(fonteTexto)->getDimensao();
}

} // namespace UserInterface::Menu

} // namespace UserInterface
