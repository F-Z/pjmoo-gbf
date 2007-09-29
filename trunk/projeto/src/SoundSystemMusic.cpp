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

#include "SoundSystemMusic.h"

//Destrutor
SoundSystemMusic::~SoundSystemMusic() 
{
    Mix_FreeMusic(musica);
    musica = NULL;
    //UtilLog::getInstance()->status("[SoundMusic Removido(a)]");
}
//L� arquivo de m�sica
bool SoundSystemMusic::carregarArquivo(std::string arquivo) 
{
    musica = Mix_LoadMUS(arquivo.c_str());

    if (musica){
        return true;
    } else {
        return false;
    }
}
//Toca M�sica de Fundo
void SoundSystemMusic::play() 
{
    Mix_PlayMusic(musica, 0);
}
//Toca M�sica de Fundo de forma infinita
void SoundSystemMusic::playInfinity() 
{
    playLoop(-1);
}
//Toca M�sica de Fundo v�rias vezes
void SoundSystemMusic::playLoop(int vezes) 
{

	Mix_PlayMusic(musica, vezes);

}
//Configura o volume da m�sica
//Obs.: Valor de 0 ate 128 
void SoundSystemMusic::setVolume(int valor) 
{
    Mix_VolumeMusic(valor);
}
//Para a m�sica
void SoundSystemMusic::stop() 
{
    Mix_HaltMusic();
}
//Construtor
SoundSystemMusic::SoundSystemMusic() 
{

}
