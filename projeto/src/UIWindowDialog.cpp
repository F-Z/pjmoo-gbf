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

#include "UIWindowDialog.h"

namespace UserInterface
{

namespace Window
{

const int UIWindowDialog::BOTAO_OK = 100;

UIWindowDialog::UIWindowDialog()
{
    botao = NULL;
}

UIWindowDialog::~UIWindowDialog()
{
    if (botao) {
        delete(botao);
    }
}

void UIWindowDialog::adicionarBotao(UserInterface::Component::UIButton * novoBotao)
{
    botao = novoBotao;
}

//Retorna se a ação informada foi acionado
bool UIWindowDialog::isAcao(int tipoAcao)
{
    if (confirmarSelecao() == tipoAcao) {
        return true;
    } else {
        return false;
    }
}

int UIWindowDialog::confirmarSelecao()
{
    int selecionado = -1;

    if (((botao == NULL) || (((inputSystem->keyboard->isKey(botao->getKey())) || (inputSystem->joystick->isButtonA()))))
            && (tempoEspera.isTerminou())) {
        tempoEspera.setResetar();
        selecionado = BOTAO_OK;
    }

    return selecionado;
}

//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindowDialog::inicializar()
{
    UIWindow::inicializar();
    texto.setLetterDimension(writeManager->getFonte(texto.getFont())->getDimensao());
}

//Desenha o conteudo da janela

//Desenha o conteudo da janela
void UIWindowDialog::desenharConteudo()
{
    int numeroLinha = 1;
    bool continuar = false;
    char textoChave[30];

    int posicaoTextoVertical   = position.y + espacoAntesTexto;
    int posicaoTextoHorizontal = 0;
    int auxiliar = 0;

    do {
        sprintf(textoChave, texto.getKeyText().c_str(), numeroLinha);

        continuar = text->isKey(textoChave);

        if (continuar) {

            if (texto.getAlignment() == Text::TEXT_CENTRAL) {
                auxiliar = writeManager->getLarguraLinha(texto.getFont(), textoChave);
                posicaoTextoHorizontal = int (position.x + (dimension.w / 2) - (auxiliar / 2));
            } else {
                posicaoTextoHorizontal = position.x + texto.getLetterDimension().w;
            }

            writeManager->escreverLocalizado(texto.getFont(), posicaoTextoHorizontal, posicaoTextoVertical, textoChave);

            posicaoTextoVertical = position.y + espacoAntesTexto + (texto.getLineSpace() * numeroLinha);
            numeroLinha++;

        } else {
            break;
        }

    } while (true);
}

//Desenha a camada de decoração da janela (botões)
void UIWindowDialog::desenharForeground()
{
    if ((botao != NULL) && (tempoEspera.isTerminou())) {
        botao->execute();
    }
}

//atualiza as informações do componente (posicao, dimensao, estado)
void UIWindowDialog::update()
{
    tempoEspera.processar();

    if (botao != NULL) {
        GBF::Point pontoAux = position;
        GBF::Dimension d = botao->getDimension();
        pontoAux.x = (position.x + dimension.w) - d.w;
        pontoAux.y = (position.y + dimension.h) - d.h;
        botao->setPosition(pontoAux.x, pontoAux.y);
    }
}

} // namespace UserInterface::Window

} // namespace UserInterface
