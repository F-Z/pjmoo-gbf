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

#include "Log.h"

namespace GBF {

namespace Kernel {

namespace Util {

void Log::setArquivo(std::string arquivo)
{
    Log::arquivo=arquivo+"_GBF_Debug.log";
}

void Log::setAutor(std::string autor)
{
    Log::autor=autor;
}

void Log::setProjeto(std::string projeto)
{
    Log::projeto=projeto;
}

void Log::iniciar()
{
    if ((arquivo=="")||(projeto=="")||(autor=="")){
        printf("Atencao:\n\r As informacoes abaixo sao obrigatorias.");
        printf("\n\t arquivo: %s",arquivo.c_str());
        printf("\n\t projeto: %s",projeto.c_str());
        printf("\n\t autor:   %s",autor.c_str());
        exit(1);
    } else {
        //verificar se isso deleta
        handleArquivo = fopen(arquivo.c_str(), "w+t");
        fclose(handleArquivo);
        //abrindo novo
        handleArquivo = fopen(arquivo.c_str(), "a+t");

        //cabecalho
        escrever("Inicio do Log. %s",Date::getInfo().c_str());
        escrever("=========================================================================");
        escrever(" Gamework's Brazilian Framework (GBF) - http://pjmoo.codigolivre.org.br  ");
        escrever("=========================================================================");
        escrever(" Projeto: %s",projeto.c_str());
        escrever(" Autor:");
        escrever(" ...%s",autor.c_str());
        escrever("=========================================================================");
    }
}

void Log::finalizar()
{
    if (handleArquivo){
        escrever("");
        escrever("Fim do Log. %s",Date::getInfo().c_str());
        fclose(handleArquivo);
        handleArquivo = NULL;
    }
}

void Log::cabecalho(const char * texto)
{
    escrever("");
    escrever("=========================================================================");
    escrever(" GBF :: %s",texto);
    escrever("=========================================================================");
    escrever("");
}

void Log::sistema(const char * texto, ...)
{

    // Cria a mensagem final
    char szBuffer[512];
    va_list arglist;

    va_start(arglist, texto);
    vsprintf(szBuffer, texto, arglist);
    va_end(arglist);

    // Escreve no arquivo de log
    fprintf(handleArquivo, "\n #:%s", szBuffer);
}

void Log::subSistema(const char * texto, ...)
{

    // Cria a mensagem final
    char szBuffer[512];
    va_list arglist;

    va_start(arglist, texto);
    vsprintf(szBuffer, texto, arglist);
    va_end(arglist);

    // Escreve no arquivo de log
    fprintf(handleArquivo, "\n\t >%s", szBuffer);
}

void Log::comentario(const char * texto, ...)
{

    // Cria a mensagem final
    char szBuffer[512];
    va_list arglist;

    va_start(arglist, texto);
    vsprintf(szBuffer, texto, arglist);
    va_end(arglist);

    // Escreve no arquivo de log
    fprintf(handleArquivo, " : %s", szBuffer);
    fflush(handleArquivo);
}

void Log::comentarioComQuebra(const char * texto, ...)
{

    // Cria a mensagem final
    char szBuffer[512];
    va_list arglist;

    va_start(arglist, texto);
    vsprintf(szBuffer, texto, arglist);
    va_end(arglist);

    // Escreve no arquivo de log
    fprintf(handleArquivo, "\n    %s", szBuffer);
    fflush(handleArquivo);
}

void Log::tracer(const char * texto, ...)
{

    // Cria a mensagem final
    char szBuffer[512];
    va_list arglist;

    va_start(arglist, texto);
    vsprintf(szBuffer, texto, arglist);
    va_end(arglist);

    // Escreve no arquivo de log
    fprintf(handleArquivo, "\n   *%s", szBuffer);
    fflush(handleArquivo);
}

std::string Log::arquivo= "";

std::string Log::autor= "";

std::string Log::projeto= "";

FILE * Log::handleArquivo= NULL;

void Log::escrever(const char * texto, ...)
{

    // Cria a mensagem final
    char szBuffer[512];
    va_list arglist;

    va_start(arglist, texto);
    vsprintf(szBuffer, texto, arglist);
    va_end(arglist);

    // Escreve no arquivo de log
    fprintf(handleArquivo, "\n %s", szBuffer);
    fflush(handleArquivo);
}


} // namespace GBF::Kernel::Util

} // namespace GBF::Kernel

} // namespace GBF
