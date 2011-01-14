/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _GTSTATE_H
#define _GTSTATE_H

#include "GTTime.h"

namespace GAT {

enum State
{
    STATE_START        =  0,
    STATE_QUIT         = 10,
    STATE_MENU         = 20,
    STATE_INTRODUCTION = 30,
    STATE_GAME         = 40,
    STATE_SCORE        = 50
};

class GTState : public GTTime
{
    public:
        /** Construtor */
        GTState();

        /** Destrutor */
        virtual ~GTState();

        State processarEstadoGeral();


    protected:

        virtual bool setMenu();

        virtual void setIntroduction();

        virtual bool setGame();

        virtual bool setScore();

        void setQuit();

        /** Inicializa os recursos utilizados no jogo. Imagens, sons, fontes, configuração do modo gráfico e etc .. */
        virtual void loadResources() = 0;

        virtual void executeMenu() = 0;

        virtual void executeIntroduction() = 0;

        virtual void executeGame() = 0;

        virtual void executeScore() = 0;

        virtual void quit() = 0;

        virtual bool triggerMenu();

        virtual bool triggerIntroduction();

        virtual bool triggerGame();

        virtual bool triggerScore();

        virtual bool triggerQuit();


    private:

        void setStateStart();

        State estado;
};

} // namespace GAT
#endif
