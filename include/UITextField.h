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

#ifndef _UITEXTFIELD_H
#define _UITEXTFIELD_H

#include "UIField.h"
#include <string>


namespace UserInterface {

namespace Componente {

class UITextField : public UIField
{
  public:
    UITextField();

    virtual ~UITextField();

    void setValue(std::string value);


  protected:
    void desenharConteudo();


  private:
    std::string value;

};

} // namespace UserInterface::Componente

} // namespace UserInterface
#endif
