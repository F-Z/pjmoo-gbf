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

#ifndef _SOUNDSYSTEMSTATUS_H
#define _SOUNDSYSTEMSTATUS_H

#include <string> // Adicionada para poder usar a palavra reservada NULL
//Descri��o: 
//    Classe para controle do estado do sistema de som
//Motiva��o:
//    Fornecer um conjunto de controles b�sicos para o sistema de som
class SoundSystemStatus {
  public:
    //Destrutor
    virtual ~SoundSystemStatus();

    //Verifica se sistema de som est� funcionando
    bool isAtivo();

    //Verifica se o som est� desligado
    bool isMute();

    //Configurar se o sistema de som est� funcionando
    void setAtivo(bool ativo);

    //Configura o sistema de som
    void setMute(bool mute);


  protected:
    bool ativo;

    bool mute;


  private:
    //Construtor
    SoundSystemStatus();

  friend class SoundSystemCore;
};
#endif
