////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#ifndef _GTTOPGALERIA_H
#define _GTTOPGALERIA_H

#include "GTMaquinaEstado.h"

namespace GAT {

enum EstadoTopGaleria {
  GAT_ET_INICIO=0,
  GAT_ET_NOVO=10,
  GAT_ET_SALVAR=20,
  GAT_ET_EXIBIR=30
};
class GTTopGaleria : public GTMaquinaEstado
{
  private:
    EstadoTopGaleria estado;


  public:
    //Construtor
    GTTopGaleria();

    //Destrutor
    virtual ~GTTopGaleria();

    EstadoTopGaleria processarEstadoTopGaleria();


  protected:
    void loopTopGaleria();

    void setTopGaleriaNovo();

    void setTopGaleriaSalvar();

    void setTopGaleriaExibir();

    virtual void topGaleriaNovo() = 0;

    virtual void topGaleriaSalvar() = 0;

    virtual void topGaleriaExibir() = 0;

    virtual bool gatilhoTopGaleriaNovo();

    virtual bool gatilhoTopGaleriaSalvar();

    virtual bool gatilhoTopGaleriaExibir();

    void setTopGaleriaInicio();


};

} // namespace GAT
#endif
