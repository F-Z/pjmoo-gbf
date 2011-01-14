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
#ifndef _WRITEMANAGER_H
#define _WRITEMANAGER_H

#include <string>

#include "Language.h"
#include "FontBitmap.h"
#include <map>

#include "BaseManager.h"

namespace GBF {

namespace Kernel {

namespace Write {

/**
 * Classe para gerenciamento do sistema de fontes (letras).
 * Gerenciar o uso de fontes, facilitando o carregamento e acesso a escrita
 */
class WriteManager : public GBF::BaseManager
{
    public:

        /** Constante para representar a fonte padrão do GBF */
        static const std::string defaultFont;

        Language * language;

        /** Destrutor */
        virtual ~WriteManager();

        /** Retorna uma fonte para manipulação direta
         Obs.: Ideal para casos em que se deseja manipulações avançadas */
        FontBitmap * getFont(std::string name);

        /** Pega uma Referência para a instância de WriteManager */
        static WriteManager * getInstance();

        /** Carrega e adiciona uma fonte (FontBitmap) */
        void loadFromFile(std::string name, std::string fileName);

        /** Escreve um texto na tela usando a fonte padrão (defaultFont) */
        void write(int x, int y, const char * text, ...);

        /** Escreve um texto na tela */
        void write(std::string font, int x, int y, const char * text, ...);

        /** Escreve um texto na tela usando recursos de Localização (Tradução) */
        void writeKeyText(const std::string font, int x, int y, std::string keyText, ...);

        /** Escreve na tela usando recursos de Localização (Tradução), baseado na junção de dois segmentos de localização */
        void escreverLocalizadoSubChave(const std::string font, int x, int y, const std::string keyText, const std::string subKeyText);

        /** Remove uma fonte (WriteSystemFontBitmap) */
        void remove(std::string name);

        /** Retorna em Pixel o tamanho total da linha */
        int getLineWidth(const std::string font, const std::string key);


    protected:

        std::map<std::string, FontBitmap*> objetomap;

        static WriteManager * instance;

    private:

        /** Construtor */
        WriteManager();
};

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF

#endif
