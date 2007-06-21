#ifndef _GRAPHICSYSTEMIMAGE_H
#define _GRAPHICSYSTEMIMAGE_H

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

#include <string>

#include "GraphicSystemScreen.h"
#include "GBF_define.h"

//Definição de area
struct Area
{
    int top;

    int left;

    int bottom;

    int right;

};
class GraphicSystemImage
{
  public:
    //Construtor
    GraphicSystemImage();

    //Destrutor
    virtual ~GraphicSystemImage();

    //Seta nível de transparência 
    void setAlpha(Uint8 ALPHA);

    //Seta cor transparente
    void setColorKey(Uint8 R, Uint8 G, Uint8 B);

    virtual bool carregarArquivo(std::string arquivo) = 0;

    double getTimer();

    SDL_Rect getTamanho();


  protected:
    static GraphicSystemScreen * gsScreen;

    SDL_Surface * imagem;

    static double time;

    SDL_Rect tamanho;

    SDL_Rect posicao;

    //Converte Surface para formato na inicialização do GraphicSystem 
    void converterSurface();


  private:
    static void setGraphicSystemScreen(GraphicSystemScreen * screen);

    static void setTimer(double TEMPO);

  friend class GBF;
  friend class GraphicSystem;
};
#endif
