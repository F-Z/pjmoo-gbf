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

/** Valores para indicação dos botões
 Motivação: Fornecer um conjunto de valores para verificação dos botões do mouse */
enum MouseButton {
    MS_NULL,
    MS_LEFT,
    MS_MIDDLE,
    MS_RIGHT

};
/** Classe para controle do mouse
 Motivação: Prover o controle de eventos por meio do Mouse */

class Mouse {

    public:
        /** Destrutor */
        virtual ~Mouse();

        /** Retorna a posição do mouse no eixo X */
        int getX();

        /** Retorna a posição do mouse no eixo Y */
        int getY();

        /** Retorna a posição do mouse */
        GBF::Point getPoint();

        /** Carrega o curso do mouse do arquivo */
        void loadFromFile(std::string fileName);

        /** Retorna o InputSystemMouseCursor para manipulação */
        Cursor * getMouseCursor();

        /** Configura se exibe ou não o cursor do mouse */
        void setMouse(bool show);

        /** Retorna se o ponteiro está ativo na tela */
        bool isMouse();

        /** Verifica se o botão esquerdo foi pressionado */
        bool isButtonLeft();

        /** Verifica se o botão do meio foi pressionado */
        bool isButtonMiddle();

        /** Verifica se o botão direito foi pressionado */
        bool isButtonRight();

        /** Verifica se a combinação de botões foi pressionada */
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
