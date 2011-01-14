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
#include "MusicManager.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
MusicManager::~MusicManager()
{
//    UtilLog::subSistema("Removendo SoundSystemMusicManager");
    Mix_HaltMusic();
    std::map<std::string,Music*>::iterator it;

    for (it=objetomap.begin();it!=objetomap.end(); it++){
        try {
           // UtilLog::tracer("SoundMusic=%s",((*it).first).c_str());
        } catch(...){
            //UtilLog::tracer("SoundMusic=Desconhecido(a)");
        }
        delete ((*it).second);
        (*it).second=NULL;
        //UtilLog::comentario("[Ok]");
    }
    objetomap.clear();
}
//Remove uma música do gerenciador
void MusicManager::remove(std::string nome)
{
    if (objetomap[nome]){
        delete(objetomap[nome]);
        objetomap[nome]=NULL;
        objetomap.erase(nome);
    }
}
//Carregar um arquivo de música para o gerenciador
void MusicManager::loadFromFile(std::string nome, std::string arquivo)
{
    std::string fullpath=Kernel::Util::Path::getPath()+arquivo;

    Music *som = new Music();

    std::cout << "\tMusicManager: " << nome << "=" << fullpath << std::endl;
    if ((status->isActive())&&(som->loadFromFile(fullpath))){
        objetomap[nome]=som;
    } else {
        delete(som);
    }
}
//Pausa a música
void MusicManager::pause()
{
    if (status->isActive()){
        Mix_PauseMusic();
    }
}
//Toca uma música
void MusicManager::play(std::string nome)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->play();
    }
}
//Toca uma música de repetitiva
void MusicManager::playInfinity(const std::string & nome)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        if (musicaTocando!=nome){
            objetomap[nome]->playInfinity();
            musicaTocando=nome;
        }
    }
}
//Toca uma música uma certa quantidade de vezes
void MusicManager::playLoop(const std::string & nome, int vezes)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        if (musicaTocando!=nome){
            objetomap[nome]->playLoop(vezes);
            musicaTocando=nome;
        }
    }
}
//Continuar a tocar a música
void MusicManager::resume()
{
    if (status->isActive()){
        Mix_ResumeMusic();
    }
}
//Configura o volume do som
void MusicManager::setVolume(std::string nome, int volume)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->setVolume(volume);
    }
}
//Para uma música
void MusicManager::stop(const std::string & nome)
{
    if ((objetomap.find(nome)!=objetomap.end())&&(!status->isMute())){
        objetomap[nome]->stop();
        musicaTocando="";
    }
}
//Construtor
MusicManager::MusicManager()
{
    std::cout << "GBF::Kernel::Sound::MusicManager" << std::endl;
}

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
