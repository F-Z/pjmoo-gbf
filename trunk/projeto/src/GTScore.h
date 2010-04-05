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
#ifndef _GTSCORE_H
#define _GTSCORE_H

#include "GTTime.h"

namespace GAT {

enum StateScore
{
    SCORE_VIEW =  0,
    SCORE_NEW  = 10,
    SCORE_SAVE = 20
};

class GTScore : public GTTime
{
    public:

        /** Construtor */
        GTScore();

        /** Destrutor */
        virtual ~GTScore();

        /** Retorna o Estado do Score */
        StateScore getScoreState();

    protected:

        void loopScore();

        void setScoreNew();

        void setScoreSave();

        void setScoreView();

        /** Tela para Entrada do Novo Recorde */
        virtual void screenNewScore() = 0;

        /** Ação para Salvar o Novo Recorde */
        virtual void actionSaveScore() = 0;

        /** Tela para Visualização dos Recordes */
        virtual void screenViewScore() = 0;

        virtual bool triggerNewScore();

        virtual bool triggerSaveScore();

        virtual bool triggerViewScore();

    private:

        StateScore state;
};

} // namespace GAT
#endif
