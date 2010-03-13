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

#ifndef _FONTEBITMAP_H
#define _FONTEBITMAP_H

#include "ImageBase.h"
#include <string>

#include "GBF.h"

namespace GBF {

namespace Kernel {

namespace Write {

//Descri��o:
//    Classe que representa fontes originadas de imagens (Font Bitmap).
//Motiva��o:
//    Permitir a personaliza��o dos textos na tela por meio de fontes contidas em imagens
class FonteBitmap : public GBF::Kernel::Graphic::ImageBase
{
  friend class WriteManager;

  public:
    //Destrutor
    virtual ~FonteBitmap();

    //Carrega arquivo de imagem contendo o desenho das letras.
    //Obs.: Se a imagem tiver arquivo de dimens�o das letras este ser� carregado, caso contrario ser� utilizado um valor default tanto para largura como altura
    virtual bool loadFromFile(std::string ARQUIVO);

    //Configura altura e largura padr�o para todas as letras.
    //Obs.: A altura e largura devem ser suficientes para evitar que a letra seja desenhada cortada
    void setDimensao(int largura, int altura);

    //Retorna a largura padr�o
    int getLargura();

    //Retorna a altura padr�o
    int getAltura();

    //Retorna a dimens�o (altura e largura) padr�o
    GBF::Dimensao getDimensao();


  protected:
    //Desenha o texto na tela
    void escrever(const char * PALAVRA, int X, int Y);

    //Retorna em pixel o tamanho da linha
    int getLarguraLinha(const char * palavra);


  private:
    char largura[256];

    GBF::Dimensao dimensaoPadrao;

    GBF::Dimensao dimensaoQuadro;

    //Construtor
    FonteBitmap();

    //Define altura e largura padr�o baseada na maior altura e largura utilizada.
    void checkar();


  protected:
    //Converte Surface para formato na inicializa��o do GraphicSystem
    virtual void converterSurface();

};

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
#endif
