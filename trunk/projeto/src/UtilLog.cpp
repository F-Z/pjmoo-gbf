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

#include "UtilLog.h"

void UtilLog::setArquivo(std::string arquivo)
{
    UtilLog::arquivo=arquivo+"_GBF_Debug.log";
}

void UtilLog::setAutor(std::string autor)
{

	UtilLog::autor=autor;
}

void UtilLog::setProjeto(std::string projeto)
{
    UtilLog::projeto=projeto;
}

void UtilLog::iniciar()
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
        //handleArquivo = fopen(arquivo.c_str(), "w+t");
        handleArquivo = fopen(arquivo.c_str(), "a+t");

        //cabecalho
        escrever("Inicio do Log. %s",UtilDate::getInfo().c_str());
        escrever("=========================================================================");
        escrever(" Gamework's Brazilian Framework (GBF) - http://pjmoo.codigolivre.org.br  ");
        escrever("=========================================================================");
        escrever(" Projeto: %s",projeto.c_str());
        escrever(" Autor:");
        escrever(" ...%s",autor.c_str());
        escrever("=========================================================================");
    }
}

void UtilLog::finalizar()
{
    if (handleArquivo){
        escrever("");
        escrever("Fim do Log. %s",UtilDate::getInfo().c_str());
        fclose(handleArquivo);
        handleArquivo = NULL;
    }
}

void UtilLog::cabecalho(const char * texto)
{
    escrever("");
    escrever("=========================================================================");
    escrever(" GBF :: %s",texto);
    escrever("=========================================================================");
    escrever("");
}

void UtilLog::sistema(const char * texto, ...)
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

void UtilLog::subSistema(const char * texto, ...)
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

void UtilLog::comentario(const char * texto, ...)
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

void UtilLog::comentarioComQuebra(const char * texto, ...)
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

void UtilLog::tracer(const char * texto, ...)
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

std::string UtilLog::arquivo = "";

std::string UtilLog::autor = "";

std::string UtilLog::projeto = "";

FILE * UtilLog::handleArquivo = NULL;

void UtilLog::escrever(const char * texto, ...)
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

