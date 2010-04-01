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
#ifndef _GTGAME_H
#define _GTGAME_H

#include "GTTime.h"

namespace GAT {

enum StateGame {
    GAT_EJ_INICIO = 0,
    GAT_EJ_NOVO = 10,
    GAT_EJ_EXECUTANDO = 20,
    GAT_EJ_PAUSE = 30,
    GAT_EJ_FASE_CARREGAR = 40,
    GAT_EJ_FASE_FINALIZADA = 50,
    GAT_EJ_GAMEOVER = 60,
    GAT_EJ_ZERADO = 70
};

class GTGame : public GTTime
{
    public:
        //Construtor
        GTGame();

        //Destrutor
        virtual ~GTGame();

        StateGame processarEstadoJogo();


    protected:
        void loopJogo();

        void setJogoNovo();

        //Coloca o jogo em estado de execução imediata
        void setJogoExecutando();

        void setJogoPause();

        void setJogoFaseCarregar();

        void setJogoFaseFinalizada();

        void setJogoGameOver();

        void setJogoZerado();

        virtual void jogoNovo() = 0;

        virtual void jogoExecutando() = 0;

        virtual void jogoPause() = 0;

        virtual void jogoFaseCarregar() = 0;

        virtual void jogoFaseFinalizada() = 0;

        virtual void jogoGameOver() = 0;

        virtual void jogoZerado() = 0;

        virtual void gatilhoJogoNovo();

        virtual void gatilhoJogoExecutando();

        virtual bool gatilhoJogoFaseCarregar();

        virtual bool gatilhoJogoFaseFinalizada();

        void setJogoInicio();


    private:

        StateGame estado;

};

} // namespace GAT
#endif
