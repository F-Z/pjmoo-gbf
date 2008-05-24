#ifndef _FRAMELAYER_H
#define _FRAMELAYER_H

////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#include "SpriteInterface.h"
#include "LayerCamera.h"
#include "GBF.h"
#include <string>

#include "LayerMundo.h"

namespace GBF {

namespace Imagem {

namespace Layer {

//Classe para Desenho de TileMaps
class FrameLayer : public GBF::Imagem::SpriteInterface
{
  public:
    LayerCamera camera;

    //Construtor
    FrameLayer();

    //Destrutor
    virtual ~FrameLayer();

    //Desenha o mapa
    void desenhar();

    //Retorna a area do layer relacionado com o ponto de desenho (x e y) e  o tamanho interno (w e h)
    GBF::Area getArea();

    //Distancia restante para finalizar Scrolling Vertical
    int getDistanciaScrollVertical();

    //Porcentagem percorrida do Scroll Horizontal
    int getPorcentagemScrollHorizontal();

    //Porcentagem percorrida do Scroll Vertical
    int getPorcentagemScrollVertical();

    //Distancia total do Scrolling Vertical
    int getTotalScrollVertical();

    //Inicializa tiles com valores do arquivo
    void iniciarArquivo(std::string arquivo);

    //Iniciar preenchendo apenas com o quadro informado
    void iniciarCom(int quadro);

    //Iniciar ordenado até o quadro informado
    void iniciarOrdenado(int quadroMaximo);

    //Inicializa tiles de forma aleatória
    void iniciarRandomico(int range);

    //Informa o posicionamento da area de desenho e as suas dimensões internas
    void setFrame(int left, int top, int largura, int altura);

    //Informa o tamanho do mundo em tiles horizontais e verticais
    void setTiles(int largura, int altura);

    //Informa o tamanho em pixels dos tiles usados no layer
    void setPixelTile(int largura, int altura);

    //Desenha a grade de tiles do mapa
    void showGrade();


  protected:
    int * mapa;

    LayerMundo mundo;

    GBF::Area screen_dimensao;

  friend class LayerManager;
};

} // namespace GBF::Imagem::Layer

} // namespace GBF::Imagem

} // namespace GBF
#endif
