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
#include "GTMenu.h"

namespace GAT {

//Construtor
GTMenu::GTMenu()
{
    setMenuInicio();
}

//Destrutor
GTMenu::~GTMenu()
{
}

StateMenu GTMenu::processarEstadoMenu()
{
    return estado;
}

void GTMenu::setMenuPrincipal()
{
    if ((estado == GAT_EM_INICIO)
            || ((estado != GAT_EM_PRINCIPAL)
                && (isTempoEspera()))){
        estado = GAT_EM_PRINCIPAL;
        gatilhoMenuPrincipal();
        reiniciarTempo();
    }
}

void GTMenu::setMenuAjuda()
{
    if ((estado != GAT_EM_AJUDA) && (isTempoEspera())){
        estado = GAT_EM_AJUDA;
        reiniciarTempo();
    }
}

void GTMenu::setMenuCredito()
{
    if ((estado != GAT_EM_CREDITO) && (isTempoEspera())){
        estado = GAT_EM_CREDITO;
        reiniciarTempo();
    }
}

void GTMenu::setMenuSobre()
{
    if ((estado != GAT_EM_SOBRE) && (isTempoEspera())){
        estado = GAT_EM_SOBRE;
        reiniciarTempo();
    }
}

void GTMenu::setMenuConfiguracao()
{
    if ((estado != GAT_EM_CONFIGURACAO) && (isTempoEspera())){
        estado = GAT_EM_CONFIGURACAO;
        gatilhoMenuConfiguracao();
        reiniciarTempo();
    }
}

void GTMenu::menuConfiguracao()
{
    //opcional implementação de acordo com a necessidade
}

void GTMenu::gatilhoMenuPrincipal()
{
    //opcional implementação de acordo com a necessidade
}

void GTMenu::gatilhoMenuConfiguracao()
{
    //opcional implementação de acordo com a necessidade
}

void GTMenu::setMenuInicio()
{
    estado = GAT_EM_INICIO;
}

} // namespace GAT
