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

#include "GAT.h"

//Construtor
GAT::GAT(int argc, char * argv[]) 
{
    fullscreen = true;
    looping    = true;

    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "--window") == 0 ){
            fullscreen=false;
        }
    }

    frameworkGBF    = new GBF();   
    tsGaleria       = new TopSystemGaleria();
    uiRecordeNovo   = NULL;
    uiMenuPrincipal = NULL;

    tempoInativo.setTempoOriginal(0);
    tempoInativo.setUnidade(TEMPO_SEGUNDO);
    tempoInativo.setResetar();

    frameworkGBF->setPath(argv[0]);
}
//Destrutor
GAT::~GAT() 
{
    if (uiRecordeNovo){
        delete(uiRecordeNovo);
    }
    if (tsGaleria){
        delete(tsGaleria);
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
void GAT::executar() 
{
    //Inicialização de classes extras 
    TopSystemGaleria::setPathBase(frameworkGBF->getPath());

    while(looping) {
        escutar();
        interpretadorGlobal();
    }
}
void GAT::interpretadorGlobal() 
{
    if (frameworkGBF->inputSystem->teclado->isKey(SDLK_ESCAPE)){
        setMenu();
    }
//TODO: Criar mecanismo para aumetar/diminuir ciclo do FPS  
}
void GAT::escutar() 
{
    executarTempo();

    switch(processarEstadoGeral()){
        case GAT_EG_JOGO:
                jogo();
            break;
        case GAT_EG_MENU:
                menu();
            break;
        case GAT_EG_APRESENTACAO:
                apresentacao();
            break;
        case GAT_EG_TOPGALERIA:
                topGaleria();
            break;
        case GAT_EG_SAIR:
                sair();
            break;
        case GAT_EG_INICIO:
        default:
                inicializarRecursos();
                setApresentacao();
            break;
    }

    frameworkGBF->atualizar();
}
//Apresentação do jogo
void GAT::apresentacao() 
{
    setMenu();
}
//Tela para entrada de Novo Recorde
void GAT::topGaleriaNovo() 
{
    setMenu();
}
//Tela para Salvar Novo Recorde
void GAT::topGaleriaSalvar() 
{
    setMenu();
}
//Tela para Exibição dos Recordes
void GAT::topGaleriaExibir() 
{
    setMenu();
}
bool GAT::setJogo() 
{
    bool mudou = false;

    if (GATMaquinaEstadoGeral::setJogo()){
        setJogoInicio();
        mudou=true;
    }

    return mudou;
}
bool GAT::setMenu() 
{
    bool mudou = false;

    if (GATMaquinaEstadoGeral::setMenu()){
        setMenuInicio();
        mudou=true;
    }

    return mudou;
}
bool GAT::setTopGaleria() 
{
    bool mudou = false;
    
    if (GATMaquinaEstadoGeral::setTopGaleria()){
		setTopGaleriaInicio();
		mudou=true;
    }

    return mudou;
}
void GAT::menu() 
{
    switch(processarEstadoMenu()){
        case GAT_EM_PRINCIPAL:
                menuPrincipal();
                tempoInativo.processar();
                if (tempoInativo.getTempo()>10){
                    tempoInativo.setResetar();
                    setApresentacao();
                }
            break;
        case GAT_EM_AJUDA:
                menuAjuda();
            break;
        case GAT_EM_CREDITO:
                menuCredito();
            break;
        case GAT_EM_SOBRE:
                menuSobre();
            break;
        case GAT_EM_CONFIGURACAO:
                menuConfiguracao();
            break;
        case GAT_EM_INICIO:
                setMenuPrincipal();
            break;
    }
}
void GAT::jogo() 
{
    loopJogo();
}
void GAT::topGaleria() 
{
    loopTopGaleria();
}
void GAT::sair() 
{
    looping=false;
}
