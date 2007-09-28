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

#ifndef _USERINTERFACERECORDE_H
#define _USERINTERFACERECORDE_H

#include "TopSystemRecorde.h"
#include "WriteSystemManager.h"
#include "GraphicSystemGFX.h"
#include "TimerSystemCronometroDecrescente.h"
#include "TimerSystemCronometroCrescente.h"
#include "GBF_define.h"
#include <string>

#include "InputSystemUtility.h"

//Descri��o: 
//    Classe para entrada de novo recorde.
//Motiva��o:
//    Possibilitar que o jogador informe seu nome e entre na galeria de recordes
class UserInterfaceRecorde : public InputSystemUtility
{
  private:
    TopSystemRecorde recorde;

    WriteSystemManager * wsManager;

    GraphicSystemGFX * gsGFX;

    TimerSystemCronometroDecrescente tempoNavegacao;

    TimerSystemCronometroCrescente tempoBlink;

    Ponto posicao;

    Dimensao dimensaoFonteLabel;

    Dimensao dimensaoFonteTeclado;

    Dimensao caixaTeclado;

    int totalTeclasTeclado;

    unsigned int totalTeclasControle;

    int totalTeclas;

    unsigned int tamanhoMaiorTeclaControle;

    int tecladoSelecao;

    std::string tecladoControle[3];

    //Armazena a letras do teclado
    char miniTeclado[50];

    int nomePosicao;

    std::string fonteLabel;

    std::string fonteTeclado;


  public:
    //Construtor
    UserInterfaceRecorde();

    //Destrutor
    ~UserInterfaceRecorde();

    //Define a fonte a ser usada pelo teclado virtual
    void setFonteTeclado(std::string fonte);

    //Define a posi��o da Interface de recordes
    void setPosicao(int x, int y);

    //Define a fonte a ser usada pelo label
    void setFonteLabel(std::string fonte);

    //Adiciona refer�ncia para o Sistema Gr�fico GFX
    void setGFX(GraphicSystemGFX * gfx);

    //Adiciona refer�ncia para o Sistema de Escrita
    void setWriteManager(WriteSystemManager * write);

    //Retorna o TopSystemRecorde
    TopSystemRecorde getRecorde();

    //Atribui um TopSystemRecorde para complementar os dados
    void setRecorde(TopSystemRecorde recorde);

    //Gerencia o controle do cursor (navega��o) e as op��es selecionadas
    bool controle();

    //Desenha a interface contendo: pontua��o, dados do jogador e teclado virtual
    void desenhar();


  protected:
    //Efetua as a��es de acordo com a posi��o do cursor
    bool confirmar();

    //Desenha as caixas de fundo para posicionamento dos dados do jogador e do teclado virtual
    void desenharCaixa();

    //Desenha o teclado virtual
    void desenharMiniTeclado();

    //Desenha o nome do jogador e sua pontua��o
    void desenharDados();

    //Efetua o controle sobre a navega��o do cursor
    void navegar();

};
#endif
