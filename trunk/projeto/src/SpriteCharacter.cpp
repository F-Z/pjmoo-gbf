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

#include "SpriteCharacter.h"

namespace GBF {

namespace Imagem {

namespace Sprite {

//Destrutor
SpriteCharacter::~SpriteCharacter() {

}

void SpriteCharacter::setDirection(Direcao DIR) {
    switch (qtdDirecao) {

        case 8:

        case 4:
            direction = DIR;
            break;

        case 3:

            switch (DIR) {

                case DR_ESQUERDA:
                    direction = DR_BAIXO;
                    break;

                case DR_BAIXO:
                    break;

                default:
                    direction = DIR;
                    break;
            }

            break;

        case 2:

            switch (DIR) {

                case DR_ESQUERDA:

                case DR_CIMA:
                    direction = DR_CIMA;
                    break;

                case DR_BAIXO:

                case DR_DIREITA:
                    direction = DR_DIREITA;
                    break;

                default:
                    //Sem modificação da direção. Opção 'default' apenas
                    //para respeitar a recomendação do compilador
                    break;
            }

            break;
    }

    animacao.processManual();
}

void SpriteCharacter::setQtdDirecoes(int QTD) {
    qtdDirecao = QTD;
}

void SpriteCharacter::desenhar(int x, int y) {
    animacao.cutSet(direction, tamanho.w);

    Sprite::desenhar(x, y);
}

//Retorna a quantidade de direções que o personagem possui
int SpriteCharacter::getQtdDirecoes() {
    return qtdDirecao;
}

Direcao SpriteCharacter::getDirection() {
    return direction;
}

//Construtor
SpriteCharacter::SpriteCharacter() {
    direction = DR_CIMA;
    qtdDirecao = 4;
}

} // namespace GBF::Imagem::Sprite

} // namespace GBF::Imagem

} // namespace GBF
