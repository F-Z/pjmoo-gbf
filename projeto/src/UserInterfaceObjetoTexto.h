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

#ifndef _USERINTERFACEOBJETOTEXTO_H
#define _USERINTERFACEOBJETOTEXTO_H

#include <string>

#include "GBF_define.h"

enum UserInterfaceTextoAlinhamento {
  TEXTO_NORMAL=0,
  TEXTO_CENTRALIZADO=1

};
//Texto Alinhado a esquerda
//Texto Alinhado ao Centro (Centralizado)
class UserInterfaceObjetoTexto
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
    UserInterfaceObjetoTexto();

    //Destrutor
    ~UserInterfaceObjetoTexto();

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
    void setAlinhamento(UserInterfaceTextoAlinhamento alinhamento);

    //Retorna o alinhamento utilizado
    UserInterfaceTextoAlinhamento getAlinhamento();


  protected:
    Dimensao dimensaoLetra;

    UserInterfaceTextoAlinhamento alinhamento;

};
#endif
