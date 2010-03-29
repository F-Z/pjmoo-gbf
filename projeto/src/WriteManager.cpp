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
#include "WriteManager.h"

namespace GBF {

namespace Kernel {

namespace Write {

/** Constante para representar a fonte padrão do GBF */
const std::string WriteManager::defaultFont = "default";

/** Destrutor */
WriteManager::~WriteManager()
{
//    UtilLog::subSistema("Removendo WriteSystemManager");
    std::map<std::string, FontBitmap*>::iterator it;

    for (it = objetomap.begin();it != objetomap.end(); it++){
        try {
            //UtilLog::tracer("Fonte=%s",((*it).first).c_str());
        } catch (...){
            //UtilLog::tracer("Fonte=Desconhecido(a)");
        }

        delete((*it).second);

        (*it).second = NULL;
        // UtilLog::comentario("[Ok]");
    }

    objetomap.clear();
}

/** Retorna uma fonte para manipulação direta
Obs.: Ideal para casos em que se deseja manipulações avançadas */
FontBitmap * WriteManager::getFont(std::string name)
{
    if (objetomap.find(name) != objetomap.end()){
        return objetomap[name];
    } else {
        // UtilLog::tracer("WriteSystemManager::getFonte(%s) - [* ERRO *]",nome.c_str());
        return objetomap[WriteManager::defaultFont];
    }
}

/** Pega uma Referência para a instância de WriteManager */
WriteManager * WriteManager::getInstance()
{
    if (instance == NULL){
        instance = new WriteManager();
    }

    return instance;
}

/** Carrega e adiciona uma fonte (WriteSystemBitmap) */
void WriteManager::loadFromFile(std::string name, std::string fileName)
{
    std::string fullpath = Kernel::Util::Path::getPath() + fileName;

    FontBitmap *f = new FontBitmap();

    std::cout << "\tWriteManager: " << name << "=" << fullpath << std::endl;

    if (f->loadFromFile(fullpath)){
        objetomap[name] = f;
    }
}

/** Escreve um texto na tela usando a fonte padrão (defaultFont) */
void WriteManager::write(int x, int y, const char * text, ...)
{
    char texto_aux[256];
    va_list ap;

    va_start(ap, text);
    vsprintf(texto_aux, text, ap);
    va_end(ap);

    getFont(defaultFont)->write(texto_aux, x, y);
}

/** Escreve um texto na tela */
void WriteManager::write(std::string font, int x, int y, const char * text, ...)
{
    char texto_aux[256];
    va_list ap;

    va_start(ap, text);
    vsprintf(texto_aux, text, ap);
    va_end(ap);

    getFont(font)->write(texto_aux, x, y);
}

/** Escreve um texto na tela usando recursos de Localização (Tradução) */
void WriteManager::writeKeyText(const std::string font, int x, int y, std::string keyText, ...)
{
    char textoFormatado[256];
    va_list ap;

    va_start(ap, keyText);
    vsprintf(textoFormatado, language->getText(keyText).c_str(), ap);
    va_end(ap);

    write(font, x, y, textoFormatado);
}

/** Escreve na tela usando recursos de Localização (Tradução), baseado na junção de dois segmentos de localização
    @deprecated
 */
void WriteManager::escreverLocalizadoSubChave(const std::string font, int x, int y, const std::string keyText, const std::string subKeyText)
{
    char textoFormatado[256];

    sprintf(textoFormatado, language->getText(keyText).c_str(), language->getText(subKeyText).c_str());
    write(font, x, y, textoFormatado);
}

/** Remove uma fonte (WriteSystemFontBitmap) */
void WriteManager::remove(std::string name)
{
    if (objetomap.find(name) != objetomap.end()){
        delete(objetomap[name]);
        objetomap[name] = NULL;
        objetomap.erase(name);
    }
}

/** Retorna em Pixel o tamanho total da linha */
int WriteManager::getLineWidth(const std::string font, const std::string key)
{
    if (objetomap.find(font) != objetomap.end()){
        return objetomap[font]->getLineWidth(language->getText(key).c_str());
    } else {
        return 0;
    }
}

/** Construtor */
WriteManager::WriteManager()
{
//    UtilLog::subSistema("Instanciando WriteSystemManager");
    language =  Language::getInstance();
}

WriteManager * WriteManager::instance;


} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
