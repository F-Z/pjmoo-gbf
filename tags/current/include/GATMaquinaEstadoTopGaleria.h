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

#ifndef _GATMAQUINAESTADOTOPGALERIA_H
#define _GATMAQUINAESTADOTOPGALERIA_H

#include "GATMaquinaEstado.h"

enum GATEstadoTopGaleria {
  GAT_ET_INICIO =0,
  GAT_ET_NOVO =10,
  GAT_ET_SALVAR =20,
  GAT_ET_EXIBIR =30
};
class GATMaquinaEstadoTopGaleria : public GATMaquinaEstado
{
  private:
    GATEstadoTopGaleria estado;


  public:
    //Construtor
    GATMaquinaEstadoTopGaleria();

    //Destrutor
    virtual ~GATMaquinaEstadoTopGaleria();

    GATEstadoTopGaleria processarEstadoTopGaleria();


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
#endif
