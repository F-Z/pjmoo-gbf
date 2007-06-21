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

#ifndef _TIMERSYSTEMCRONOMETROABSTRACT_H
#define _TIMERSYSTEMCRONOMETROABSTRACT_H

#include "GBF_define.h"

//Descri��o: 
//    Valores para marca��o da passagem do tempo
//Motiva��o:
//    Fornecer um conjunto de valores para medi��o da passagem de tempo
//

enum EnumTempo {
  TEMPO_CENTESIMO =100,
  TEMPO_MEIO =500,
  TEMPO_SEGUNDO =1000

};
//Descri��o: 
//    Valores para  indica��o de estado
//Motiva��o:
//    Fornecer um conjunto de valores para defini��o da m�quina de estados dos cronometros
enum EnumCronometro {
  //Restaura tempo original e passa para o estado de iniciar
  CRONOMETRO_RESETAR,
  //Inicio do cronometro
  CRONOMETRO_INICIAR,
  //Pausa cronometro
  CRONOMETRO_PAUSAR,
  //continua contagem do cronometro
  CRONOMETRO_CONTINUAR,
  //Cronometro em execu��o
  CRONOMETRO_EXECUTAR,
  //Cronometro finalizado
  
  CRONOMETRO_TERMINAR
};
//Descri��o: 
//    Classe abstrata para cria��o de cronometros
//Motiva��o:
//    Fornecer um conjunto de m�todos padr�es para controle de tempo
class TimerSystemCronometroAbstract {
  protected:
    Uint32 tempoUnidade;

    Uint32 tempoInicial;

    Uint32 tempoAtual;

    int tempoCorrente;

    int tempoOriginal;

    EnumCronometro eCronometro;

    //Executa este m�todo quando o estado � CRONOMETRO_EXECUTAR
    virtual void executar() = 0;

    //Executa este m�todo quando o estado � CRONOMETRO_RESETAR
    virtual void resetar();

    //Executa este m�todo quando o estado � CRONOMETRO_INICIAR
    virtual void iniciar();

    //Executa este m�todo quando o estado � CRONOMETRO_CONTINUAR
    virtual void continuar();

    //Inicia o contado de tempo
    void execTempoInicial();

    //Muda o estado para CRONOMETRO_EXECUTAR
    void setExecutar();

    //Muda o estado para CRONOMETRO_TERMINAR
    void setTerminar();


  public:
    //Construtor 
    TimerSystemCronometroAbstract();

    //Destrutor 
    virtual ~TimerSystemCronometroAbstract();

    //Configura a unidade de tempo a ser usada
    void setUnidade(EnumTempo eTempo);

    //Muda o estado para CRONOMETRO_RESETAR
    void setResetar();


  protected:
    //Muda o estado para CRONOMETRO_INICIAR
    void setIniciar();


  public:
    //Muda o estado para CRONOMETRO_PAUSAR
    void setPausar();

    //Muda o estado para CRONOMETRO_CONTINUAR
    void setContinuar();

    //Centro de processamento de estados
    void processar();

    //Retorna a contagem de tempo corrente
    int getTempo();

    //Adiciona o marcador de tempo inicial
    void setTempoOriginal(int tempo);

    //Informa se o tempo j� terminou
    bool isTerminou();

};
#endif
