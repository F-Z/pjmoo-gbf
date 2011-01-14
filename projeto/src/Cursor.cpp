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
#include "Cursor.h"

namespace GBF {

namespace Kernel {

namespace Input {

/** Destrutor */
Cursor::~Cursor()
{
    //UtilLog::subSistema("Removendo InputSystemMouseCursor");
}

/** Carregar arquivo contendo a imagem do ponteiro */
bool Cursor::loadFromFile(std::string fileName)
{
    if (image){
        SDL_FreeSurface(image);
    }

    image = IMG_Load(fileName.c_str());

    if (image){
        convertSurface();
        setColorKey(255, 0, 255);
        point.y = 0;
        point.x = 0;
        return true;
    } else {
        std::cerr << "[ERROR]SDL: " << SDL_GetError() << std::endl;

        return false;
    }
}

/** Desenha o ponteiro na tela */
void Cursor::draw(int x, int y)
{
    point.x = x;
    point.y = y;

    if (image){
        screen->blitSurface(image, point);
    }
}

/** Construtor */
Cursor::Cursor()
{
    std::cout << "GBF::Kernel::Input::Cursor " << std::endl;
}

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
