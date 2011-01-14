/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _LANGUAGE_H
#define _LANGUAGE_H

#ifndef __gnu_linux__
#include <windows.h>
#endif

#include <cstdlib>
#include <fstream>

#include <map>

#include <string>

#include "Path.h"
#include <iostream>


namespace GBF {

namespace Kernel {

namespace Write {

/**
 * Classe para carregar textos.
 * Possibilitar que os textos usados no jogo possam ser carregados de arquivos externos.
 */

class Language
{

    public:
        /** Destrutor */
        ~Language();

        static Language * getInstance();

        /** Configura um idioma. O idioma é configurado de acordo com a lista de idiomas suportado */
        bool setLanguage(const std::string & codigo);

        std::string getLanguage();

        /** Seleciona o idioma automaticamente de acordo com o ambiente */
        void autodetect();

        bool refresh();

        void setFileName(const std::string & fileName);

        int size();

        std::string getText(const std::string & key);

        /** Retorna se existe a chave de texto */
        bool isKey(const std::string & key);


    protected:
        void parser(char * info);

        /** Carrega o mapeamento de idiomas e os arquivos de texto */
        void load();

        void parserLanguage(char * info);

        void clear();

        /** Lista com os códigos e textos correspondentes */
        std::map<std::string, std::string> mapaTexto;

        /** Lista com os idiomas suportados */
        std::map<std::string, std::string> idiomaSuportado;

        /** Prefixo do idioma selecionado */
        std::string prefix;

        static Language * instance;

    private:
        /** Construtor */
        Language();

        /** arquivo de localização a ser carregado */
        std::string fileName;

};

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF

#endif
