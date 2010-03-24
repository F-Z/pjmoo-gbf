/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "UIWindow.h"

namespace UserInterface {

namespace Window {

/** Construtor */
UIWindow::UIWindow()
{
    espacoAntesTexto = 0;

    tempoEspera.setInitialTime(1);
    tempoEspera.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoEspera.setReset();
}
/** Destrutor */
UIWindow::~UIWindow()
{
    if (visual){
        delete(visual);
    }
}
void UIWindow::setDimension(int largura, int altura)
{
    dimension.w = largura;
    dimension.h = altura;
}
/** Inicializa as configurações da caixa de texto */
void UIWindow::inicializar()
{
    if (visual != NULL){
        visual->aplicar(point, dimension);
    }
}
/** Estilo Visual a ser Aplicado no Componente */
void UIWindow::setVisual(UserInterface::Look::UIBackground * visual)
{
    this->visual = visual;
}
/** atualiza as informações do componente (posicao, dimensao, estado) */
void UIWindow::update()
{
    tempoEspera.update();
}
/** desenha os componentes vistuais */
void UIWindow::draw()
{
    drawBackground();

    drawContent();

    drawForeground();
}
/** Desenha o background da caixa de texto */
void UIWindow::drawBackground()
{
    if (visual != NULL){
        visual->desenhar();
    }
}
/** Desenha a camada de decoração da janela (botões) */
void UIWindow::drawForeground()
{
}

} // namespace UserInterface::Window

} // namespace UserInterface
