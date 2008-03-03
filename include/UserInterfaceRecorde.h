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

//Descrição: 
//    Classe para entrada de novo recorde.
//Motivação:
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

    //Define a posição da Interface de recordes
    void setPosicao(int x, int y);

    //Define a fonte a ser usada pelo label
    void setFonteLabel(std::string fonte);

    //Adiciona referência para o Sistema Gráfico GFX
    void setGFX(GraphicSystemGFX * gfx);

    //Adiciona referência para o Sistema de Escrita
    void setWriteManager(WriteSystemManager * write);

    //Retorna o TopSystemRecorde
    TopSystemRecorde getRecorde();

    //Atribui um TopSystemRecorde para complementar os dados
    void setRecorde(TopSystemRecorde recorde);

    //Gerencia o controle do cursor (navegação) e as opções selecionadas
    bool controle();

    //Desenha a interface contendo: pontuação, dados do jogador e teclado virtual
    void desenhar();


  protected:
    //Efetua as ações de acordo com a posição do cursor
    bool confirmar();

    //Desenha as caixas de fundo para posicionamento dos dados do jogador e do teclado virtual
    void desenharCaixa();

    //Desenha o teclado virtual
    void desenharMiniTeclado();

    //Desenha o nome do jogador e sua pontuação
    void desenharDados();

    //Efetua o controle sobre a navegação do cursor
    void navegar();

};
#endif
