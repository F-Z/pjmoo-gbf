/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2011 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/
#ifndef _SOUNDMANAGERABSTRACT_H
#define _SOUNDMANAGERABSTRACT_H

#include <string>

#include "SoundStatus.h"
#include "BaseManager.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição:
//    Classe para criação de gerenciados de som
//Motivação:
//    Fornecer uma interface padrão para gerenciamento de som

class SoundManagerAbstract : public GBF::BaseManager {

    public:
        //Destrutor
        virtual ~SoundManagerAbstract();

        //Construtor
        SoundManagerAbstract();

        //Apaga o arquivo de som do gerenciador
        virtual void remove(std::string nome) = 0;

        //Carrega no manager o arquivo de som
        virtual void loadFromFile(std::string nome, std::string arquivo) = 0;

        //Pausa o sistema de som
        virtual void pause() = 0;

        //Toca um som
        virtual void play(std::string nome) = 0;

        //Continua a tocar o som
        virtual void resume() = 0;

        //Configura o volume do som
        //Obs.: Valor do volume de 0 ate 128
        virtual void setVolume(std::string nome, int volume) = 0;


    private:
        static void setStatus(SoundStatus * instance);


    protected:
        static SoundStatus * status;

        friend class SoundCore;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF

#endif
