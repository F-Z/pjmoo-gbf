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

#include "UIKeyboard.h"

namespace UserInterface {

namespace Component {

//Efetua o controle sobre a navegação do cursor

//Efetua o controle sobre a navegação do cursor
void UIKeyboard::browse()
{
    if ((inputSystem->keyboard->isKey(SDLK_LEFT)) || (inputSystem->joystick->isAxeLeft())){
        selecao--;
        tempoEspera.setReset();
    } else if ((inputSystem->keyboard->isKey(SDLK_RIGHT)) || (inputSystem->joystick->isAxeRight())){
        selecao++;
        tempoEspera.setReset();
    } else if ((inputSystem->keyboard->isKey(SDLK_DOWN)) || (inputSystem->joystick->isAxeDown())){
        if (selecao < 40){
            selecao += 10;
        } else {//if (selecao>=teclado.getTotalTeclas()){
            selecao++;
        }

        tempoEspera.setReset();
    } else if ((inputSystem->keyboard->isKey(SDLK_UP)) || (inputSystem->joystick->isAxeUp())){
        if ((selecao >= 10) && (selecao < getTotalCaracter())){
            selecao -= 10;
        } else {
            selecao--;
        }

        tempoEspera.setReset();
    }

    if (selecao < 0){
        selecao = 0;
    } else if (selecao > getTotalTeclas() - 1){
        selecao = getTotalTeclas() - 1;
    }
}

void UIKeyboard::drawBackground()
{
    //desenhando caixa do teclado
    if (visual != NULL){
        visual->desenhar();
    }

    int letra = 0;

    GBF::Point tecla;
    tecla.x = point.x + (fontKey.dimensao.w / 4);
    tecla.y = point.y;

    GBF::Point cursor;
    cursor.x = point.x + (fontKey.dimensao.w * 0.2);
    cursor.y = point.y + (fontKey.dimensao.h * 0.1);

    GBF::Dimension cursorDimensao;
    cursorDimensao.w = fontKey.dimensao.w;
    cursorDimensao.h = fontKey.dimensao.h;

    int espacoHorizontal = fontKey.dimensao.w + int(fontKey.dimensao.w / 4);
    int espacoVertical   = fontKey.dimensao.h + int(fontKey.dimensao.h / 4);

    graphicSystem->gfx->setColor(corCursor.r, corCursor.g, corCursor.b);

    //Painel do teclado

    for (int l = 0;l < 5;l++){
        for (int c = 0;c < 10;c++){
            writeManager->write(fontKey.nome, tecla.x + (espacoHorizontal*c), tecla.y + (espacoVertical*l), "%c", caracter[letra]);

            //Desenhando cursor da selecao de tecla

            if ((selecao == letra) && (tempoBlink.getTime() % 2 == 0)){
                graphicSystem->gfx->retangulo(cursor.x + (espacoHorizontal*c), cursor.y + (espacoVertical*l), cursorDimensao.w, cursorDimensao.h);
            }

            letra++;
        }
    }
}

void UIKeyboard::drawContent()
{
    graphicSystem->gfx->setColor(corCursor.r, corCursor.g, corCursor.b);

    GBF::Point tecla;
    tecla.x = point.x + (fontKey.dimensao.w / 4);
    tecla.y = point.y;

    tecla.x = point.x + (10 * (fontKey.dimensao.w + fontKey.dimensao.w * 0.3));
    tecla.y = point.y + dimension.h - (getTotalControle() * fontControl.dimensao.h);

    GBF::Point cursor;
    cursor.x = tecla.x - int(fontControl.dimensao.w * 0.25);
    cursor.y = tecla.y;

    GBF::Dimension cursorDimensao;
    cursorDimensao.w = getTamanhoControle() + (fontControl.dimensao.w * 0.5);
    cursorDimensao.h = fontControl.dimensao.h;

    //Painel das teclas de controles

    for (int ic = getTotalControle() - 1;ic >= 0;ic--){
        writeManager->writeKeyText(fontControl.nome, tecla.x, tecla.y + (fontControl.dimensao.h*ic), controle[ic].c_str());
    }

    //Desenhando cursor das teclas de controle
    if (tempoBlink.getTime() % 2 == 0){
        if (selecao >= getTotalCaracter()){
            int t = selecao - getTotalCaracter();
            graphicSystem->gfx->retangulo(cursor.x, cursor.y + (fontControl.dimensao.h*t), cursorDimensao.w, cursorDimensao.h);
        }
    }
}

void UIKeyboard::update()
{
    tempoEspera.update();
    tempoBlink.update();

    if (tempoEspera.isFinish()){
        browse();
    }

    if (visual != NULL){
        GBF::Dimension d  = dimension;
        d.w = dimension.w + getTamanhoControle() + (fontKey.dimensao.w);

        visual->aplicar(point, d);
    }
}

void UIKeyboard::draw()
{
    drawBackground();
    drawContent();
}

UIKeyboard::UIKeyboard()
{
    point.x = 0;
    point.y = 0;
    selecao   = 0;

    tempoEspera.setInitialTime(1);
    tempoEspera.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoEspera.setReset();

    tempoBlink.setInitialTime(0);
    tempoBlink.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoBlink.setReset();
}

UIKeyboard::~UIKeyboard(){
}

int UIKeyboard::getTotalCaracter()
{
    return strlen(caracter);
}

int UIKeyboard::getTotalControle()
{
    return 3;
}

int UIKeyboard::getTotalTeclas()
{
    return getTotalCaracter() + getTotalControle();
}

int UIKeyboard::getTamanhoControle()
{
    return tamanhoControle;
}

void UIKeyboard::setCaracter(std::string caracteres)
{
    strcpy(caracter, caracteres.c_str());
}

void UIKeyboard::addControl(int index, std::string text)
{
    controle[index] = text;
}

char UIKeyboard::getCaracter()
{
    return caracter[selecao];
}

int UIKeyboard::getIndex()
{
    return selecao;
}

//Define a fonte a ser usada pelo label

//Define a fonte a ser usada pelo Controle
void UIKeyboard::setFontControl(std::string font)
{
    fontControl.nome = font;
    fontControl.dimensao = writeManager->getFont(fontControl.nome)->getDimensao();

    tamanhoControle  = 0;
    int tmp = 0;

    for (int i = 0; i < getTotalControle();i++){
        tmp = writeManager->getLineWidth(fontControl.nome, controle[i].c_str());

        if (tmp > getTamanhoControle()){
            tamanhoControle = tmp;
        }
    }
}

//Define a fonte a ser usada pelo teclado virtual

//Define a fonte a ser usada pelo teclado virtual
void UIKeyboard::setFontKey(std::string font)
{
    fontKey.nome = font;
    fontKey.dimensao = writeManager->getFont(fontKey.nome)->getDimensao();

    dimension.w = 10 * (fontKey.dimensao.w + int(fontKey.dimensao.w / 4));
    dimension.h = 5  * (fontKey.dimensao.h + int(fontKey.dimensao.h / 4));
}

//Estilo Visual a ser Aplicado no Componente

void UIKeyboard::setVisual(UserInterface::Look::UIBackground * visual)
{
    this->visual = visual;
}

void UIKeyboard::setColorCursor(const GBF::Color::Pallete & r, const GBF::Color::Pallete & g, const GBF::Color::Pallete & b)
{
    corCursor.r = r;
    corCursor.g = g;
    corCursor.b = b;
}

} // namespace UserInterface::Componente

} // namespace UserInterface
