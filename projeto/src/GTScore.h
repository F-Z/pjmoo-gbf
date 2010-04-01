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
#ifndef _GTSCORE_H
#define _GTSCORE_H

#include "GTTime.h"

namespace GAT {

enum StateScore {
    GAT_ET_INICIO = 0,
    GAT_ET_NOVO = 10,
    GAT_ET_SALVAR = 20,
    GAT_ET_EXIBIR = 30
};

class GTScore : public GTTime
{
    public:
        //Construtor
        GTScore();

        //Destrutor
        virtual ~GTScore();

        StateScore processarEstadoTopGaleria();


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

    private:
        StateScore estado;


};

} // namespace GAT
#endif
