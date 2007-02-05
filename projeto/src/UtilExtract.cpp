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

#include "UtilExtract.h"

//Extrai o caminho do diretório base 
std::string UtilExtract::extractPath(char * fullPath)
{
    int i=0;
    std::string path = fullPath;
    std::string pathBase  ="";

    for (i=path.length();i>=0;i--){
        if ((path[i]=='\\')||(path[i]=='/')) {
            i++;
            break;
        }
    }
    if (i>=0){
        pathBase=path.substr(0,i);
    }

    return pathBase;
}

//Extrai o nome do aplicativo
std::string UtilExtract::extractApplication(char * fullPath)
{
    int i=0;
    std::string path=fullPath;
    std::string nomeAplicacao="";

    for (i=path.length();i>=0;i--){
        if ((path[i]=='\\')||(path[i]=='/')) {
            break;
        }
    }

    if (i>=0){
        nomeAplicacao = path.substr(i,path.length());
    }

    return nomeAplicacao;
}

