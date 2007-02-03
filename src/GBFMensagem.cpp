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

#include "GBFMensagem.h"

//* Destrutor 
GBFMensagem::~GBFMensagem(){

}

//* Construtor 
GBFMensagem::GBFMensagem(){
   
	tempoEspera.setTempoOriginal(1);
	tempoEspera.setUnidade(TEMPO_MEIO);
    tempoEspera.setIniciar();    
    
    msgInicial();
}

void GBFMensagem::msgIntroducao() {

     eGBFMensagemEstado=GBF_MENSAGEM__ACAO__INTRODUCAO;
}

void GBFMensagem::msgTelaIndroducao() {

     eGBFMensagemEstado=GBF_MENSAGEM__TELA__INTRODUCAO;    
}

void GBFMensagem::msgMenu() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__MENU;
    }
}

void GBFMensagem::msgTelaMenu() {

     eGBFMensagemEstado=GBF_MENSAGEM__TELA__MENU;    
}

void GBFMensagem::msgSobre() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__SOBRE;
    }
}

void GBFMensagem::msgTelaSobre() {

     eGBFMensagemEstado=GBF_MENSAGEM__TELA__SOBRE;    
}

void GBFMensagem::msgAjuda() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__AJUDA;
    }
}

void GBFMensagem::msgTelaAjuda() {

     eGBFMensagemEstado=GBF_MENSAGEM__TELA__AJUDA;    
}

void GBFMensagem::msgCredito() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__CREDITO;
    }
}

void GBFMensagem::msgTelaCredito() {

     eGBFMensagemEstado=GBF_MENSAGEM__TELA__CREDITO;    
}

void GBFMensagem::msgTopRecorde() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__TOP_RECORDE;
    }
}

void GBFMensagem::msgTelaTopRecorde() {

    eGBFMensagemEstado=GBF_MENSAGEM__TELA__TOP_RECORDE;   
}

void GBFMensagem::msgTopRecordeNovo() {

    eGBFMensagemEstado=GBF_MENSAGEM__ACAO__TOP_RECORDE_NOVO;    
}

void GBFMensagem::msgTelaTopRecordeNovo() {

    eGBFMensagemEstado=GBF_MENSAGEM__TELA__TOP_RECORDE_NOVO;   
}

void GBFMensagem::msgTopRecordeNovoSalvar() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__TOP_RECORDE_SALVAR;
    }
}

void GBFMensagem::msgConfigurar() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__CONFIGURAR;
    }
}

void GBFMensagem::msgSair() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__SAIR;
    }
}

void GBFMensagem::msgTelaSair() {

    eGBFMensagemEstado=GBF_MENSAGEM__TELA__SAIR;    
}

void GBFMensagem::msgJogoNovo() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__JOGO_NOVO;
    }
}

void GBFMensagem::msgJogoExecutando() {

    if (isTempoEspera()){
        eGBFMensagemEstado=GBF_MENSAGEM__ACAO__JOGO_EXECUTANDO;
    }
}

bool GBFMensagem::isTempoEspera() {

    bool terminou = tempoEspera.isTerminou();
    
    if (terminou){
        tempoEspera.setResetar();
        tempoEspera.setIniciar();
    }
    
    return terminou;
}

EnumGBFMensagemEstado GBFMensagem::processarMensagem() {

    tempoEspera.processar();

    return eGBFMensagemEstado;
}

//
//Mensagens Implementação, algumas tem controles internos
////////////////

void GBFMensagem::msgInicial() {

    eGBFMensagemEstado=GBF_MENSAGEM__ACAO__INICIAL;
}

