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

#include "UIWindow.h"

namespace UserInterface {

namespace Window {

//Construtor
UIWindow::UIWindow()
{
    espacoAntesTexto=0;

    tempoEspera.setTempoOriginal(1);
    tempoEspera.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    tempoEspera.setResetar();
}
//Destrutor
UIWindow::~UIWindow()
{
    if (visual){
        delete(visual);
    }
}
void UIWindow::setDimensao(int largura, int altura)
{
    dimension.w=largura;
    dimension.h=altura;
}
//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindow::inicializar()
{
    if (visual!=NULL){
        visual->aplicar(position,dimension);
    }
}
//Estilo Visual a ser Aplicado no Componente
void UIWindow::setVisual(UserInterface::Visual::UIVisual * visual)
{
    this->visual=visual;
}
//atualiza as informações do componente (posicao, dimensao, estado)
void UIWindow::atualizar()
{
    tempoEspera.processar();
}
//desenha os componentes vistuais
void UIWindow::desenhar()
{
    desenharBackground();

    desenharConteudo();

    desenharForeground();
}
//Desenha o background da caixa de texto

//Desenha o background da caixa de texto
void UIWindow::desenharBackground()
{
    if (visual!=NULL){
        visual->desenhar();
    }
}
//Desenha o botão de ação da janela

//Desenha a camada de decoração da janela (botões)
void UIWindow::desenharForeground()
{
}

} // namespace UserInterface::Window

} // namespace UserInterface
