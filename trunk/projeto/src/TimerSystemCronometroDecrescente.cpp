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

#include "TimerSystemCronometroDecrescente.h"

//Executa este método quando o estado é CRONOMETRO_EXECUTAR
void TimerSystemCronometroDecrescente::executar() 
{
    tempoAtual = SDL_GetTicks();

    if (tempoAtual-tempoInicial>=tempoUnidade){
        tempoCorrente--;

        if (tempoCorrente<=0){
            tempoCorrente=0;
            setTerminar();
        }

        execTempoInicial();
    }
}
//Construtor
TimerSystemCronometroDecrescente::TimerSystemCronometroDecrescente() 
{

}
//Destrutor
TimerSystemCronometroDecrescente::~TimerSystemCronometroDecrescente() 
{

}
