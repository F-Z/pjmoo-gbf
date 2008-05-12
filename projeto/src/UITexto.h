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

#ifndef _UITEXTO_H
#define _UITEXTO_H

#include <string>

#include "GBF_define.h"

namespace UserInterface {

namespace Texto {

enum UITextoAlinhamento {
  TEXTO_NORMAL=0,
  TEXTO_CENTRALIZADO=1

};
//Texto Alinhado a esquerda
//Texto Alinhado ao Centro (Centralizado)
class UITexto
{
  public:
    static const float ENTRELINHA_SIMPLES;

    static const float ENTRELINHA_UMA_MEIA;

    static const float ENTRELINHA_DUPLA;


  protected:
    float entreLinhas;

    std::string fonte;

    std::string chaveTexto;

    int espacoEntreLinhas;


  public:
    //Construtor
    UITexto();

    //Destrutor
    ~UITexto();

    void setFonte(std::string fonte);

    std::string getFonte();

    void setChaveTexto(std::string chaveTexto);

    std::string getChaveTexto();

    void setDimensaoLetra(const Dimensao & dimensao);

    Dimensao getDimensaoLetra();

    //Informa o Estilo de entrelinhas a ser utilizado
    void setEntreLinha(float estiloEntreLinhas);

    //Retorna em pixel o espaçamento entre as linhas
    int getEspacoEntreLinhas();

    //Configura o Alinhamento do Texto
    void setAlinhamento(UITextoAlinhamento alinhamento);

    //Retorna o alinhamento utilizado
    UITextoAlinhamento getAlinhamento();


  protected:
    Dimensao dimensaoLetra;

    UITextoAlinhamento alinhamento;

};

} // namespace UserInterface::Texto

} // namespace UserInterface
#endif
