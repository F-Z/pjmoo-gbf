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

#ifndef _ANIMACAO_H
#define _ANIMACAO_H

#include <SDL/SDL.h>


namespace GBF {

namespace Imagem {

namespace Sprite {

struct Frame
{
    int atual;

    int total;

};
class Animacao
{
  public:
    //Construtor
    Animacao();

    //Ajusta a area de corte do sprite - posicionamento nos frames
    void ajustarCorte(int direcao, int largura);

    //Informa a quantidade de quadros e a taxa de repetição
    void config(int quantidade, int taxaRepeticao);

    //Informa se animação está no fim - último frame
    bool isFim();

    //Informa se animação está no inicio - primeiro frame
    bool isInicio();

    //Retorna a dimensão do quadro
    SDL_Rect getDimensaoFrame();

    int processar();

    //Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem 
    void processarManual();

    //Define se a animação é automática ou manual 
    void setAutomatico(bool automatico);

    //Define a dimensão do quadro
    void setDimensaoFrame(const SDL_Rect & area);

    //Coloca a animação no primeiro frame
    void setInicio();


  protected:
    bool automatico;

    SDL_Rect areaCorte;

    Frame frame;

    Frame repeticao;

    //Informa o quadro a ser usado na animação
    void setFrame(int quadro);


  private:
    //Anima o Sprite de forma automática 
    int animar();

  friend class SpriteItem;
};

} // namespace GBF::Imagem::Sprite

} // namespace GBF::Imagem

} // namespace GBF
#endif
