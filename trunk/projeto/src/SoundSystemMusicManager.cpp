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

#include "SoundSystemMusicManager.h"

//Destrutor
SoundSystemMusicManager::~SoundSystemMusicManager() 
{
    UtilLog::subSistema("Removendo SoundSystemMusicManager");
    std::map<std::string,SoundSystemMusic*>::iterator it;

    Mix_HaltMusic();
    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
            UtilLog::tracer("SoundMusic=%s",((*it).first).c_str());
        } catch(...){
            UtilLog::tracer("SoundMusic=Desconhecido(a)");
        }
        delete ((*it).second);
        (*it).second=NULL;
        UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
//Toca uma música
void SoundSystemMusicManager::play(std::string nome) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->play();
    }
}
//Carregar um arquivo de música para o gerenciador
void SoundSystemMusicManager::carregar(std::string nome, std::string arquivo) 
{
    SoundSystemMusic *som = new SoundSystemMusic();

    std::string fullpath=pathBase+arquivo;

    //UtilLog::getInstance()->inicializando("SoundMusicManager::Carregar()");
    UtilLog::tracer("SoundMusic=%s Arquivo=%s",nome.c_str(),fullpath.c_str());

    if ((status->isAtivo())&&(som->carregarArquivo(fullpath))){
        objetomap[nome]=som;
        UtilLog::comentario("[Ok]");
    } else {
        UtilLog::comentario("[Falhou]");
    }
}
//Remove uma música do gerenciador
void SoundSystemMusicManager::apagar(std::string nome) 
{
    if (objetomap[nome]){
        delete(objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
//Pausa a música
void SoundSystemMusicManager::pause() 
{

    if (status->isAtivo()){
    	Mix_PauseMusic();
    }
}
//Continuar a tocar a música
void SoundSystemMusicManager::resume() 
{
    if (status->isAtivo()){
        Mix_ResumeMusic();
    }
}
//Toca uma música uma certa quantidade de vezes
void SoundSystemMusicManager::playLoop(const std::string & nome, int vezes) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        if (musicaTocando!=nome){
            objetomap[nome]->playLoop(vezes);
            musicaTocando=nome;
        }
    }
}
//Toca uma música de repetitiva
void SoundSystemMusicManager::playInfinity(const std::string & nome) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        if (musicaTocando!=nome){
            objetomap[nome]->playInfinity();
            musicaTocando=nome;
        }
    }
}
//Para uma música
void SoundSystemMusicManager::stop(const std::string & nome) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->stop();
        musicaTocando="";
    }
}
//Construtor
SoundSystemMusicManager::SoundSystemMusicManager(SoundSystemStatus * status):SoundSystemInterfaceManager(status){
    UtilLog::subSistema("Instanciando SoundSystemMusicManager");
}
//Configura o volume do som
void SoundSystemMusicManager::setVolume(std::string nome, int volume) 
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->setVolume(volume);
    }
}
