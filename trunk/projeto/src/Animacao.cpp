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

#include "Animacao.h"

namespace GBF {

namespace Imagem {

namespace Sprite {

//Construtor
Animacao::Animacao()
{
    automatico = false;

    frame.atual = 0;
    frame.total = 0;

    repeticao.atual = 0;
    repeticao.total = 0;
}
//Ajusta a area de corte do sprite - posicionamento nos frames
void Animacao::ajustarCorte(int direcao, int largura)
{
    areaCorte.x = (direcao) * (largura * frame.total);
}
//Informa a quantidade de quadros e a taxa de repetição
void Animacao::config(int quantidade, int taxaRepeticao)
{
    frame.total     = quantidade;
    repeticao.total = taxaRepeticao;
}
//Informa se animação está no fim - último frame
bool Animacao::isFim()
{
//verificar se deve-se utilizar 'repeticao.total
    if ((frame.atual==frame.total-1) && (repeticao.atual==repeticao.total)){
    //if (frame.atual==frame.total-1){
        return true;
    } else {
        return false;
    }
}
//Informa se animação está no inicio - primeiro frame
bool Animacao::isInicio()
{
    if (frame.atual==0){
        return true;
    } else {
        return false;
    }
}
//Retorna a dimensão do quadro
SDL_Rect Animacao::getDimensaoFrame()
{
    return areaCorte;
}
int Animacao::processar()
{
    if (automatico){
        animar();
    }

    return frame.atual;
}
//Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem
void Animacao::processarManual()
{
    animar();
}
//Define se a animação é automática ou manual
void Animacao::setAutomatico(bool automatico)
{
    this->automatico=automatico;
}
//Define a dimensão do quadro
void Animacao::setDimensaoFrame(const SDL_Rect & area)
{
    areaCorte=area;
}
//Coloca a animação no primeiro frame
void Animacao::setInicio()
{
    repeticao.atual = 0;
    frame.atual     = 0;
}
//Informa o quadro a ser usado na animação
void Animacao::setFrame(int quadro)
{
    if (quadro>=0){
        if (quadro<frame.total){
            frame.atual=quadro;
        } else {
            frame.atual=frame.total-1;
        }
    }
}
//Anima o Sprite de forma automática
int Animacao::animar()
{
    repeticao.atual++;

    if (repeticao.atual>repeticao.total){
        frame.atual++;
        if (frame.atual>=frame.total){
            frame.atual = 0;
        }
        repeticao.atual = 0;
    }

    return frame.atual;
}

} // namespace GBF::Imagem::Sprite

} // namespace GBF::Imagem

} // namespace GBF
