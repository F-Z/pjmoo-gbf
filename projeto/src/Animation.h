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

#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "GBF.h"

namespace GBF {

namespace Image {

namespace Sprite {

struct Frame {
    int current;

    int total;

};

class Animation {

    public:
        //Construtor
        Animation();

        //Ajusta a area de corte do sprite - posicionamento nos frames
        void cutSet(int direction, int width);

        //Informa a quantidade de quadros e a taxa de repetição
        void configuration(int total, int repetitionRate);

        //Informa se animação está no fim - último frame
        bool isEnd();

        //Informa se animação está no inicio - primeiro frame
        bool isBegin();

        //Retorna a dimensão do quadro
        GBF::Area getFrameSize();

        int process();

        //Anima o sprite de forma manual, toda chamada a esse metodo anima o personagem
        void processManual();

        //Define se a animação é automática ou manual
        void setAutomatic(bool automatic);

        //Define a dimensão do quadro
        void setFrameSize(GBF::Area area);

        //Coloca a animação no primeiro frame
        void setBegin();


    protected:
        bool automatic;

        GBF::Area cutArea;

        Frame frame;

        Frame repetition;

        //Informa o quadro a ser usado na animação
        void setFrame(int quadro);


    private:
        //Anima o Sprite de forma automática
        int animate();

        friend class SpriteItem;
};

} // namespace GBF::Image::Sprite

} // namespace GBF::Image

} // namespace GBF

#endif
