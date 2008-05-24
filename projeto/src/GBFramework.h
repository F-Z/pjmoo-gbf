#ifndef _GBFRAMEWORK_H
#define _GBFRAMEWORK_H

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

#include "GraphicCore.h"
#include "InputCore.h"
#include "SoundCore.h"
#include "WriteManager.h"
#include <string>

#include "FPSFactory.h"
#include "FPS.h"
#include "Log.h"
#include "ImageBufferManager.h"
#include "LayerManager.h"
#include "GraphicMode.h"
#include "StringExtract.h"
#include "SoundManagerAbstract.h"
#include "Path.h"

namespace GBF {

//Descri��o:
//     Classe central do framework
//Motiva��o:
//     Prover de forma unificada a inicializa��o e configura��o b�sica do framework
//
class GBFramework
{
  public:
    //GraphicSystemCore, n�cleo do sistema gr�fico
    GBF::Kernel::Graphic::GraphicCore * graphicSystemCore;

    GBF::Kernel::Input::InputCore * inputSystemCore;

    GBF::Kernel::Sound::SoundCore * soundSystemCore;

    GBF::Kernel::Write::WriteManager * writeSystem;

    //Destrutor
    virtual ~GBFramework();

    //Construtor
    GBFramework();

    //Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick),
    //desenha na tela o conte�do do backbuffer

    void atualizar();

    //Retorna o diret�rio base da aplica��o corrente
    std::string getPath();

    //Inicializa o Sistema, e configura o modo gr�fico
    void iniciar(int width, int height, int bpp_color, bool full, GBF::Kernel::FPS::Tipo fps);

    //Informa se o mostrador de FPS est� ativo
    bool isFPS();

    //Pausa o Sistema
    void pausar();

    //Mostra o Contador de FPS
    void setFPS(bool show);

    //Informa o caminho do diret�rio base da aplica��o corrente
    void setPath(char * fullPath);

    //Informa��o sobre o Autor e o T�tulo da Aplica��o.
    //Obs.: Usado para arquivo de log e t�tulo da janela
    void setTitulo(std::string titulo, std::string autor);


  protected:
    //Prepara o Ambiente para ser inicializado
    void carregar();

    //Controle para a��es internas
    void controleInterno();

    //Define o T�tulo para Janela
    void setTitulo(std::string titulo);


  private:
    bool fps;

    GBF::Kernel::FPS::FPS * fpsSystem;

    int numscreenshot;

};

} // namespace GBF
#endif
