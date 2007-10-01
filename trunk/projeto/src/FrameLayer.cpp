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

#include "FrameLayer.h"

//Construtor
FrameLayer::FrameLayer() 
{
    mapa=NULL;
}
//Destrutor
FrameLayer::~FrameLayer() 
{
    delete[] mapa;
}
//Desenha o mapa
void FrameLayer::desenhar() 
{
    int i,IMG,bloco_y,bloco_x;
    int offset_x, offset_y;
    int l_max, c_max;
    SDL_Rect corte=tamanho;

    Ponto ponto           = camera.getPosicao();
    Dimensao pixelTile    = mundo.getPixelTile();
    Dimensao pixelVisivel = mundo.getPixelVisivel();
    Dimensao tilesMundo   = mundo.getTiles();

    // Tamanho do Bloco
    bloco_y  = ponto.y / pixelTile.h;
    bloco_x  = ponto.x / pixelTile.w;

    // Calcula o Smooth
    offset_y = ponto.y & (pixelTile.h - 1);
    offset_x = ponto.x & (pixelTile.w - 1);


    // Linhas que cabem na tela
    l_max    = (pixelVisivel.h/pixelTile.h);
    if ((pixelVisivel.h % pixelTile.h>0)||(offset_y>0)){
        l_max++;
    }
    // Checa se a linha não ultrapassa o total
    if (l_max>tilesMundo.h){   l_max=tilesMundo.h;   }

    // Colunas que cabem na tela
    c_max    = (pixelVisivel.w/pixelTile.w);
    if ((pixelVisivel.w % pixelTile.w>0)||(offset_x>0)){
        c_max++;
    }
    // Checa se a coluna não ultrapassa o total
    if (c_max>tilesMundo.w){   c_max=tilesMundo.w;   }

    // Calcula a coordenada inicial de Y
    posicao.y=screen_dimensao.top - offset_y;

    for (int l=0; l<l_max; l++){
        // Transforma linha em coordenada do vetor
        i=((l + bloco_y) * tilesMundo.w) + bloco_x;
        // Verifica e corta a imagem da primeira linha

        if (posicao.y<=screen_dimensao.top){
            posicao.y=screen_dimensao.top;
            corte.y=tamanho.y + offset_y;
            corte.h=tamanho.h - offset_y;
        // Verifica e corta a imagem da última linha
        } else if (posicao.y+pixelTile.h>screen_dimensao.bottom){
            corte.h-=(posicao.y+pixelTile.h)-(screen_dimensao.bottom);
        }

        // Calcula a coordenada inicial de X
        posicao.x=screen_dimensao.left - offset_x;
        for (int c=0; c<c_max; c++){
            // Transforma coluna em coordenada do vetor
            IMG=(i)+(c);
            // Verifica e corta a imagem da primeira coluna
            if (posicao.x<=screen_dimensao.left){
                posicao.x=screen_dimensao.left;
                corte.x=tamanho.x + offset_x;
                corte.w=tamanho.w - offset_x;
            // Verifica e corta a imagem da última linha
            } else if (posicao.x+pixelTile.w>screen_dimensao.right){
                corte.w-=(posicao.x+pixelTile.w)-(screen_dimensao.right);
            }

            // Desenha a imagem na tela efetuando corte se necessário
            imagem->desenhar(posicao,tamanho,mapa[IMG],corte);
            // Move x para a próxima posição
            posicao.x+=corte.w;
            // Restaura informações de corte para coluna
            corte.w=tamanho.w;
            corte.x=tamanho.x;
        }
        // Move y para a próxima posição
        posicao.y+=corte.h;
        // Restaura informações de corte para coluna
        corte.y=tamanho.y;
        corte.h=tamanho.h;
    }
}
//Retorna a area do layer relacionado com o ponto de desenho (x e y) e  o tamanho interno (w e h)
Area FrameLayer::getArea() 
{
    return screen_dimensao;
}
//Distancia restante para finalizar Scrolling Vertical
int FrameLayer::getDistanciaScrollVertical() 
{
    Ponto ponto = camera.getPosicao();

    return ponto.y;
}
//Porcentagem percorrida do Scroll Horizontal
int FrameLayer::getPorcentagemScrollHorizontal() 
{
    return 0;
}
//Porcentagem percorrida do Scroll Vertical
int FrameLayer::getPorcentagemScrollVertical() 
{
    Dimensao tilesMundo = mundo.getTiles();
    Ponto ponto         = camera.getPosicao();

    int total = tilesMundo.h * mundo.getPixelTileVertical();
    total = 100-int((100*ponto.y)/total);
    return total;
}
//Distancia total do Scrolling Vertical
int FrameLayer::getTotalScrollVertical() 
{
    Dimensao tilesMundo = mundo.getTiles();
    Ponto ponto         = camera.getPosicao();

    return int(tilesMundo.h * mundo.getPixelTileVertical());
}
//Inicializa tiles com valores do arquivo
void FrameLayer::iniciarArquivo(std::string arquivo) 
{
    FILE *handleArquivo;
    handleArquivo = fopen(arquivo.c_str(),"rb");
    Dimensao tilesMundo = mundo.getTiles();

    if (handleArquivo){
        fread(mapa,sizeof(mapa),(tilesMundo.w*tilesMundo.h), handleArquivo);
    }
    fclose(handleArquivo);

    camera.setMundo(&mundo);
}
//Iniciar preenchendo apenas com o quadro informado
void FrameLayer::iniciarCom(int quadro) 
{
    Dimensao tilesMundo   = mundo.getTiles();
    int total = tilesMundo.w*tilesMundo.h;

    for (int i=0; i<total; i++){
        mapa[i]=quadro;
    }

    camera.setMundo(&mundo);
}
//Iniciar ordenado até o quadro informado
void FrameLayer::iniciarOrdenado(int quadroMaximo) 
{
    Dimensao tilesMundo   = mundo.getTiles();
    int total = tilesMundo.w*tilesMundo.h;
    int contador=0;

    for (int i=0; i<total; i++){
        mapa[i]=contador;
        contador++;
        if (contador>quadroMaximo){
            contador=0;
        }
    }

    camera.setMundo(&mundo);
}
//Inicializa tiles de forma aleatória
void FrameLayer::iniciarRandomico(int range) 
{
    Dimensao tilesMundo = mundo.getTiles();
    int total = tilesMundo.w*tilesMundo.h;

    for (int i=0; i<total; i++){
        mapa[i]=rand()%range;
    }

    camera.setMundo(&mundo);
}
//Informa o posicionamento da area de desenho e as suas dimensões internas
void FrameLayer::setFrame(int left, int top, int largura, int altura) 
{
    screen_dimensao.top    = top;
    screen_dimensao.left   = left;
    screen_dimensao.bottom = top  + altura;
    screen_dimensao.right  = left + largura;

    mundo.setPixelVisivel(largura,altura);
}
//Informa o tamanho do mundo em tiles horizontais e verticais
void FrameLayer::setTiles(int largura, int altura) 
{
    mundo.setTiles(largura,altura);

    if (mapa!=NULL){
        delete[] mapa;
    }
    mapa = new int[largura*altura];
}
//Informa o tamanho em pixels dos tiles usados no layer
void FrameLayer::setPixelTile(int largura, int altura) 
{
    mundo.setPixelTile(largura,altura);
}
//Desenha a grade de tiles do mapa
void FrameLayer::showGrade() 
{
/*
    int offset_x, offset_y;
    int linha_x, linha_y;
    int bloco_x,bloco_y;
    int c_max,l_max;

    GraphicSystemGFX *gfx = GraphicSystemGFX::getInstance();

    // Bloco vertical
    bloco_y  = (int(ponto_virtual.y) / tile.h);
    // Bloco horizontal
    bloco_x  = (int(ponto_virtual.x) / tile.w);
    // Calcula o Smooth de Y
    offset_y = int(ponto_virtual.y) & (tile.h - 1);
    // Calcula o Smooth de X
    offset_x = int(ponto_virtual.x) & (tile.w - 1);

    // Linhas que cabem na tela
    l_max    = (area_visivel.h/tile.h);
    if ((area_visivel.h % tile.h>0)||(offset_y>0)){
        l_max++;
    }
    // Checa se a linha não ultrapassa o total
    if (l_max>mundo.h){   l_max=mundo.h;   }

    // Colunas que cabem na tela
    c_max    = (area_visivel.w/tile.w);
    if ((area_visivel.w % tile.w>0)||(offset_x>0)){
        c_max++;
    }
    // Checa se a coluna não ultrapassa o total
    if (c_max>mundo.w){   c_max=mundo.w;   }

    gfx->setColor(0,255,0);
    // Calcula a coordenada inicial de Y
    linha_y=screen_dimensao.top - offset_y;
    for (int l=0; l<l_max; l++){
        // Verifica se a divisão das linhas está em área visivel
        if ((linha_y>=screen_dimensao.top)&&(linha_y<=screen_dimensao.bottom)){
            gfx->linha(screen_dimensao.left,linha_y,screen_dimensao.right,linha_y);
        }
        // Move y para a próxima posição
        linha_y+=tamanho.h;
    }

    linha_x=screen_dimensao.left - offset_x;
    for (int c=0; c<c_max; c++){
        // Verifica se a divisão das colunas está em área visivel
        if ((linha_x>=screen_dimensao.left)&&(linha_x<=screen_dimensao.right)){
            gfx->linha(linha_x,screen_dimensao.top,linha_x,screen_dimensao.bottom);
        }
        // Move x para a próxima posição
        linha_x+=tamanho.w;
    }
*/
}
