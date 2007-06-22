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

#ifndef _PARTICLESYSTEMEFEITO_H
#define _PARTICLESYSTEMEFEITO_H

#include "GBF_define.h"
#include "UtilColor.h"
#include <deque>
#include "GraphicSystem.h"

//Descrição:
//    Estrutura para representação de uma particula
//Motivação:
//    Permitir representar uma unidade com caracteristicas e ciclo de vida próprios
struct Particula
{
    PontoVirtual velocidade;

    PontoVirtual posicao;

    int energia;

    HSV cor;

    bool ativa;

};
//Descrição: 
//    Classe abstrata que permite agrupamente de particulas
//Motivação:
//    Permitir gerenciar um grupo de unidades com ciclo de vida semelhantes
class ParticleSystemEfeito {
  public:
    //Construtor
    ParticleSystemEfeito();

    //Destrutor
    virtual ~ParticleSystemEfeito();

    //Configura a quantidade de unidades que serão criadas
    void setQuantidade(int quantidade);

    //Indica se todas as unidades já terminaram o ciclo de vida
    virtual bool isTerminou();

    //Desenha todas as unidades
    virtual void desenhar();

    //Inicializa o sistema de particulas
    virtual void criar(int x, int y) = 0;

    //Executa as unidades do sistema
    virtual void executar() = 0;


  protected:
    std::deque<Particula> lista;
    static GraphicSystem * graphicSystem;

};
#endif
