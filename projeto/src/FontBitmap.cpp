/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "FontBitmap.h"

namespace GBF {

namespace Kernel {

namespace Write {

/** Destrutor */
FontBitmap::~FontBitmap()
{
    //UtilLog::getInstance()->status("[Fonte Removido(a)]");
}
/** Carrega arquivo de imagem contendo o desenho das letras.
Obs.: Se a imagem tiver arquivo de dimensão das letras este será carregado, caso contrario será utilizado um valor default tanto para largura como altura */
bool FontBitmap::loadFromFile(std::string ARQUIVO)
{
    FILE *ARQ_FONTE;
    std::string txt = "";
    image = IMG_Load(ARQUIVO.c_str());

    if (image != NULL){
        converterSurface();
        //setColorKey(0,0,0);

        txt = ARQUIVO.substr(0, ARQUIVO.length() - 4);
        txt += ".dat";

        ARQ_FONTE = fopen(txt.data(), "rb");

        if (ARQ_FONTE != NULL){
            fread(&largura, 256, 1, ARQ_FONTE);
            fclose(ARQ_FONTE);
        } else {
            for (int l = 0;l < 256;l++){
                largura[l] = image->w / 16;
            }
        }

        dimensaoQuadro.w = image->w / 16;
        dimensaoQuadro.h = image->h / 16;

        checkar();
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;

        return false;
    }
}
/** Configura altura e largura padrão para todas as letras.
Obs.: A altura e largura devem ser suficientes para evitar que a letra seja desenhada cortada */
void FontBitmap::setDimensao(int largura, int altura)
{
    for (int i = 0;i < 256;i++){
        this->largura[i] = largura;
    }

    dimensaoPadrao.w = largura;
    dimensaoPadrao.h = altura;
}
/** Retorna a altura padrão */
int FontBitmap::getAltura()
{
    return dimensaoPadrao.h;
}
/** Retorna a dimensão (altura e largura) padrão */
GBF::Dimension FontBitmap::getDimensao()
{
    return dimensaoPadrao;
}
/** Desenha o texto na tela */
void FontBitmap::write(const char * words, int x, int y)
{
    int i, t = strlen(words);
    unsigned char l;
    point.x = x;
    point.y = y;

    for (i = 0; i < t; i++){
        l = words[i];

        //tamanho.x=(l%16)*32;   tamanho.w=largura[l];//32;
        //tamanho.y=(l/16)*32;   tamanho.h=32;
        tamanho.left = (l % 16) * dimensaoQuadro.w;
        tamanho.right  = largura[l];
        tamanho.top  = (l / 16) * dimensaoQuadro.h;
        tamanho.bottom = dimensaoQuadro.h;

        screen->blitSurface(image, tamanho, point);
        point.y = y;
        point.x = point.x + largura[l];
    }
}
/** Retorna em pixel o tamanho da linha */
int FontBitmap::getLarguraLinha(const char * palavra)
{
    int tamanhoPixel = 0;
    int t = strlen(palavra);
    unsigned char l;

    for (int i = 0; i < t; i++){
        l = palavra[i];
        tamanhoPixel = tamanhoPixel + largura[l];
    }

    return tamanhoPixel;
}
/** Construtor */
FontBitmap::FontBitmap()
{
}
/** Define altura e largura padrão baseada na maior altura e largura utilizada. */
void FontBitmap::checkar()
{
    int maior = 0;
    for (int i = 0; i < 256; i++){
        if (largura[i] > maior){
            maior = largura[i];
        }
    }

    dimensaoPadrao.w = maior;
    dimensaoPadrao.h = dimensaoQuadro.h;
}
/** Converte Surface para formato na inicialização do GraphicSystem */
void FontBitmap::converterSurface()
{
    SDL_Surface *tmp = SDL_DisplayFormatAlpha(image);
    SDL_FreeSurface(image);
    image = tmp;
}

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
