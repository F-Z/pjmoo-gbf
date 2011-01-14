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
#ifndef _SOUNDSTATUS_H
#define _SOUNDSTATUS_H

#include <string> // Adicionada para poder usar a palavra reservada NULL

namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição:
//    Classe para controle do estado do sistema de som
//Motivação:
//    Fornecer um conjunto de controles básicos para o sistema de som

class SoundStatus {

    public:
        //Destrutor
        virtual ~SoundStatus();

        //Verifica se sistema de som está funcionando
        bool isActive();

        //Verifica se o som está desligado
        bool isMute();

        //Configurar se o sistema de som está funcionando
        void setActive(bool active);

        //Configura o sistema de som
        void setMute(bool mute);


    protected:
        bool active;

        bool mute;


    private:
        //Construtor
        SoundStatus();

        friend class SoundCore;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF

#endif
