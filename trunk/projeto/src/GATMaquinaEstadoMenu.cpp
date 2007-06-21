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

#include "GATMaquinaEstadoMenu.h"

//Construtor
GATMaquinaEstadoMenu::GATMaquinaEstadoMenu() 
{
    setMenuInicio();
}
//Destrutor
GATMaquinaEstadoMenu::~GATMaquinaEstadoMenu() 
{
}
GATEstadoMenu GATMaquinaEstadoMenu::processarEstadoMenu() 
{
    return estado;
}
void GATMaquinaEstadoMenu::setMenuPrincipal() 
{
    if ((estado==GAT_EM_INICIO)
        || ((estado!=GAT_EM_PRINCIPAL)
        && (isTempoEspera()))){
            estado=GAT_EM_PRINCIPAL;
            gatilhoMenuPrincipal();
            reiniciarTempo();
    }
}
void GATMaquinaEstadoMenu::setMenuAjuda() 
{
    if ((estado!=GAT_EM_AJUDA)&&(isTempoEspera())){
        estado=GAT_EM_AJUDA;
        reiniciarTempo();
    }
}
void GATMaquinaEstadoMenu::setMenuCredito() 
{
    if ((estado!=GAT_EM_CREDITO)&&(isTempoEspera())){
        estado=GAT_EM_CREDITO;
        reiniciarTempo();        
    }
}
void GATMaquinaEstadoMenu::setMenuSobre() 
{
    if ((estado!=GAT_EM_SOBRE)&&(isTempoEspera())){
        estado=GAT_EM_SOBRE;
        reiniciarTempo();
    }
}
void GATMaquinaEstadoMenu::setMenuConfiguracao() 
{
    if ((estado!=GAT_EM_CONFIGURACAO)&&(isTempoEspera())){
        estado=GAT_EM_CONFIGURACAO;
        gatilhoMenuConfiguracao();
        reiniciarTempo();
    }
}
void GATMaquinaEstadoMenu::menuConfiguracao() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoMenu::gatilhoMenuPrincipal() 
{
//opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoMenu::gatilhoMenuConfiguracao() 
{
    //opicional implementação de acordo com a necessidade
}
void GATMaquinaEstadoMenu::setMenuInicio() 
{
    estado=GAT_EM_INICIO;
}
