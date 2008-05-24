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
////        http://pjmoo.sourceforge.net
////////////////////////////////////////////////////////////////////////

#ifndef _INPUTSYSTEMUTILITY_H
#define _INPUTSYSTEMUTILITY_H

#include "InputSystem.h"

namespace GBF {

namespace Kernel {

namespace Input {

class InputSystemUtility
{
  protected:
    static InputSystem * inputSystem;


  private:
    static void setInputSystem(InputSystem * instance);

  friend class InputCore;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
#endif
