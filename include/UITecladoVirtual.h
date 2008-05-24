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

#ifndef _UITECLADOVIRTUAL_H
#define _UITECLADOVIRTUAL_H

#include "Cor.h"
#include <string>

#include "UserInterface.h"
#include "UIVisual.h"
#include "GraphicSystemUtility.h"
#include "UIComponente.h"
#include "InputSystemUtility.h"
#include "CronometroDecrescente.h"
#include "CronometroCrescente.h"

namespace UserInterface {

namespace Componente {

class UITecladoVirtual : public GBF::Kernel::Graphic::GraphicSystemUtility, public UserInterface::UIComponente, public GBF::Kernel::Input::InputSystemUtility
{
  private:
    //Efetua o controle sobre a navegação do cursor
    void navegar();

    GBF::Cor::RGB corCursor;


  protected:
    char caracter[50];

    std::string controle[3];

    UserInterface::UIFonteReferencia fonteTeclado;

    UserInterface::UIFonteReferencia fonteControle;

    int selecao;

    int tamanhoControle;

    UserInterface::Visual::UIVisual * visual;

    void desenharBackground();

    void desenharConteudo();

    void atualizar();

    void desenhar();


  public:
    UITecladoVirtual();

    virtual ~UITecladoVirtual();

    int getTotalCaracter();

    int getTotalControle();

    int getTotalTeclas();

    int getTamanhoControle();

    void setCaracter(std::string caracteres);

    void setControle(int index, std::string texto);

    char getCaracter();

    int getIndex();

    //Define a fonte a ser usada pelo Controle
    void setFonteControle(std::string fonte);

    //Define a fonte a ser usada pelo teclado virtual
    void setFonteTeclado(std::string fonte);

    void setVisual(UserInterface::Visual::UIVisual * visual);

    void setCorCursor(const GBF::Cor::CorPaleta & r, const GBF::Cor::CorPaleta & g, const GBF::Cor::CorPaleta & b);


  protected:
    GBF::Kernel::Timer::CronometroDecrescente tempoEspera;

    GBF::Kernel::Timer::CronometroCrescente tempoBlink;

};

} // namespace UserInterface::Componente

} // namespace UserInterface
#endif
