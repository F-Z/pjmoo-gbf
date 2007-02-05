////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
////    
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////    
////    David Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "GBFAplicacao.h"

GBFAplicacao::~GBFAplicacao(){

    if (uiRecordeNovo){
        delete (uiRecordeNovo);
    }
    if (frameworkGBF){
        delete(frameworkGBF);
    }       
    if (tsGaleria){
        delete(tsGaleria);
    }
}

GBFAplicacao::GBFAplicacao(int argc, char * argv[]) 
{
    fullscreen = true;
    looping    = true;
    
    for (int i=1; i<argc; i++){
        if (strcmp(argv[i], "--window") == 0 ){
            fullscreen=false;
        }
    }
    
    frameworkGBF   = new GBF();   
    tsGaleria      = new TopSystemGaleria();

	tempoInativo.setTempoOriginal(0);
	tempoInativo.setUnidade(TEMPO_SEGUNDO);
    tempoInativo.setIniciar();
    
    frameworkGBF->setPath(argv[0]);
}
bool GBFAplicacao::isFullScreen() 
{
	return fullscreen;
}
void GBFAplicacao::executar() 
{
    //Inicialização de classes extras 
    TopSystemGaleria::setPathBase(frameworkGBF->getPath());
    
    while(looping) {
        escutar();
        interpretadorGlobal();
    }
}
void GBFAplicacao::interpretadorGlobal() {

    if (frameworkGBF->inputSystem->teclado->isKey(SDLK_ESCAPE)){
        msgMenu();
    }
//TODO: Criar mecanismo para aumetar/diminuir ciclo do FPS  
}

void GBFAplicacao::escutar() {

    switch(processarMensagem()){
//
// ACOES - PARTE 1 - CRITICAS 
////////////////
        case GBF_MENSAGEM__ACAO__JOGO_EXECUTANDO:
                acaoJogoExecutando(); 
            break;
//
// TELAS 
////////////////
        case GBF_MENSAGEM__TELA__INTRODUCAO: 
                telaIntroducao();
            break;
        case GBF_MENSAGEM__TELA__MENU: 
                telaMenu();
                tempoInativo.processar();
                if (tempoInativo.getTempo()>10){
                    tempoInativo.setResetar();
                    tempoInativo.setIniciar();
                    msgIntroducao();
                }
            break;   
        case GBF_MENSAGEM__TELA__SOBRE: 
                telaSobre();
            break;
        case GBF_MENSAGEM__TELA__AJUDA: 
                telaAjuda();
            break;
        case GBF_MENSAGEM__TELA__CONFIGURAR: 
                telaConfigurar();
            break;
        case GBF_MENSAGEM__TELA__CREDITO: 
                telaCredito();
            break;
        case GBF_MENSAGEM__TELA__TOP_RECORDE: 
                telaTopRecorde();
            break;
        case GBF_MENSAGEM__TELA__TOP_RECORDE_NOVO:
                telaTopRecordeNovo();
            break;           
        case GBF_MENSAGEM__TELA__SAIR:
                telaSair();
            break;            

//
// ACOES - PARTE 2 - USADAS APENAS QUANDO INVOCADAS
////////////////
        case GBF_MENSAGEM__ACAO__INTRODUCAO:
                acaoIntroducao();
            break;
        case GBF_MENSAGEM__ACAO__MENU:
                acaoMenu();
            break;
        case GBF_MENSAGEM__ACAO__SOBRE:
                acaoSobre();
            break;
        case GBF_MENSAGEM__ACAO__AJUDA:
                acaoAjuda();
            break;
        case GBF_MENSAGEM__ACAO__CREDITO:
                acaoCredito();
            break;
        case GBF_MENSAGEM__ACAO__TOP_RECORDE:
                acaoTopRecorde();
            break;
        case GBF_MENSAGEM__ACAO__TOP_RECORDE_NOVO:
                acaoTopRecordeNovo();
            break;
        case GBF_MENSAGEM__ACAO__TOP_RECORDE_SALVAR:
                acaoTopRecordeNovoSalvar();
            break;            
        case GBF_MENSAGEM__ACAO__SAIR: 
                acaoSair();
            break;                
        case GBF_MENSAGEM__ACAO__JOGO_NOVO: 
                acaoJogoNovo();
            break;   
        case GBF_MENSAGEM__ACAO__INICIAL:
                // carrega arquivos de recursos
                acaoInicial(); 
                // muda estado para exibir tela de introducao
                msgIntroducao();
            break;
        default:
                printf("Erro sem msg");
            break;            
    }
    frameworkGBF->atualizar();
}

//novos
void GBFAplicacao::acaoIntroducao() {

    msgTelaIndroducao();
}

void GBFAplicacao::acaoMenu() {

    msgTelaMenu();
}

void GBFAplicacao::acaoSobre() {

    msgTelaSobre();
}

void GBFAplicacao::acaoAjuda() {

    msgTelaAjuda();
}

void GBFAplicacao::acaoCredito() {

    msgTelaCredito();
}

void GBFAplicacao::acaoTopRecorde() {

    tsGaleria->carregar();
    msgTelaTopRecorde();
}

void GBFAplicacao::acaoTopRecordeNovo() {

    msgTelaTopRecordeNovo();
}

void GBFAplicacao::acaoTopRecordeNovoSalvar() {

    if ((tsGaleria)&&(uiRecordeNovo)){
         if (tsGaleria->adicionar(uiRecordeNovo->getRecorde())){
            tsGaleria->salvar();
         }
    }
    msgTopRecorde();
}

void GBFAplicacao::acaoSair() 
{
    msgTelaSair();
	looping=false;
}
