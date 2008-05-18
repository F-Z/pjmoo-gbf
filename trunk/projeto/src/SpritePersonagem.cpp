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

#include "SpritePersonagem.h"

namespace GBF {

namespace Imagem {

namespace Sprite {

//Destrutor 
SpritePersonagem::~SpritePersonagem() 
{

}
void SpritePersonagem::setDirecao(Direcao DIR) 
{
    switch (qtdDirecao){
        case 8:
        case 4:
                direcao=DIR;
            break;
        case 3:
                switch (DIR){
                    case DR_ESQUERDA:
                            direcao=DR_BAIXO;
                        break;
                    case DR_BAIXO:
                        break;
                    default:
                            direcao=DIR;
                        break;
                }
            break;
        case 2:
                switch (DIR){
                    case DR_ESQUERDA:
                    case DR_CIMA:
                            direcao=DR_CIMA;
                        break;
                    case DR_BAIXO:
                    case DR_DIREITA:
                            direcao=DR_DIREITA;
                        break;
                    default:
                            //Sem modifica��o da dire��o. Op��o 'default' apenas
                            //para respeitar a recomenda��o do compilador
                        break;
            }
            break;
    }

    animacao.processarManual();
}
void SpritePersonagem::setQtdDirecoes(int QTD) 
{
    qtdDirecao=QTD;
}
void SpritePersonagem::desenhar(int x, int y) 
{
    animacao.ajustarCorte(direcao,tamanho.w);

    Sprite::desenhar(x,y);
}
//Retorna a quantidade de dire��es que o personagem possui 
int SpritePersonagem::getQtdDirecoes() 
{
    return qtdDirecao;
}
Direcao SpritePersonagem::getDirecao() 
{
    return direcao;
}
//Construtor
SpritePersonagem::SpritePersonagem() 
{
    direcao=DR_CIMA;
    qtdDirecao=4;
}

} // namespace GBF::Imagem::Sprite

} // namespace GBF::Imagem

} // namespace GBF
