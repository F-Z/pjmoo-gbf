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

#ifndef _MUSICMANAGER_H
#define _MUSICMANAGER_H

#include <string>

#include <map>

#include "Music.h"
#include "SoundManagerAbstract.h"
#include "Path.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição:
//    Classe para gerenciamento de Música
//Motivação:
//    Fornecer mecanismos para gerenciamento de músicas de fundo

class MusicManager : public SoundManagerAbstract {

    public:
        //Destrutor
        virtual ~MusicManager();

        //Remove uma música do gerenciador
        virtual void remove(std::string nome);

        //Carregar um arquivo de música para o gerenciador
        virtual void loadFromFile(std::string nome, std::string arquivo);

        //Pausa a música
        virtual void pause();

        //Toca uma música
        virtual void play(std::string nome);

        //Toca uma música de repetitiva
        void playInfinity(const std::string & nome);

        //Toca uma música uma certa quantidade de vezes
        void playLoop(const std::string & nome, int vezes);

        //Continuar a tocar a música
        virtual void resume();

        //Configura o volume do som
        virtual void setVolume(std::string nome, int volume);

        //Para uma música
        void stop(const std::string & nome);


    protected:
        std::map<std::string, Music*> objetomap;


    private:
        std::string musicaTocando;

        //Construtor
        MusicManager();

        friend class SoundSystem;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF

#endif
