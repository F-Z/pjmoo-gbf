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
#ifndef _MOUSE_H
#define _MOUSE_H

#include "GBF.h"
#include <string>

#include "Cursor.h"

namespace GBF {

namespace Kernel {

namespace Input {

/** Valores para indica��o dos bot�es
 Motiva��o: Fornecer um conjunto de valores para verifica��o dos bot�es do mouse */
enum MouseButton {
    MS_NULL,
    MS_LEFT,
    MS_MIDDLE,
    MS_RIGHT

};
/** Classe para controle do mouse
 Motiva��o: Prover o controle de eventos por meio do Mouse */

class Mouse {

    public:
        /** Destrutor */
        virtual ~Mouse();

        /** Retorna a posi��o do mouse no eixo X */
        int getX();

        /** Retorna a posi��o do mouse no eixo Y */
        int getY();

        /** Retorna a posi��o do mouse */
        GBF::Point getPoint();

        /** Carrega o curso do mouse do arquivo */
        void loadFromFile(std::string fileName);

        /** Retorna o InputSystemMouseCursor para manipula��o */
        Cursor * getMouseCursor();

        /** Configura se exibe ou n�o o cursor do mouse */
        void setMouse(bool show);

        /** Retorna se o ponteiro est� ativo na tela */
        bool isMouse();

        /** Verifica se o bot�o esquerdo foi pressionado */
        bool isButtonLeft();

        /** Verifica se o bot�o do meio foi pressionado */
        bool isButtonMiddle();

        /** Verifica se o bot�o direito foi pressionado */
        bool isButtonRight();

        /** Verifica se a combina��o de bot�es foi pressionada */
        bool isButton(bool left, bool middle, bool right);


    protected:
        Cursor * cursor;


    private:
        /** Construtor */
        Mouse();

        /** Processa os eventos do mouse */
        void update();

        GBF::Point point;

        bool mouse;

        friend class InputSystem;
};

} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF

#endif
