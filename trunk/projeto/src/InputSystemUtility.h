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
