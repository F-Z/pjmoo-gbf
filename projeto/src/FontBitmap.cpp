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

#include "FontBitmap.h"

namespace GBF {

namespace Kernel {

namespace Write {

//Destrutor
FontBitmap::~FontBitmap()
{
    //UtilLog::getInstance()->status("[Fonte Removido(a)]");
}
//Carrega arquivo de imagem contendo o desenho das letras.
//Obs.: Se a imagem tiver arquivo de dimensão das letras este será carregado, caso contrario será utilizado um valor default tanto para largura como altura
bool FontBitmap::loadFromFile(std::string ARQUIVO)
{
    FILE *ARQ_FONTE;
    std::string txt="";
    imagem = IMG_Load(ARQUIVO.c_str());

    if (imagem!=NULL){
        converterSurface();
        //setColorKey(0,0,0);

        txt=ARQUIVO.substr(0,ARQUIVO.length()-4);
        txt+=".dat";

        ARQ_FONTE = fopen(txt.data(),"rb");

        if (ARQ_FONTE!=NULL){
            fread(&largura, 256, 1, ARQ_FONTE);
            fclose(ARQ_FONTE);
        } else {
            for (int l=0;l<256;l++){
                largura[l] = imagem->w/16;
            }
        }

        dimensaoQuadro.w=imagem->w/16;
        dimensaoQuadro.h=imagem->h/16;

        checkar();
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;

        return false;
    }
}
//Configura altura e largura padrão para todas as letras.
//Obs.: A altura e largura devem ser suficientes para evitar que a letra seja desenhada cortada
void FontBitmap::setDimensao(int largura, int altura)
{
    for (int i=0;i<256;i++){
        this->largura[i] = largura;
    }

    dimensaoPadrao.w=largura;
    dimensaoPadrao.h=altura;
}
//Retorna a altura padrão
int FontBitmap::getAltura()
{
    return dimensaoPadrao.h;
}
//Retorna a dimensão (altura e largura) padrão
GBF::Dimensao FontBitmap::getDimensao()
{
    return dimensaoPadrao;
}
//Desenha o texto na tela
void FontBitmap::escrever(const char * PALAVRA, int X, int Y)
{
    int i,t=strlen(PALAVRA);
    unsigned char l;
    posicao.x=X;
    posicao.y=Y;

    for (i=0; i<t; i++){
        l=PALAVRA[i];

        //tamanho.x=(l%16)*32;   tamanho.w=largura[l];//32;
        //tamanho.y=(l/16)*32;   tamanho.h=32;
        tamanho.x=(l%16)*dimensaoQuadro.w; tamanho.w=largura[l];
        tamanho.y=(l/16)*dimensaoQuadro.h; tamanho.h=dimensaoQuadro.h;

        gsScreen->blitSurface(imagem,&tamanho,&posicao);
        posicao.y=Y;
        posicao.x=posicao.x+largura[l];
    }
}
//Retorna em pixel o tamanho da linha
int FontBitmap::getLarguraLinha(const char * palavra)
{
    int tamanhoPixel=0;
    int t=strlen(palavra);
    unsigned char l;

    for (int i=0; i<t; i++){
        l=palavra[i];
        tamanhoPixel=tamanhoPixel+largura[l];
    }

    return tamanhoPixel;
}
//Construtor
FontBitmap::FontBitmap()
{

}
//Define altura e largura padrão baseada na maior altura e largura utilizada.
void FontBitmap::checkar()
{
    int maior=0;
    for (int i=0; i<256; i++){
        if (largura[i]>maior){
            maior=largura[i];
        }
    }

    dimensaoPadrao.w=maior;
    dimensaoPadrao.h=dimensaoQuadro.h;
}
//Converte Surface para formato na inicialização do GraphicSystem
void FontBitmap::converterSurface()
{
    SDL_Surface *tmp = SDL_DisplayFormatAlpha(imagem);
    SDL_FreeSurface(imagem);
    imagem=tmp;
}

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
