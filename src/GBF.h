#ifndef _GBF_H
#define _GBF_H

////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2006 David de Almeida Ferreira
////    
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////    
////    David Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include <string>

#include "GraphicSystem.h"
#include "InputSystem.h"
#include "WriteSystemManager.h"
#include "SoundSystem.h"
#include "TimerSystemFPS.h"
#include "UtilLog.h"
#include "GraphicSystemImageBufferManager.h"
#include "FrameLayerManager.h"
#include "GraphicSystemMode.h"
#include "UtilExtract.h"
#include "SoundSystemInterfaceManager.h"
#include "UserInterfaceTexto.h"

//*
// * \class GBF
// * \brief Classe Central do Framework
// * \author David de Almeida Ferreira
// * \date Criado em 24/10/2004
// * \warning nenhum
// 
class GBF {
  public:
    //Construtor
    GBF();

    //Destrutor
    virtual ~GBF();

    //Informação sobre o Autor e o Título da Aplicação.
    //Usado para arquivo de log e título da janela
    void setTitulo(std::string titulo, std::string autor);

    //Inicializa o Sistema, e configura o modo gráfico
    void iniciar(int width, int height, int bpp_color, bool full);

    //Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick),
    //desenha na tela o conteúdo do backbuffer
    //Obs.: Deve ser usado na interação do loop principal do jogo
    void atualizar();

    //Pausa o Sistema
    void pausar();

    //Mostra o Contador de FPS
    //Obs.: Desabilitado
    void setFPS(bool show);

    //Informa se o mostrador de FPS está ativo
    //Obs.: Desabilitado
    bool isFPS();

    //Informa o caminho do diretório base da aplicação corrente
    void setPath(char * fullPath);

    //Retorna o diretório base da aplicação corrente
    std::string getPath();

    bool isDefaultPath();

    void setDefaultPath(bool ativo);

    GraphicSystem * graphicSystem;

    InputSystem * inputSystem;

    WriteSystemManager * writeSystem;

    SoundSystem * soundSystem;


  private:
    bool fps;

    int numscreenshot;

    std::string pathBase;

    bool defaultPath;

    TimerSystemFPS * fpsSystem;


  protected:
    //Controle para ações internas
    
    void controleInterno();

    //* Prepara o Ambiente para ser inicializado 
    void carregar();

    //* Define o Título para Janela 
    void setTitulo(std::string titulo);

};
#endif
