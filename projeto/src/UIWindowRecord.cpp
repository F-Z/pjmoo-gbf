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

#include "UIWindowRecord.h"

namespace UserInterface {

namespace Window {

void UIWindowRecord::update()
{
    tempoEspera.update();

    textName.setValue(record.nome);
    textScore.setValue(record.pontos);
}

/** Desenha o botão de ação da janela */
void UIWindowRecord::drawForeground()
{
    if (showErro){
        writeManager->writeKeyText(fontNotice.nome, fontNotice.posicao.x, fontNotice.posicao.y, "GBF_UIRecorde_warning");
    }
}

/** Desenha o conteudo da janela */
void UIWindowRecord::drawContent()
{
    // escrevendo titulo centralizado
    writeManager->writeKeyText(fontTitle.nome, fontTitle.posicao.x, fontTitle.posicao.y, "GBF_UIRecorde_title");

    keyboard.execute();
    textName.execute();
    textScore.execute();
}

/** Efetua as ações de acordo com a posição do cursor */
int UIWindowRecord::confirmSelection()
{
    int opcao = false;

    if ((inputSystem->keyboard->isKey(SDLK_RETURN)) || (inputSystem->joystick->isButtonA())){

        showErro = false;

        int selecao = keyboard.getIndex();

        if ((selecao >= 0) && (selecao < keyboard.getTotalCaracter())){
            record.nome[nameIndex] = keyboard.getCaracter();
            nameIndex++;
        } else if (selecao == keyboard.getTotalCaracter()){//controle voltar
            nameIndex--;
        } else if (selecao == keyboard.getTotalCaracter() + 1){//controle avancar
            nameIndex++;
        } else if (selecao == keyboard.getTotalCaracter() + 2){//controle salvar
            //if (recorde.nome[0]!=' '){
            if (strlen(record.nome) > 1){
                opcao = BUTTON_SAVE;
            } else {
                showErro = true;
            }
        }

        tempoEspera.setReset();
    }

    if (nameIndex < 0){
        nameIndex = 0;
    } else if (nameIndex > 9){
        nameIndex = 9;
    }

    textName.setCursorPosicao(nameIndex);

    return opcao;
}

const int UIWindowRecord::BUTTON_SAVE = 200;

/** Inicializa as configurações da caixa de texto */
void UIWindowRecord::inicializar()
{
    UIWindow::inicializar();

    GBF::Dimension d = keyboard.getDimension();

    int pX = (point.x + dimension.w) / 2 - (d.w / 2);
    int pY = (point.y + dimension.h) / 2;

    keyboard.setPoint(pX, pY);


    pY = pY + keyboard.getDimension().h;
    fontNotice.posicao.x = pX;
    fontNotice.posicao.y = pY;

    pX = point.x + fontTitle.dimensao.h;
    pY = point.y + (fontTitle.dimensao.h * 1.5);

    textName.setPoint(pX, pY);

    pX = point.x + dimension.w - textScore.getDimension().w - fontTitle.dimensao.h;

    textScore.setPoint(pX, pY);
}

UIWindowRecord::UIWindowRecord()
{
    keyboard.setCaracter("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _+-$%*,.:[]!=");
    keyboard.addControl(0, "GBF_UIRecorde_button_back");
    keyboard.addControl(1, "GBF_UIRecorde_button_next");
    keyboard.addControl(2, "GBF_UIRecorde_button_save");

    textName.setLabel("GBF_UIRecorde_title_player");
    textName.maxLength(10);
    textName.showCursor(true);

    textScore.setLabel("GBF_UIRecorde_title_points");
    textScore.maxLength(8);

    nameIndex = 0;
    point.x = 0;
    point.y = 0;

    tempoEspera.setInitialTime(1);
    tempoEspera.setUnit(GBF::Kernel::Timer::TIME_SECOND_0100);
    tempoEspera.setReset();

    showErro = false;
}

/** Destrutor */
UIWindowRecord::~UIWindowRecord()
{
    delete(uiVisualComponentes);
}

/** Estilo Visual a ser Aplicado no Componente */
void UIWindowRecord::setVisualComponentes(UserInterface::Visual::UIVisualSolido * visual)
{
    uiVisualComponentes = visual;

    textName.setVisual(uiVisualComponentes);
    textScore.setVisual(uiVisualComponentes);
    keyboard.setVisual(uiVisualComponentes);

    keyboard.setColorCursor(255, 255, 0);
}

/** Define a fonte a ser usada pelo Titulo */
void UIWindowRecord::setFontTitle(std::string font)
{
    fontTitle.nome = font;
    fontTitle.dimensao = writeManager->getFont(fontTitle.nome)->getDimensao();

    int tamanho = writeManager->getLineWidth(fontTitle.nome, "GBF_UIRecorde_title");
    fontTitle.posicao.x = point.x + (dimension.w / 2) - (tamanho / 2);
    fontTitle.posicao.y = point.y;
}

void UIWindowRecord::setFontKeyboard(std::string keyFont, std::string controlFont)
{
    keyboard.setFontKey(keyFont);
    keyboard.setFontControl(controlFont);
}

void UIWindowRecord::setFontInput(std::string fontLabel, std::string fontValue)
{
    textName.setFont(fontLabel);
    textName.setFontInput(fontValue);

    textScore.setFont(fontLabel);
    textScore.setFontInput(fontValue);

    textScore.showCursor(false);

    fontNotice.nome = fontLabel;
}

/** Retorna o TopSystemRecorde */
RankingSystem::RSRecorde UIWindowRecord::getRecord()
{
    return record;
}

/** Atribui um RSRecorde para complementar os dados */
void UIWindowRecord::setRecord(RankingSystem::RSRecorde record)
{
    this->record  = record;
    nameIndex    = 0;
    tempoEspera.setReset();
}

/** Gerencia o controle do cursor (navegação) e as opções selecionadas */
bool UIWindowRecord::isAction(int action)
{
    bool salva = false;

    if (tempoEspera.isFinish()){
        if (confirmSelection() == action) {
            salva = true;
        }
    }

    return salva;
}

} // namespace UserInterface::Window

} // namespace UserInterface
