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

#ifndef _FXMANAGER_H
#define _FXMANAGER_H

#include <string>

#include <map>

#include "FX.h"
#include "SoundManagerAbstract.h"
#include "Path.h"

namespace GBF {

namespace Kernel {

namespace Sound {

//Descrição:
//    Classe para gerenciamento de Efeitos sonoros
//Motivação:
//    Fornecer mecanismos para gerenciamento de efeitos sonoros
class FXManager : public SoundManagerAbstract {
  public:
    //Destrutor
    virtual ~FXManager();

    //Toca uma efeito sonoro
    virtual void play(std::string nome);

    //Carregar um arquivo de efeito sonoro para o gerenciador
    virtual void loadFromFile(std::string nome, std::string arquivo);

    //Remove um efeito sonoro do gerenciador
    virtual void apagar(std::string nome);

    //Pausa o efeito sonoro
    virtual void pause();

    //Continuar a tocar o efeito sonoro
    virtual void resume();

    //Toca um efeito sonoro de acordo com as coordenadas
    void playPanEffect(std::string nome, int left, int right);

    //Toca um efeito sonoro detectando em qual caixa está mais próximo
    void playPanEffect(std::string nome, int posicao);

    //Determina a área para calculo de efeito sonoro
    void setLimite(int left, int right);

    //Configura o volume do efeito sonoro
    //Obs.: Valor do volume de 0 ate 128
    virtual void setVolume(std::string nome, int volume);


  private:
    //Construtor
    FXManager();


  protected:
    std::map<std::string,FX*> objetomap;

    int area_left;

    int area_right;

  friend class SoundSystem;
};

} // namespace GBF::Kernel::Sound

} // namespace GBF::Kernel

} // namespace GBF
#endif
