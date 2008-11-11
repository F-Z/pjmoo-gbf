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

#include "Music.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
Music::~Music() 
{
    Mix_FreeMusic(musica);
    musica = NULL;
    //UtilLog::getInstance()->status("[SoundMusic Removido(a)]");
}
//Lê arquivo de música
bool Music::carregarArquivo(std::string arquivo) 
{
    musica = Mix_LoadMUS(arquivo.c_str());

    if (musica){
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
        return false;
    }
}
//Toca Música de Fundo
void Music::play() 
{
    Mix_PlayMusic(musica, 0);
}
//Toca Música de Fundo de forma infinita
void Music::playInfinity() 
{
    playLoop(-1);
}
//Toca Música de Fundo várias vezes
void Music::playLoop(int vezes) 
{

	Mix_PlayMusic(musica, vezes);

}
//Configura o volume da música
//Obs.: Valor de 0 ate 128 
void Music::setVolume(int valor) 
{
    Mix_VolumeMusic(valor);
}
//Para a música
void Music::stop() 
{
    Mix_HaltMusic();
}
//Construtor
Music::Music() 
{

}

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
