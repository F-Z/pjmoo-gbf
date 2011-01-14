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
#ifndef _SPRITE_H
#define _SPRITE_H

#include "ImageBuffer.h"
#include "GBF.h"
#include "SpriteInterface.h"

namespace GBF {

namespace Image {

/** Representação de Imagens (Sprites) para personagens e objetos */

namespace Sprite {

/** Definição de direções */
enum Direcao {
    DR_CIMA,
    DR_DIREITA,
    DR_BAIXO,
    DR_ESQUERDA,
    DR_CIMADIREITA,
    DR_BAIXODIREITA,
    DR_BAIXOESQUERDA,
    DR_CIMAESQUERDA
};

/** Definição de Status */

struct DirecaoStatus {
    bool cima;

    bool direita;

    bool baixo;

    bool esquerda;

    bool cimaDireita;

    bool baixoDireita;

    bool baixoEsquerda;

    bool cimaEsquerda;

};

/** Classe para representação básica de um Sprite */

class Sprite : public GBF::Image::SpriteInterface
{

    public:
        /** Destrutor */
        virtual ~Sprite();

        void create(int left, int top, int largura, int altura, int quantitadeQuadro, int repeticaoQuadro, GBF::Kernel::Graphic::ImageBuffer * gsiBuffer);

        /** Desenha o sprite na tela, com base na última posição informada ou desenhada */
        virtual void draw(int x, int y);

        /** Desenha o sprite na tela, com base na última posição informada ou desenhada */
        virtual void draw();

        /** Retorna a dimensão do sprite 'width' e 'height' */
        GBF::Dimension getTamanho();

        /** Colisão baseada no tamanho dos Sprites */
        bool isCollision(Sprite * sprite);

        /** Posiciona o Sprite na tela */
        void setPoint(GBF::Point point);

        /** Posiciona o Sprite na tela */
        virtual void setPoint(int x, int y);


    protected:
        /** Construtor */
        Sprite();

};

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF

#endif
