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
#include "FX.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Destrutor
FX::~FX()
{
    if (efeito){
        Mix_FreeChunk(efeito);
        efeito = NULL;
    }
//UtilLog::getInstance()->status("[SoundFx Removido(a)]");
}
//Lê arquivo de efeito sonoro
bool FX::loadFromFile(std::string arquivo)
{
    efeito = Mix_LoadWAV(arquivo.c_str());

    if (efeito){
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;
        return false;
    }
}
//Toca Efeto sonoro
int FX::play()
{
    return Mix_PlayChannel(-1,efeito,0);
}
//Configura o volume do efeito,
//Obs.: Valor de 0 ate 128
void FX::setVolume(int valor)
{
    Mix_VolumeChunk(efeito,valor);
}
//Construtor
FX::FX()
{
    efeito = NULL;
}

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
