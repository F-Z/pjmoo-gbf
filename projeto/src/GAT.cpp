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
#include "GAT.h"

namespace GAT {

/** Construtor */
GAT::GAT(int argc, char * argv[])
{
    fullscreen = true;
    looping    = true;

    for (int i = 1; i < argc; i++){
        if (strcmp(argv[i], "--window") == 0){
            fullscreen = false;
        }
    }

    frameworkGBF    = new GBF::GBFramework();

    recordeManager  = new Score::ScoreManager();
    uiRecordeNovo   = NULL;
    uiMenuPrincipal = NULL;

    tempoInativo.setInitialTime(0);
    tempoInativo.setUnit(GBF::Kernel::Timer::TIME_SECOND_ONE);
    tempoInativo.setReset();

    frameworkGBF->setPath(argv[0]);
}

/** Destrutor */
GAT::~GAT()
{
    if (uiRecordeNovo){
        delete(uiRecordeNovo);
    }

    if (recordeManager){
        delete(recordeManager);
    }

    if (uiMenuPrincipal){
        delete(uiMenuPrincipal);
    }

    if (frameworkGBF){
        delete(frameworkGBF);
    }
}

bool GAT::isFullScreen()
{
    return fullscreen;
}

void GAT::execute()
{
    //Inicialização de classes extras
    Score::ScoreManager::setPathBase(frameworkGBF->getPath());

    while (looping) {
        loopGAT();
        hookGlobal();
    }
}

void GAT::hookGlobal()
{
    if ((frameworkGBF->inputSystemCore->inputSystem->keyboard->isKey(SDLK_ESCAPE)) &&
            (frameworkGBF->inputSystemCore->inputSystem->keyboard->isKey(SDLK_RETURN))){
        setMenu();
    }
}

void GAT::loopGAT()
{
    update();

    switch (processarEstadoGeral()){

        case STATE_GAME:
            executeGame();
            break;

        case STATE_MENU:
            executeMenu();
            break;

        case STATE_INTRODUCTION:
            executeIntroduction();
            break;

        case STATE_SCORE:
            executeScore();
            break;

        case STATE_QUIT:
            quit();
            break;

        case STATE_START:

        default:
            loadResources();
            setIntroduction();
            break;
    }

    frameworkGBF->update();
}

/** Tela para entrada de Novo Recorde */
void GAT::screenNewScore()
{
    setMenu();
}

/** Ação para Salvar o Novo Recorde */
void GAT::actionSaveScore()
{
    setMenu();
}

/** Tela para Visualização dos Recordes */
void GAT::screenViewScore()
{
    setMenu();
}

bool GAT::setGame()
{
    bool mudou = false;

    if (GTState::setGame()){
        setGameStart();
        mudou = true;
    }

    return mudou;
}

bool GAT::setMenu()
{
    bool mudou = false;

    if (GTState::setMenu()){
        setMenu();
        mudou = true;
    }

    return mudou;
}

bool GAT::setScore()
{
    bool mudou = false;

    if (GTState::setScore()){
        setScoreView();
        mudou = true;
    }

    return mudou;
}

void GAT::executeMenu()
{
    switch (processarEstadoMenu()){

        case MENU_MAIN:
            screenMain();
            tempoInativo.update();

            if (tempoInativo.getTime() > 10){
                tempoInativo.setReset();
                setIntroduction();
            }

            break;

        case MENU_HELP:
            screenHelp();
            break;

        case MENU_CREDIT:
            screenCredit();
            break;

        case MENU_ABOUT:
            screenAbout();
            break;

        case MENU_CONFIG:
            screenConfig();
            break;

        case MENU_START:
            setMenu();
            break;
    }
}

void GAT::executeIntroduction()
{
    setMenu();
}

void GAT::executeGame()
{
    loopGame();
}

void GAT::executeScore()
{
    loopScore();
}

void GAT::quit()
{
    looping = false;
}

} // namespace GAT
