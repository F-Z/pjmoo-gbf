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
    GAME_START        =  0,
    GAME_NEW          = 10,
    GAME_ON           = 20,
    GAME_PAUSE        = 30,
    GAME_STAGE_LOAD   = 40,
    GAME_STAGE_FINISH = 50,
    GAME_OVER         = 60,
    GAME_FINISH       = 70
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
        void loopGame();

        void setNewGame();

        void setGameStart();

        //Coloca o jogo em estado de execução imediata
        void setOnGame();

        void setGamePause();

        void setLoadStage();

        void setFinishStage();

        void setGameOver();

        void setGameFinish();

        virtual void actionNewGame() = 0;

        virtual void actionOnGame() = 0;

        virtual void screenGamePause() = 0;

        virtual void screenLoadStage() = 0;

        virtual void screenFinishStage() = 0;

        virtual void screenGameOver() = 0;

        virtual void screenGameFinish() = 0;

        virtual void triggerNewGame();

        virtual void triggerOnGame();

        virtual bool triggerLoadStage();

        virtual bool triggerFinishStage();

    private:

        StateGame estado;

};

} // namespace GAT
#endif
