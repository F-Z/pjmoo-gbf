#ifndef _GBFACAO_H
#define _GBFACAO_H

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

class GBFAcao {
  public:
    virtual ~GBFAcao();

    GBFAcao();


  protected:
    //* Novo Jogo 
    virtual void acaoJogoNovo() = 0;

    //* Jogo em Execução 
    virtual void acaoJogoExecutando() = 0;

    //* Carregar arquivos de recursos 
    virtual void acaoInicial() = 0;

};
#endif
