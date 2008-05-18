////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2008 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://davidferreira-fz.blogspot.com
////////////////////////////////////////////////////////////////////////

#include "WriteManager.h"

namespace GBF {

namespace Kernel {

namespace Write {

//Constante para representar a fonte padrão do GBF
const std::string WriteManager::defaultFont="default";

//Destrutor
WriteManager::~WriteManager() 
{
//    UtilLog::subSistema("Removendo WriteSystemManager");
    std::map<std::string,FonteBitmap*>::iterator it;

    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
            //UtilLog::tracer("Fonte=%s",((*it).first).c_str());
        } catch(...){
            //UtilLog::tracer("Fonte=Desconhecido(a)");
        }
        delete((*it).second);
        (*it).second=NULL;
       // UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
//Retorna uma fonte para manipulação direta
//Obs.: Ideal para casos em que se deseja manipulações avançadas
FonteBitmap * WriteManager::getFonte(std::string nome) 
{
    if (objetomap.find(nome)!=objetomap.end()){
        return objetomap[nome];
    } else {
       // UtilLog::tracer("WriteSystemManager::getFonte(%s) - [* ERRO *]",nome.c_str());
        return objetomap[WriteManager::defaultFont];
    }
}
//Pega uma Instância de FonteManager
//Obs.: Esta classe é Singleton
WriteManager * WriteManager::getInstance()
{
    if (instance == NULL){
        instance = new WriteManager();
    }
    return instance;
}
//Carrega e adiciona uma fonte (WriteSystemBitmap)
void WriteManager::carregar(std::string nome, std::string arquivo) 
{
    FonteBitmap *f = new FonteBitmap();

   // UtilLog::tracer("FonteBitmap=%s Arquivo=%s",nome.c_str(),arquivo.c_str());
    if (f->carregarArquivo(arquivo)){
        objetomap[nome]=f;
        //UtilLog::comentario("[Ok]");
    } else {
        //UtilLog::comentario("[Falhou]");
    }
}
//Escreve um texto na tela
void WriteManager::escrever(std::string fonte, int x, int y, const char * texto, ...) 
{
    char texto_aux[256];
    va_list ap;

    va_start(ap, texto);
    vsprintf(texto_aux, texto, ap);
    va_end(ap);

    getFonte(fonte)->escrever(texto_aux,x,y);
}
//Escreve um texto na tela usando recursos de Localização (Tradução)
void WriteManager::escreverLocalizado(const std::string & fonte, int x, int y, std::string chave, ...) 
{
    char textoFormatado[256];
    va_list ap;

    va_start(ap, chave);
    vsprintf(textoFormatado, idioma->getTexto(chave).c_str(), ap);
    va_end(ap);

    escrever(fonte,x,y,textoFormatado);
}
//Escreve na tela usando recursos de Localização (Tradução), baseado na junção de dois segmentos de localização
void WriteManager::escreverLocalizadoSubChave(const std::string fonte, int x, int y, const std::string chave, const std::string subChave) 
{
    char textoFormatado[256];

    sprintf(textoFormatado, idioma->getTexto(chave).c_str(), idioma->getTexto(subChave).c_str());
    escrever(fonte,x,y,textoFormatado);
}
//Remove uma fonte (WriteSystemFontBitmap)
void WriteManager::apagar(std::string nome) 
{
    if (objetomap[nome]){
        delete (objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
//Retorna em Pixel o tamanho total da linha
int WriteManager::getLarguraLinha(const std::string fonte, const std::string chave) 
{
    if (objetomap[fonte]){
        return objetomap[fonte]->getLarguraLinha(idioma->getTexto(chave).c_str());
    } else {
        return 0;
    }
}
//Construtor
WriteManager::WriteManager() 
{
//    UtilLog::subSistema("Instanciando WriteSystemManager");
    idioma =  Idioma::getInstance();
}
WriteManager * WriteManager::instance;


} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
