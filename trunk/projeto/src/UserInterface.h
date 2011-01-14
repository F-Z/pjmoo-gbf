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
#ifndef _USERINTERFACE_H
#define _USERINTERFACE_H

#include "GBF.h"
#include <string>

/** Namespace para interface gr�fica de usu�rio */
namespace UserInterface {

/** Alinhamento dos itens do menu e dos itens */
enum UIAlinhamento {
    CENTRO = 0,
    HORIZONTAL = 1,
    VERTICAL = 2
};

/** Estrutura para representa��o do Cursor de edi��o */
struct UICursor
{
    bool show;

    GBF::Point point;
};

/** Estrutura para representa��o b�sica de um fonte */
struct UIFont
{
    std::string name;

    GBF::Dimension dimension;
};

/** Estrutura para representa��o de uma fonte extendida */
struct UIFontExtend : public UIFont
{
    GBF::Point point;
};

} // namespace UserInterface

#endif
