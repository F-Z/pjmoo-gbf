/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#include "UIWindowDialog.h"

namespace UserInterface
{

namespace Window
{

const int UIWindowDialog::BUTTON_OK = 100;

UIWindowDialog::UIWindowDialog()
{
    button = NULL;
}

UIWindowDialog::~UIWindowDialog()
{
    if (button) {
        delete(button);
    }
}

void UIWindowDialog::addButton(UserInterface::Component::UIButton * button)
{
    this->button = button;
}

/** Retorna se a ação informada foi acionado */
bool UIWindowDialog::isAction(int action)
{
    if (confirmSelection() == action) {
        return true;
    } else {
        return false;
    }
}

int UIWindowDialog::confirmSelection()
{
    int selecionado = -1;

    if (((button == NULL) || (((inputSystem->keyboard->isKey(button->getKey())) || (inputSystem->joystick->isButtonA()))))
            && (tempoEspera.isFinish())) {
        tempoEspera.setReset();
        selecionado = BUTTON_OK;
    }

    return selecionado;
}

/** Inicializa as configurações da caixa de texto */
void UIWindowDialog::inicializar()
{
    UIWindow::inicializar();
    text.setLetterDimension(writeManager->getFont(text.getFont())->getDimension());
}

/** Desenha o conteudo da janela */
void UIWindowDialog::drawContent()
{
    int numeroLinha = 1;
    bool continuar = false;
    char textoChave[30];

    int posicaoTextoVertical   = point.y + espacoAntesTexto;
    int posicaoTextoHorizontal = 0;
    int auxiliar = 0;

    do {
        sprintf(textoChave, text.getKeyText().c_str(), numeroLinha);

        continuar = language->isKey(textoChave);

        if (continuar) {

            if (text.getAlignment() == Text::TEXT_CENTRAL) {
                auxiliar = writeManager->getLineWidth(text.getFont(), textoChave);
                posicaoTextoHorizontal = int (point.x + (dimension.w / 2) - (auxiliar / 2));
            } else {
                posicaoTextoHorizontal = point.x + text.getLetterDimension().w;
            }

            writeManager->writeKeyText(text.getFont(), posicaoTextoHorizontal, posicaoTextoVertical, textoChave);

            posicaoTextoVertical = point.y + espacoAntesTexto + (text.getLineSpace() * numeroLinha);
            numeroLinha++;

        } else {
            break;
        }

    } while (true);
}

/** Desenha a camada de decoração da janela (botões) */
void UIWindowDialog::drawForeground()
{
    if ((button != NULL) && (tempoEspera.isFinish())) {
        button->execute();
    }
}

/** atualiza as informações do componente (posicao, dimensao, estado) */
void UIWindowDialog::update()
{
    tempoEspera.update();

    if (button != NULL) {
        GBF::Point pontoAux = point;
        GBF::Dimension d = button->getDimension();
        pontoAux.x = (point.x + dimension.w) - d.w;
        pontoAux.y = (point.y + dimension.h) - d.h;
        button->setPoint(pontoAux.x, pontoAux.y);
    }
}

} // namespace UserInterface::Window

} // namespace UserInterface
