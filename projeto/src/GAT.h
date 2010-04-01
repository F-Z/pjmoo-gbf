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
#ifndef _GAT_H
#define _GAT_H

#include "GTState.h"
#include "GTScore.h"
#include "GTMenu.h"
#include "GTGame.h"
#include "GBFramework.h"
#include "UIWindowRecord.h"
#include "ScoreManager.h"
#include "UIMenuAbstract.h"
#include "TimerProgressive.h"

namespace GAT {

/**
 * GAT - GBF Application Template
 */
class GAT : public GTState, public GTScore, public GTMenu, public GTGame
{
    public:
        /** Construtor */
        GAT(int argc, char * argv[]);

        /** Destrutor */
        virtual ~GAT();

        bool isFullScreen();

        void executar();

        virtual void interpretadorGlobal();

    protected:

        /** Apresentação do jogo */
        virtual void apresentacao();

        /** Tela para entrada de Novo Recorde */
        virtual void topGaleriaNovo();

        /** Tela para Salvar Novo Recorde */
        virtual void topGaleriaSalvar();

        /** Tela para Exibição dos Recordes */
        virtual void topGaleriaExibir();

        bool setJogo();

        bool setMenu();

        bool setTopGaleria();

        GBF::GBFramework * frameworkGBF;

        UserInterface::Window::UIWindowRecord * uiRecordeNovo;

        Score::ScoreManager * recordeManager;

        UserInterface::Menu::UIMenuAbstract * uiMenuPrincipal;

        GBF::Kernel::Timer::TimerProgressive tempoInativo;

    private:

        bool looping;

        bool fullscreen;

        void escutar();

        void menu();

        void jogo();

        void topGaleria();

        void sair();

};

} // namespace GAT

#endif
