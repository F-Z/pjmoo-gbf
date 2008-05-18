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

#ifndef _USERINTERFACE_H
#define _USERINTERFACE_H

#include "GBF.h"
#include <string>


namespace UserInterface {

//Alinhamento dos itens do menu e dos itens
enum UIAlinhamento {
  CENTRO=0,
  HORIZONTAL=1,
  VERTICAL=2
};
struct UICursor
{
    bool show;

    GBF::Ponto posicao;

};
struct UIFonteReferencia
{
    std::string nome;

    GBF::Dimensao dimensao;

};
struct UIFonteExtendida : public UIFonteReferencia
{
    GBF::Ponto posicao;

};

} // namespace UserInterface
#endif
