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

#include "UserInterfaceWindow.h"

//Construtor
UserInterfaceWindow::UserInterfaceWindow() 
{
    espacoAntesTexto=0;

    tempoEspera.setTempoOriginal(1);
    tempoEspera.setUnidade(TEMPO_MEIO);
    tempoEspera.setResetar();
}
//Destrutor
UserInterfaceWindow::~UserInterfaceWindow() 
{
    if (visual){
        delete(visual);
    }
}
void UserInterfaceWindow::setDimensao(int largura, int altura) 
{
    dimensao.w=largura;
    dimensao.h=altura;
}
//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UserInterfaceWindow::inicializar() 
{
    if (visual!=NULL){
        visual->aplicar(posicao,dimensao);
    }
}
//Estilo Visual a ser Aplicado no Componente
void UserInterfaceWindow::setVisual(UserInterfaceVisual * visual) 
{
    this->visual=visual;
}
//atualiza as informações do componente (posicao, dimensao, estado)
void UserInterfaceWindow::atualizar() 
{
    tempoEspera.processar();
}
//desenha os componentes vistuais
void UserInterfaceWindow::desenhar() 
{
    desenharBackground();

    desenharConteudo();

    desenharForeground();
}
//Desenha o background da caixa de texto

//Desenha o background da caixa de texto
void UserInterfaceWindow::desenharBackground() 
{
    if (visual!=NULL){
        visual->desenhar();
    }
}
//Desenha o botão de ação da janela

//Desenha a camada de decoração da janela (botões)
void UserInterfaceWindow::desenharForeground() 
{
}
