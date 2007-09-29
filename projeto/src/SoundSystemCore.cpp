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

#include "SoundSystemCore.h"

//Destrutor
SoundSystemCore::~SoundSystemCore() 
{
    UtilLog::sistema("Removendo SoundSystem");

    delete(soundSystem);
    delete(status);

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
//Inicializa o sistema de som
void SoundSystemCore::iniciar(int frequencia, Uint16 formato, SoundSystemCanal canal, Uint16 cache, int quantidadeCanais) 
{
    bool hardware = false;

    if (status->isAtivo()) {
        if (Mix_OpenAudio(frequencia, formato, canal, cache) == 0 ){
            if (Mix_AllocateChannels(quantidadeCanais)>0){
                hardware = true;
            } else {
                UtilLog::comentario("Alocando canais de Som =%s [Falhou]",SDL_GetError());
            }
        } else {
            UtilLog::comentario("Inicializando SDL_mixer =%s [Falhou]",SDL_GetError());
        }
    }

    status->setAtivo(hardware);
    SoundSystemInterfaceManager::setStatus(status);

    soundSystem = SoundSystem::getInstance();
    SoundSystemUtility::setSoundSystem(soundSystem);
}
//Configura sistema sonoro para parar o som
void SoundSystemCore::setMute(bool mute) 
{
    if (status->isAtivo()){
        status->setMute(mute);
    }
}
//Construtor
SoundSystemCore::SoundSystemCore() 
{
    UtilLog::sistema("Instanciando SoundSystem");
    bool hardware = false;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0 ) {
        UtilLog::comentario("[Falhou] SDL_InitSubSystem(SDL_INIT_AUDIO)=%s",SDL_GetError());
    } else {
        hardware = true;
    }

    status = new SoundSystemStatus();
    status->setAtivo(hardware);


}
