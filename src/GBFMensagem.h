#ifndef _GBFMENSAGEM_H
#define _GBFMENSAGEM_H

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

#include "TimerSystemCronometroDecrescente.h"

enum EnumGBFMensagemEstado {
  GBF_MENSAGEM__ACAO__INICIAL =0,
  GBF_MENSAGEM__TELA__INTRODUCAO =1,
  GBF_MENSAGEM__ACAO__INTRODUCAO =10,
  GBF_MENSAGEM__TELA__MENU =2,
  GBF_MENSAGEM__ACAO__MENU =20,
  GBF_MENSAGEM__TELA__SOBRE =3,
  GBF_MENSAGEM__ACAO__SOBRE =30,
  GBF_MENSAGEM__TELA__AJUDA =4,
  GBF_MENSAGEM__ACAO__AJUDA =40,
  GBF_MENSAGEM__TELA__CREDITO =5,
  GBF_MENSAGEM__ACAO__CREDITO =50,
  GBF_MENSAGEM__TELA__TOP_RECORDE =6,
  GBF_MENSAGEM__ACAO__TOP_RECORDE =60,
  GBF_MENSAGEM__TELA__TOP_RECORDE_NOVO =61,
  GBF_MENSAGEM__ACAO__TOP_RECORDE_NOVO =62,
  GBF_MENSAGEM__ACAO__TOP_RECORDE_SALVAR =63,
  GBF_MENSAGEM__TELA__CONFIGURAR =7,
  GBF_MENSAGEM__ACAO__CONFIGURAR =70,
  GBF_MENSAGEM__TELA__SAIR =8,
  GBF_MENSAGEM__ACAO__SAIR =80,
  GBF_MENSAGEM__ACAO__JOGO_EXECUTANDO =9,
  GBF_MENSAGEM__ACAO__JOGO_NOVO =91

};
class GBFMensagem {
  public:
    //* Destrutor 
    virtual ~GBFMensagem();

    //* Construtor 
    GBFMensagem();


  protected:
    void msgIntroducao();

    void msgTelaIndroducao();

    void msgMenu();

    void msgTelaMenu();

    void msgSobre();

    void msgTelaSobre();

    void msgAjuda();

    void msgTelaAjuda();

    void msgCredito();

    void msgTelaCredito();

    void msgTopRecorde();

    void msgTelaTopRecorde();

    void msgTopRecordeNovo();

    void msgTelaTopRecordeNovo();

    void msgTopRecordeNovoSalvar();

    void msgConfigurar();

    void msgSair();

    void msgTelaSair();

    void msgJogoNovo();

    void msgJogoExecutando();

    bool isTempoEspera();

    EnumGBFMensagemEstado processarMensagem();


  private:
    void msgInicial();

    TimerSystemCronometroDecrescente tempoEspera;

    EnumGBFMensagemEstado eGBFMensagemEstado;

};
#endif
