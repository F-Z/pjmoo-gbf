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

#include "UIItemText.h"

namespace UserInterface {

namespace Menu {

GBF::Kernel::Write::WriteManager * UIItemText::writeManager = NULL;

UIItemText::UIItemText(const std::string & text, const std::string & font)
{
    this->text = text;
    this->font = font;

    time.setInitialTime(0);
    time.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    time.setReset();

    if (writeManager == NULL){
        writeManager = GBF::Kernel::Write::WriteManager::getInstance();
    }
}

UIItemText::~UIItemText()
{
}

void UIItemText::draw(int x, int y)
{
    if (isActive()){
        time.update();

        if (time.getTime() % 2 == 0){
            writeManager->writeKeyText(font, x, y, text.c_str());
        }
    } else {
        writeManager->writeKeyText(font, x, y, text.c_str());
    }
}

int UIItemText::getQuantidadeLetras()
{
    return writeManager->language->getText(text).length();
}

GBF::Dimension UIItemText::getDimensaoLetra()
{
    return writeManager->getFont(font)->getDimension();
}

} // namespace UserInterface::Menu

} // namespace UserInterface
