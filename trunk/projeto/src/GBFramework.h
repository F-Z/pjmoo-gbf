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

#ifndef _GBFRAMEWORK_H
#define _GBFRAMEWORK_H

#include "GraphicCore.h"
#include "InputCore.h"
#include "SoundCore.h"
#include "WriteManager.h"
#include <string>

#include "FPSFactory.h"
#include "FPS.h"
#include "ImageBufferManager.h"
#include "LayerManager.h"
#include "GraphicMode.h"
#include "StringExtract.h"
#include "SoundManagerAbstract.h"
#include "Path.h"
#include "Version.h"

namespace GBF {

/** Classe central do framework
   Prover de forma unificada a inicialização e configuração básica do framework */

class GBFramework
{

    public:
        /** GraphicSystemCore, núcleo do sistema gráfico */
        GBF::Kernel::Graphic::GraphicCore * graphicSystemCore;

        GBF::Kernel::Input::InputCore * inputSystemCore;

        GBF::Kernel::Sound::SoundCore * soundSystemCore;

        GBF::Kernel::Write::WriteManager * writeSystem;

        /** Destrutor */
        virtual ~GBFramework();

        /** Construtor */
        GBFramework();

        /** Atualiza o Sistema de processamento de eventos (teclado,mouse,joystick), desenha na tela o conteúdo do backbuffer */

        void update();

        /** Retorna o diretório base da aplicação corrente */
        std::string getPath();

        /** Inicializa o Sistema, e configura o modo gráfico */
        void start(int width, int height, int bpp_color, bool full, GBF::Kernel::FPS::FPSType fps);

        /** Informa se o mostrador de FPS está ativo */
        bool isFPS();

        /** Pausa o Sistema */
        void pause();

        /** Mostra o Contador de FPS */
        void setFPS(bool show);

        /** Informa o caminho do diretório base da aplicação corrente*/
        void setPath(char * fullPath);

        //Informação sobre o Autor e o Título da Aplicação.
        //Obs.: Usado para arquivo de log e título da janela
        void setTitle(std::string titlo, std::string autor);


    protected:
        /**Prepara o Ambiente para ser inicializado*/
        void load();

        /** Not implemented. Free for your implementation. */
        virtual void hookF1();
        /** Not implemented. Free for your implementation. */
        virtual void hookF2();
        /** Not implemented. Free for your implementation. */
        virtual void hookF3();
        /** Not implemented. Free for your implementation. */
        virtual void hookF4();
        /** Not implemented. Free for your implementation. */
        virtual void hookF5();
        /** Not implemented. Free for your implementation. */
        virtual void hookF6();
        /** Not implemented. Free for your implementation. */
        virtual void hookF7();
        /** Not implemented. Free for your implementation. */
        virtual void hookF8();
        /** Not implemented. Free for your implementation. */
        virtual void hookF9();
        /** F10 = Alterna entre modo de controle de teclado e mouse exclusivo*/
        virtual void hookF10();
        /**F11 = Alterna entre modo tela Cheia e Janela */
        virtual void hookF11();
        /**F12 = Salva um screen do jogo */
        virtual void hookF12();

        /** Define o Título para Janela*/
        void setTitle(std::string title);


    private:
        bool fps;

        GBF::Kernel::FPS::FPS * fpsSystem;

        int screenShotCounter;

        /** Controle para ações internas */
        void internalControl();
};

} // namespace GBF

#endif
