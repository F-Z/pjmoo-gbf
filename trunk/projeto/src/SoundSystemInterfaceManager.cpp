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

#include "SoundSystemInterfaceManager.h"

//Construtor
SoundSystemInterfaceManager::SoundSystemInterfaceManager(SoundSystemStatus * status) 
{
    this->status=status;

    if (status->isAtivo()){
        //UtilLog::getInstance()->status("[Ok]");
    } else {
        //UtilLog::getInstance()->status("[Falhou]");
    }
}
//Destrutor
SoundSystemInterfaceManager::~SoundSystemInterfaceManager() 
{
    status = NULL;
}
//Informa PathBase para leitura de arquivos
void SoundSystemInterfaceManager::setPathBase(std::string path)
{
    pathBase=path;
}
std::string SoundSystemInterfaceManager::pathBase;

