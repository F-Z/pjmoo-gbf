////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2009 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.sourceforge.net
////        http://www.davidferreira.com.br
////////////////////////////////////////////////////////////////////////

#include "Language.h"

namespace GBF {

namespace Kernel {

namespace Write {

Language * Language::instance=NULL;

Language::~Language()
{
//    UtilLog::sistema("Removendo UserInterfaceTexto");
}
Language * Language::getInstance()
{
    if (instance == NULL){
        instance = new Language();
    }

    return instance;
}
//Configura um idioma
//Obs.: O idioma é configurado de acordo com a lista de idiomas suportado
bool Language::setLanguage(const std::string & codigo)
{
    bool achou = false;
   // UtilLog::tracer("UserInterfaceTexto::setIdioma(%s)",codigo.c_str());
    std::cout << "\tIdioma: " << codigo << std::endl;

    if ((!codigo.empty())&&(idiomaSuportado.find(codigo)!=idiomaSuportado.end())){
        prefix=idiomaSuportado[codigo];
        achou=true;
    }

    if ((achou)&&(!fileName.empty())){
        refresh();
    }

    return achou;
}
std::string Language::getLanguage()
{
    return prefix;
}
//Seleciona o idioma automaticamente de acordo com o ambiente
void Language::autodetect()
{
    std::cout << "GBF::Kernel::Write::Language::autodetect()" << std::endl;
#ifdef __gnu_linux__
//Descobrindo o idioma do usuário no GNU/LINUX
    const char* idioma    = getenv("LC_ALL");
    const char* idiomaAux = getenv("LANG");

    if (idioma==NULL){
        if (idiomaAux==NULL){
            setLanguage("DEFAULT");
        } else {
            if (!setLanguage(idiomaAux)){
                setLanguage("DEFAULT");
            }
        }
    } else {
        if (!setLanguage(idioma)){
            setLanguage("DEFAULT");
        }
    }
#else
//Descobrindo o idioma do usuário no MS-Windows(r)
    char idioma[6];
    int id = GetUserDefaultLangID();
    sprintf(idioma,"%d",id & 0x3ff);

    if (!setLanguage(idioma)){
        setLanguage("DEFAULT");
    }
#endif
}
bool Language::refresh()
{
    char str[256];
    bool retorno = false;

    std::string fullpath=Kernel::Util::Path::getPath()+"data//etc//idioma//"+getLanguage()+"."+fileName;

    if (!fileName.empty()){
        std::fstream arquivoTexto(fullpath.c_str(),std::ios::in);

        if (arquivoTexto!=NULL){
            while(!arquivoTexto.eof()){
                arquivoTexto.getline(str,256);
                parser(str);
            }
            arquivoTexto.close();
            retorno = true;
        } else {
            std::cerr << "[ERROR]Language: File Not Found : " << fullpath << std::endl;
        }
    } else {
        std::cerr << "[ERROR]Language: File Not Defined" << std::endl;
    }

    return retorno;
}
void Language::setFileName(const std::string & fileName)
{
   this->fileName=fileName;
}
int Language::size()
{
    return mapaTexto.size();
}
std::string Language::getText(const std::string & key)
{
    if (mapaTexto.find(key)!=mapaTexto.end()){
        return mapaTexto[key];
    } else {
        return "ERRO";
    }
}
//Retorna se existe a chave de texto
bool Language::isKey(const std::string & key)
{
    return mapaTexto.find(key)!=mapaTexto.end();
}
void Language::parser(char * info)
{
    int i = 0;
    std::string linha = info;
    int tamanho = linha.length();

    for (i=0;i<tamanho;i++){
        if (linha[0]=='#'){
            break;
        } else if (linha[i]=='=') {
            break;
        }
    }
    if ((i>0)&&(tamanho>0)){
        mapaTexto[linha.substr(0,i)]=linha.substr(i+1,tamanho);
    }
}
//Carrega o mapeamento de idiomas e os arquivos de texto
void Language::load()
{
    char str[256];

    std::string fullpath=Kernel::Util::Path::getPath()+"//data//etc//idioma.cfg";

    std::cout << "\tCFG: " << fullpath << std::endl;

    if (fileName.empty()){
        std::fstream arquivoTexto(fullpath.c_str(),std::ios::in);

        mapaTexto.clear();

        if (arquivoTexto!=NULL){
            while(!arquivoTexto.eof()){
                arquivoTexto.getline(str,256);
                parserLanguage(str);
            }
            arquivoTexto.close();

            std::map<std::string,std::string>::iterator it;

            for (it=idiomaSuportado.begin();it!=idiomaSuportado.end(); it++){
                std::cout << "\tLanguage: " <<  (std::string) it->second << "=" << (std::string) it->first << std::endl;;
            }

        } else {
            std::cerr << "[ERROR]Language: File Not Found : " << fullpath << std::endl;
        }
    }
}
void Language::parserLanguage(char * info)
{
    int i = 0;
    std::string linha = info;
    int tamanho = linha.length();

    for (i=0;i<tamanho;i++){
        if (linha[0]=='#'){
            break;
        } else if (linha[i]=='=') {
            break;
        }
    }

    if ((i>0)&&((i+1)<tamanho)){
        idiomaSuportado[linha.substr(0,i)]=linha.substr(i+1,tamanho);
    }
}
void Language::clear()
{
}
Language::Language()
{
    std::cout << "GBF::Kernel::Write::Language" << std::endl;

    load();
}

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
