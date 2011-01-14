/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#include "UIMenuSolid.h"

namespace UserInterface {

namespace Menu {

//Construtor
UIMenuSolid::UIMenuSolid()
{
}

//Destrutor
UIMenuSolid::~UIMenuSolid()
{
}

void UIMenuSolid::draw()
{
    if (!item.empty()){
        GBF::Dimension dimensao = item[0]->getDimensaoLetra();
        int offsetY = (dimensao.w / 4);
        int totalVertical   = (int(item.size()) * verticalSpace) + offsetY;
        int totalHorizontal = (maxCharItem + 2) * dimensao.w;
        int meioHorizontal  = totalHorizontal / 2;

        GBF::Point t = calcularAlinhamento(totalHorizontal, totalVertical);

        graphicSystem->gfx->setColor(corFundo.r, corFundo.g, corFundo.b);
        graphicSystem->gfx->rectangleFill(t.x, t.y, totalHorizontal, totalVertical);
        graphicSystem->gfx->setColor(corBorda.r, corBorda.g, corBorda.b);
        graphicSystem->gfx->rectangle(t.x, t.y, totalHorizontal, totalVertical);

        int pontoY = t.y + offsetY;
        int pontoX = 0;
        int quantidadeLetras = 0;

        for (unsigned int i = 0; i < item.size(); i++){
            if (item[i] != NULL){
                //item[i]->desenhar(t.x+(meioHorizontal-((dtmp*dimensao.w)/2)),pontoY);
                quantidadeLetras = item[i]->getQuantidadeLetras();
                pontoX = t.x + meioHorizontal - (quantidadeLetras * dimensao.w) / 2;
                item[i]->draw(pontoX, pontoY);
            }

            pontoY += verticalSpace;
        }
    }
}

bool UIMenuSolid::browse()
{
    bool navegou = false;

    if ((inputSystem->keyboard->isKey(SDLK_UP)) || (inputSystem->joystick->isAxeUp())){
        previous();
        browseDelay.setReset();
        navegou = true;
    } else if ((inputSystem->keyboard->isKey(SDLK_DOWN)) || (inputSystem->joystick->isAxeDown())){
        next();
        browseDelay.setReset();
        navegou = true;
    }

    return navegou;
}

void UIMenuSolid::next()
{
    selectedItem++;

    if (selectedItem >= int(item.size())){
        selectedItem = item.size() - 1;
    }
}

void UIMenuSolid::previous()
{
    selectedItem--;

    if (selectedItem < 0){
        selectedItem = 0;
    }
}

} // namespace UserInterface::Menu

} // namespace UserInterface
