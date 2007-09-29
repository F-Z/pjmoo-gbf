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

#include "SoundSystemStatus.h"

//Destrutor
SoundSystemStatus::~SoundSystemStatus() 
{

}
//Verifica se sistema de som está funcionando
bool SoundSystemStatus::isAtivo() 
{

    return ativo;
}
//Verifica se o som está desligado
bool SoundSystemStatus::isMute() 
{
    return mute;
}
//Configurar se o sistema de som está funcionando
void SoundSystemStatus::setAtivo(bool ativo) 
{
    this->ativo=ativo;

    if (!ativo){
        mute=true;
    }
}
//Configura o sistema de som
void SoundSystemStatus::setMute(bool mute) 
{
    if (ativo){
        this->mute=mute;
    }
}
//Construtor
SoundSystemStatus::SoundSystemStatus() 
{
    ativo = false;
    mute  = false;
}
