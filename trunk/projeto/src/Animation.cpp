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

#include "Animation.h"

namespace GBF {

namespace Image {

namespace Sprite {

//Construtor
Animation::Animation() {
    automatic = false;

    frame.current = 0;
    frame.total = 0;

    repetition.current = 0;
    repetition.total = 0;
}

//Ajusta a area de corte do sprite - posicionamento nos frames
void Animation::cutSet(int direction, int width) {
    cutArea.left = (direction) * (width * frame.total);
}

//Informa a quantidade de quadros e a taxa de repeti��o
void Animation::configuration(int total, int repetitionRate) {
    frame.total = total;
    repetition.total = repetitionRate;
}

//Informa se anima��o est� no fim - �ltimo frame
bool Animation::isEnd() {
//verificar se deve-se utilizar 'repeticao.total
    if ((frame.current == frame.total - 1) && (repetition.current == repetition.total)) {
        return true;
    }
    else {
        return false;
    }
}

//Informa se anima��o est� no inicio - primeiro frame
bool Animation::isBegin() {
    if (frame.current == 0) {
        return true;
    }
    else {
        return false;
    }
}

//Retorna a dimens�o do quadro
GBF::Area Animation::getFrameSize() {
    return cutArea;
}

int Animation::process() {
    if (automatic) {
        animate();
    }

    return frame.current;
}

//Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem
void Animation::processManual() {
    animate();
}

//Define se a anima��o � autom�tica ou manual
void Animation::setAutomatic(bool automatic) {
    this->automatic = automatic;
}

//Define a dimens�o do quadro
void Animation::setFrameSize(GBF::Area area) {
    cutArea = area;
}

//Coloca a anima��o no primeiro frame
void Animation::setBegin() {
    repetition.current = 0;
    frame.current     = 0;
}

//Informa o quadro a ser usado na anima��o
void Animation::setFrame(int quadro) {
    if (quadro >= 0) {
        if (quadro < frame.total) {
            frame.current = quadro;
        }
        else {
            frame.current = frame.total - 1;
        }
    }
}

//Anima o Sprite de forma autom�tica
int Animation::animate() {
    repetition.current++;

    if (repetition.current > repetition.total) {
        frame.current++;

        if (frame.current >= frame.total) {
            frame.current = 0;
        }

        repetition.current = 0;
    }

    return frame.current;
}

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF
