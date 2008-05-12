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

#ifndef _UIVISUALSOLIDO_H
#define _UIVISUALSOLIDO_H

#include "UIVisual.h"
#include "Cor.h"

namespace UserInterface {

namespace Visual {

class UIVisualSolido : public UIVisual
{
  public:
    //Construtor
    UIVisualSolido();

    //Destrutor
    virtual ~UIVisualSolido();

    void setCorFundo(const GBF::Cor::CorPaleta & r, const GBF::Cor::CorPaleta & g, const GBF::Cor::CorPaleta & b);

    //Desenha o EstiloVisual do Componente
    virtual void desenhar();

    //Retorna uma copia do objeto
    virtual UIVisual * clone();


  protected:
    GBF::Cor::RGB corFundo;

};

} // namespace UserInterface::Visual

} // namespace UserInterface
#endif
