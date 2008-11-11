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

#include "SoundCore.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
SoundCore::~SoundCore() 
{
//    UtilLog::sistema("Removendo SoundSystem");

    delete(soundSystem);
    delete(status);

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
//Inicializa o sistema de som
void SoundCore::iniciar(int frequencia, Uint16 formato, Canal canal, Uint16 cache, int quantidadeCanais) 
{
    bool hardware = false;

    std::cout << "GBF::Kernel::Sound::SoundCore::iniciar()" << std::endl;

    if (status->isAtivo()) {
        if (Mix_OpenAudio(frequencia, formato, canal, cache) == 0 ){
            if (Mix_AllocateChannels(quantidadeCanais)>0){
                hardware = true;
            } else {
                std::cerr << "[ERROR]SDL_Mixer:" << SDL_GetError() << std::endl;
                //UtilLog::comentario("Alocando canais de Som =%s [Falhou]",SDL_GetError());
            }
        } else {
            std::cerr << "[ERROR]SDL_Mixer:" << SDL_GetError() << std::endl;
           // UtilLog::comentario("Inicializando SDL_mixer =%s [Falhou]",SDL_GetError());
        }
    }

    status->setAtivo(hardware);
    SoundManagerAbstract::setStatus(status);

    soundSystem = SoundSystem::getInstance();
    SoundSystemUtility::setSoundSystem(soundSystem);
}
//Configura sistema sonoro para parar o som
void SoundCore::setMute(bool mute) 
{
    if (status->isAtivo()){
        status->setMute(mute);
    }
}
//Construtor
SoundCore::SoundCore() 
{
    //UtilLog::sistema("Instanciando SoundSystem");
    bool hardware = false;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0 ) {
        std::cerr << "[ERROR]SDL:" << SDL_GetError() << std::endl;
    } else {
        hardware = true;
    }

    status = new SoundStatus();
    status->setAtivo(hardware);
}

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
