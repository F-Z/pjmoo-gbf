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
////////////////////////////////////////////////////////////////////////

#include "SpritePersonagem.h"

//Destrutor 
SpritePersonagem::~SpritePersonagem() 
{

}
void SpritePersonagem::setDirecao(DIRECAO DIR) 
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
                            //Sem modificação da direção. Opção 'default' apenas
                            //para respeitar a recomendação do compilador
                        break;
            }
            break;
    }

    animarManual();
}
void SpritePersonagem::setQtdDirecoes(int QTD) 
{
    qtdDirecao=QTD;
}
void SpritePersonagem::desenhar(int x, int y) 
{
    quadro.x= (direcao) * (tamanho.w * frameTotal);

    SpriteAbstract::desenhar(x,y);
}
//Retorna a quantidade de direções que o personagem possui 
int SpritePersonagem::getQtdDirecoes() 
{
    return qtdDirecao;
}
DIRECAO SpritePersonagem::getDirecao() 
{
    return direcao;
}
//Construtor
SpritePersonagem::SpritePersonagem() 
{
    direcao=DR_CIMA;
    automatico=false;
    qtdDirecao=4;
}
