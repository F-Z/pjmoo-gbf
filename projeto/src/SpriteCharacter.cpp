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
#include "SpriteCharacter.h"

namespace GBF
{

namespace Image {

namespace Sprite {

//Destrutor
SpriteCharacter::~SpriteCharacter()
{

}

void SpriteCharacter::setDirection(Direcao DIR)
{
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
                    //Sem modifica��o da dire��o. Op��o 'default' apenas
                    //para respeitar a recomenda��o do compilador
                    break;
            }

            break;
    }

    animation.processManual();
}

void SpriteCharacter::setQtdDirecoes(int QTD)
{
    qtdDirecao = QTD;
}

void SpriteCharacter::draw(int x, int y)
{
    animation.cutSet(direction, tamanho.right);

    Sprite::draw(x, y);
}

//Retorna a quantidade de dire��es que o personagem possui
int SpriteCharacter::getQtdDirecoes()
{
    return qtdDirecao;
}

Direcao SpriteCharacter::getDirection()
{
    return direction;
}

//Construtor
SpriteCharacter::SpriteCharacter()
{
    direction = DR_CIMA;
    qtdDirecao = 4;
}

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF
