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
#ifndef _FRAMELAYER_H
#define _FRAMELAYER_H

#include "SpriteInterface.h"
#include "LayerCamera.h"
#include "GBF.h"
#include <string>

#include "LayerMundo.h"

namespace GBF {

namespace Image {

/** Representa��o de Imagens(Tiles) para composi��o das telas  */

namespace Layer {

/** Classe para Desenho de TileMaps */

class FrameLayer : public GBF::Image::SpriteInterface {

    public:

        /** Construtor */
        FrameLayer();

        /** Destrutor */
        virtual ~FrameLayer();

        /** Desenha o mapa */
        void draw();

        /** Retorna a area do layer relacionado com o ponto de desenho (x e y) e  o tamanho interno (w e h) */
        GBF::Area getArea();

        /** Distancia restante para finalizar Scrolling Vertical */
        int getDistanciaScrollVertical();

        /** Porcentagem percorrida do Scroll Horizontal */
        int getPorcentagemScrollHorizontal();

        /** Porcentagem percorrida do Scroll Vertical */
        int getPorcentagemScrollVertical();

        /** Distancia total do Scrolling Vertical */
        int getTotalScrollVertical();

        /** Inicializa tiles com valores do arquivo */
        void iniciarArquivo(std::string arquivo);

        /** Iniciar preenchendo apenas com o quadro informado */
        void iniciarCom(int quadro);

        /** Iniciar ordenado at� o quadro informado */
        void iniciarOrdenado(int quadroMaximo);

        /** Inicializa tiles de forma aleat�ria */
        void iniciarRandomico(int range);

        /** Informa o posicionamento da area de desenho e as suas dimens�es internas */
        void setFrame(int left, int top, int largura, int altura);

        /** Informa o tamanho do mundo em tiles horizontais e verticais */
        void setTiles(int largura, int altura);

        /** Informa o tamanho em pixels dos tiles usados no layer */
        void setPixelTile(int largura, int altura);

        /** Desenha a grade de tiles do mapa */
        void showGrade();

        /** Carrega tilemap apartir de um vetor pr�-alocado em memoria. */
        void loadMapFromMemory(int vetor[]);

        /** Carrega mapa de colis�o apartir de um vetor pr�-alocado em memoria. */
        void loadCollisionFromMemory(int vetor[]);

        /** Retorna o tipo de colis�o usado no brick */
        int getCollisionType(int index);

        /** Retorna o tipo de imagem usado no brick */
        int getImageType(int index);

        LayerMundo mundo;

        LayerCamera camera;

    protected:

        int * mapa;

        int * mapaColisao;

        GBF::Area screen_dimensao;

        friend class LayerManager;


};

} // namespace GBF::Image::Layer

} // namespace GBF::Image

} // namespace GBF

#endif
