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

#ifndef _UIFIELD_H
#define _UIFIELD_H

#include <string>

#include "UIVisual.h"
#include "UserInterface.h"
#include "UIComponente.h"
#include "GraphicSystemUtility.h"
#include "CronometroCrescente.h"

namespace UserInterface {

namespace Componente {

class UIField : public UserInterface::UIComponente, public GBF::Kernel::Graphic::GraphicSystemUtility
{
  public:
    UIField();

    virtual ~UIField();

    void setLabel(std::string label);

    //Define a fonte a ser usada pelo label
    void setFonteLabel(std::string fonte);

    //Define a fonte a ser usada pelo Campo
    void setFonteCampo(std::string fonte);

    void maxLength(int length);

    void showCursor(bool show);

    void setCursorPosicao(int posicao);

    void setVisual(UserInterface::Visual::UIVisual * visual);


  protected:
    UserInterface::UIFonteExtendida fonteLabel;

    UserInterface::UIFonteExtendida fonteCampo;

    UserInterface::UICursor cursor;

    int indice;

    //Desenha o conteudo da janela
    void desenharBackground();

    virtual void desenharConteudo() = 0;

    void desenharForeground();

    void atualizar();

    void desenhar();

    UserInterface::Visual::UIVisual * visual;


  private:
    std::string label;

    int length;


  protected:
    GBF::Kernel::Timer::CronometroCrescente tempoBlink;

};

} // namespace UserInterface::Componente

} // namespace UserInterface
#endif
