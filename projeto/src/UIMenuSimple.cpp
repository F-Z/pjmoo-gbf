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

#include "UIMenuSimple.h"

namespace UserInterface {

namespace Menu {

//Construtor
UIMenuSimple::UIMenuSimple()
{
}
//Destrutor
UIMenuSimple::~UIMenuSimple()
{
}
void UIMenuSimple::draw()
{
    if (!item.empty()){
        GBF::Dimension dimensao = item[0]->getDimensaoLetra();
        int offsetY=(dimensao.w/4);
        int totalVertical   = (int(item.size()) * verticalSpace)+offsetY;
        int totalHorizontal = (maxCharItem) * dimensao.w;
        int meioHorizontal  = totalHorizontal/2;

        GBF::Point t=calcularAlinhamento(totalHorizontal,totalVertical);

        int pontoY=t.y+offsetY;
        for (unsigned int i=0; i<item.size(); i++){
            if (item[i]!=NULL){
                int dtmp=item[i]->getQuantidadeLetras();
                item[i]->draw(t.x+(meioHorizontal-((dtmp*dimensao.w)/2)),pontoY);
            }
            pontoY+=verticalSpace;
        }
    }
}

} // namespace UserInterface::Menu

} // namespace UserInterface
