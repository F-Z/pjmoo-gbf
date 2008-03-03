#ifndef _GBF_H
#define _GBF_H

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

#include "GraphicSystemCore.h"
#include "InputSystemCore.h"
#include "SoundSystemCore.h"
#include "WriteSystemManager.h"
#include <string>

#include "TimerSystemFPS.h"
#include "UtilLog.h"
#include "GraphicSystemImageBufferManager.h"
#include "FrameLayerManager.h"
#include "GraphicSystemMode.h"
#include "UtilExtract.h"
#include "SoundSystemInterfaceManager.h"
#include "UserInterfaceTexto.h"
#include "UserInterfaceWindow.h"

//Descrição: 
//     Classe central do framework
//Motivação:
//     Prover de forma unificada a inicialização e configuração básica do framework
// 
class GBF
{
  public:
    //GraphicSystemCore, núcleo do sistema gráfico
    GraphicSystemCore * graphicSystemCore;

    InputSystemCore * inputSystemCore;

    SoundSystemCore * soundSystemCore;

    WriteSystemManager * writeSystem;

    //Destrutor
    virtual ~GBF();

    //Construtor
    GBF();

    //Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick),
    //desenha na tela o conteúdo do backbuffer
    //Obs.: Deve ser usado na interação do loop principal do jogo
    void atualizar();

    //Retorna o diretório base da aplicação corrente
    std::string getPath();

    //Inicializa o Sistema, e configura o modo gráfico
    void iniciar(int width, int height, int bpp_color, bool full);

    bool isDefaultPath();

    //Informa se o mostrador de FPS está ativo
    bool isFPS();

    //Pausa o Sistema
    void pausar();

    void setDefaultPath(bool ativo);

    //Mostra o Contador de FPS
    void setFPS(bool show);

    //Informa o caminho do diretório base da aplicação corrente
    void setPath(char * fullPath);

    //Informação sobre o Autor e o Título da Aplicação.
    //Obs.: Usado para arquivo de log e título da janela
    void setTitulo(std::string titulo, std::string autor);


  protected:
    //Prepara o Ambiente para ser inicializado 
    void carregar();

    //Controle para ações internas
    void controleInterno();

    //Define o Título para Janela 
    void setTitulo(std::string titulo);


  private:
    bool defaultPath;

    bool fps;

    TimerSystemFPS * fpsSystem;

    int numscreenshot;

    std::string pathBase;

};
#endif
