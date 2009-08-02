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

#include "Idioma.h"

namespace GBF {

namespace Kernel {

namespace Write {

Idioma * Idioma::instance=NULL;

Idioma::~Idioma()
{
//    UtilLog::sistema("Removendo UserInterfaceTexto");
}
Idioma * Idioma::getInstance()
{
    if (instance == NULL){
        instance = new Idioma();
    }

    return instance;
}
//Configura um idioma
//Obs.: O idioma é configurado de acordo com a lista de idiomas suportado
bool Idioma::setIdioma(const std::string & codigo)
{
    bool achou = false;
   // UtilLog::tracer("UserInterfaceTexto::setIdioma(%s)",codigo.c_str());

    if ((!codigo.empty())&&(idiomaSuportado.find(codigo)!=idiomaSuportado.end())){
        idiomaPrefixo=idiomaSuportado[codigo];
        achou=true;
    }

    if ((achou)&&(!arquivo.empty())){
        atualizar();
    }

    return achou;
}
std::string Idioma::getIdioma()
{
    return idiomaPrefixo;
}
//Seleciona o idioma automaticamente de acordo com o ambiente
void Idioma::detectarIdioma()
{
    std::cout << "GBF::Kernel::Write::Idioma::detectarIdioma()" << std::endl;
#ifdef __gnu_linux__
//Descobrindo o idioma do usuário no GNU/LINUX
    const char* idioma    = getenv("LC_ALL");
    const char* idiomaAux = getenv("LANG");

    if (idioma==NULL){
        if (idiomaAux==NULL){
            setIdioma("DEFAULT");
        } else {
            if (!setIdioma(idiomaAux)){
                setIdioma("DEFAULT");
            }
        }
    } else {
        if (!setIdioma(idioma)){
            setIdioma("DEFAULT");
        }
    }
#else
//Descobrindo o idioma do usuário no MS-Windows(r)
    char idioma[6];
    int id = GetUserDefaultLangID();
    sprintf(idioma,"%d",id & 0x3ff);

    if (!setIdioma(idioma)){
        setIdioma("DEFAULT");
    }
#endif
}
bool Idioma::atualizar()
{
    char str[256];
    bool retorno = false;

    std::string fullpath=Kernel::Util::Path::getPath()+"data//etc//idioma//"+getIdioma()+"."+arquivo;

    if (!arquivo.empty()){
        std::fstream arquivoTexto(fullpath.c_str(),std::ios::in);

        if (arquivoTexto!=NULL){
            while(!arquivoTexto.eof()){
                arquivoTexto.getline(str,256);
                parser(str);
            }
            arquivoTexto.close();
            retorno = true;
        } else {
            std::cerr << "[ERROR]Idioma: File Not Found : " << fullpath << std::endl;
        }
    } else {
        std::cerr << "[ERROR]Idioma: File Not Defined" << std::endl;
    }

    return retorno;
}
void Idioma::setArquivo(const std::string & arquivo)
{
   this->arquivo=arquivo;
}
int Idioma::size()
{
    return mapaTexto.size();
}
std::string Idioma::getTexto(const std::string & chave)
{
    if (mapaTexto.find(chave)!=mapaTexto.end()){
        return mapaTexto[chave];
    } else {
        return "ERRO";
    }
}
//Retorna se existe a chave de texto
bool Idioma::isChaveTexto(const std::string & chave)
{
    return mapaTexto.find(chave)!=mapaTexto.end();
}
void Idioma::parser(char * info)
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
        mapaTexto[linha.substr(0,i)]=linha.substr(i+1,tamanho);
    }
}
//Carrega o mapeamento de idiomas e os arquivos de texto
void Idioma::carregarIdioma()
{
    char str[256];

    std::string fullpath=Kernel::Util::Path::getPath()+"//data//etc//idioma.cfg";

    std::cout << "\tCFG: " << fullpath << std::endl;

    if (arquivo.empty()){
        std::fstream arquivoTexto(fullpath.c_str(),std::ios::in);

        mapaTexto.clear();

        if (arquivoTexto!=NULL){
            while(!arquivoTexto.eof()){
                arquivoTexto.getline(str,256);
                parserIdioma(str);
            }
            arquivoTexto.close();

            std::map<std::string,std::string>::iterator it;

            for (it=idiomaSuportado.begin();it!=idiomaSuportado.end(); it++){
                std::cout << "\tIdioma: " <<  (std::string) it->second << "=" << (std::string) it->first << std::endl;;
            }

        } else {
            std::cerr << "[ERROR]Idioma: File Not Found : " << fullpath << std::endl;
        }
    }
}
void Idioma::parserIdioma(char * info)
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
void Idioma::limpar()
{
}
Idioma::Idioma()
{
    std::cout << "GBF::Kernel::Write::Idioma" << std::endl;

    carregarIdioma();
}

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF
