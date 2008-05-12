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

#include "UIMenu.h"

namespace UserInterface {

namespace Menu {

//Construtor
UIMenu::UIMenu() 
{
}
//Destrutor
UIMenu::~UIMenu() 
{
}
void UIMenu::desenhar() 
{
    if (!item.empty()){
        Dimensao dimensao = item[0]->getDimensaoLetra();
        int offsetY=(dimensao.w/4);
        int totalVertical   = (int(item.size()) * espacoVertical)+offsetY;
        int totalHorizontal = (maiorPalavra+2) * dimensao.w;
        int meioHorizontal  = totalHorizontal/2;

        Ponto t=calcularAlinhamento(totalHorizontal,totalVertical);

        graphicSystem->gfx->setColor(corFundo.r,corFundo.g,corFundo.b);
        graphicSystem->gfx->retanguloPreenchido(t.x,t.y,totalHorizontal,totalVertical);
        graphicSystem->gfx->setColor(corBorda.r,corBorda.g,corBorda.b);
        graphicSystem->gfx->retangulo(t.x,t.y,totalHorizontal,totalVertical);

        int pontoY=t.y+offsetY;
        for (unsigned int i=0; i<item.size(); i++){
            if (item[i]!=NULL){
                int dtmp=item[i]->getQuantidadeLetras();
                item[i]->desenhar(t.x+(meioHorizontal-((dtmp*dimensao.w)/2)),pontoY);
            }
            pontoY+=espacoVertical;
        }
    }
}
bool UIMenu::navegar() 
{
    bool navegou = false;

    if ((inputSystem->teclado->isKey(SDLK_UP))||(inputSystem->joystick->isAxeUp())){
        itemAnterior();
        delayNavegacao.setResetar();
        navegou=true;
    } else if ((inputSystem->teclado->isKey(SDLK_DOWN))||(inputSystem->joystick->isAxeDown())){
        itemAvancar();
        delayNavegacao.setResetar();
        navegou=true;
    }

    return navegou;
}
void UIMenu::itemAvancar() 
{
    itemSelecionado++;
    if (itemSelecionado>=int(item.size())){
        itemSelecionado=item.size()-1;
    }
}
void UIMenu::itemAnterior() 
{
    itemSelecionado--;
    if (itemSelecionado<0){
        itemSelecionado=0;
    }
}

} // namespace UserInterface::Menu

} // namespace UserInterface
