#ifndef _GBFAPLICACAO_H
#define _GBFAPLICACAO_H

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
#include "GBFTela.h"
#include "GBFAcao.h"
#include "GBF.h"
#include "TimerSystemCronometroCrescente.h"
#include "TopSystemGaleria.h"

class GBFAplicacao : public GBFMensagem, public GBFTela, public GBFAcao {
  protected:
    GBF * frameworkGBF;

    TimerSystemCronometroCrescente tempoInativo;

    TopSystemGaleria * tsGaleria;


  private:
    bool fullscreen;

    bool looping;


  public:
    virtual ~GBFAplicacao();

    GBFAplicacao(int argc, char * argv[]);

    bool isFullScreen();

    void executar();


  protected:
    virtual void interpretadorGlobal();


  private:
    void escutar();

    //novos
    void acaoIntroducao();

    void acaoMenu();

    void acaoSobre();

    void acaoAjuda();

    void acaoCredito();

    void acaoTopRecorde();

    void acaoTopRecordeNovo();

    void acaoTopRecordeNovoSalvar();

    void acaoSair();

};
#endif
