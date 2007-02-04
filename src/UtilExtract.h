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

#ifndef _UTILEXTRACT_H
#define _UTILEXTRACT_H

#include <string>


//Descrição: 
//    Classe utilitária para extração de informações relativas ao path de arquivos
//Motivação:
//    Descobrir caminhos de pastas
//    Extrair o nome de aplicativos
class UtilExtract {
  public:
    //Extrai o caminho do diretório base 
    static std::string extractPath(char * fullPath);

    //Extrai o nome do aplicativo
    static std::string extractApplication(char * fullPath);

};
#endif
