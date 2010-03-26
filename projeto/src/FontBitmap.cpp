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

FontBitmap::FontBitmap()
{
}

FontBitmap::~FontBitmap()
{
}

bool FontBitmap::loadFromFile(std::string fileName)
{
    FILE *ARQ_FONTE;
    std::string txt = "";
    image = IMG_Load(fileName.c_str());

    if (image != NULL) {
        converterSurface();
        //setColorKey(0,0,0);

        txt = fileName.substr(0, fileName.length() - 4);
        txt += ".dat";

        ARQ_FONTE = fopen(txt.c_str(), "rb");

        if (ARQ_FONTE != NULL) {
            fread(&largura, 256, 1, ARQ_FONTE);
            fclose(ARQ_FONTE);
        } else {
            for (int l = 0;l < 256; l++) {
                largura[l] = image->w / 16;
            }
        }

        dimensaoQuadro.w = image->w / 16;
        dimensaoQuadro.h = image->h / 16;
        calculateSize();

        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;

        return false;
    }
}

void FontBitmap::setDimension(int largura, int altura)
{
    for (int i = 0;i < 256;i++) {
        this->largura[i] = largura;
    }

    dimensaoPadrao.w = largura;
    dimensaoPadrao.h = altura;
}

int FontBitmap::getHeight()
{
    return dimensaoPadrao.h;
}

int FontBitmap::getWidth()
{
    return dimensaoPadrao.w;
}

GBF::Dimension FontBitmap::getDimension()
{
    return dimensaoPadrao;
}

void FontBitmap::write(const char * words, int x, int y)
{
    int i, t = strlen(words);
    unsigned char l;
    point.x = x;
    point.y = y;

    for (i = 0; i < t; i++) {
        l = words[i];

        tamanho.left = (l % 16) * dimensaoQuadro.w;
        tamanho.right  = largura[l];
        tamanho.top  = (l / 16) * dimensaoQuadro.h;
        tamanho.bottom = dimensaoQuadro.h;

        screen->blitSurface(image, tamanho, point);
        point.y = y;
        point.x = point.x + largura[l];
    }
}

int FontBitmap::getLineWidth(const char * palavra)
{
    int tamanhoPixel = 0;
    int t = strlen(palavra);
    unsigned char l;

    for (int i = 0; i < t; i++) {
        l = palavra[i];
        tamanhoPixel = tamanhoPixel + largura[l];
    }

    return tamanhoPixel;
}

void FontBitmap::calculateSize()
{
    int maior = 0;

    for (int i = 0; i < 256; i++) {
        if (largura[i] > maior) {
            maior = largura[i];
        }
    }

    dimensaoPadrao.w = maior;
    dimensaoPadrao.h = dimensaoQuadro.h;
}

void FontBitmap::convertSurface()
{
    SDL_Surface *tmp = SDL_DisplayFormatAlpha(image);
    SDL_FreeSurface(image);
    image = tmp;
}

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
