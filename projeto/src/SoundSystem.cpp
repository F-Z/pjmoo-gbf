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

#include "SoundSystem.h"

//Destrutor
SoundSystem::~SoundSystem() 
{
    UtilLog::sistema("Removendo SoundSystem");

    delete(musicManager);
    delete(fxManager);
    delete(status);

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}
//Retorna uma instância de SoundSystem
SoundSystem * SoundSystem::getInstance()
{
    if (instance == NULL){
        instance = new SoundSystem();
    }

    return instance;
}
//Inicializa o sistema de som
void SoundSystem::iniciar(int frequencia, Uint16 formato, SoundSystemCanal canal, Uint16 cache, int quantidadeCanais) 
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
}
//Configura sistema sonoro para parar o som
void SoundSystem::setMute(bool mute) 
{
    if (status->isAtivo()){
        status->setMute(mute);
    }
}
//Construtor
SoundSystem::SoundSystem() 
{
    UtilLog::sistema("Instanciando SoundSystem");
    bool hardware = false;

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0 ) {
        UtilLog::comentario("[Falhou] SDL_InitSubSystem(SDL_INIT_AUDIO)=%s",SDL_GetError());
    } else {
        hardware = true;
    }

    status = SoundSystemStatus::getInstance();
    status->setAtivo(hardware);

    musicManager = new SoundSystemMusicManager(status);
    fxManager    = new SoundSystemFxManager(status);
}
SoundSystem * SoundSystem::instance;

