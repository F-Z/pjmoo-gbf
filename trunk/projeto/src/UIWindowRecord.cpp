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

#include "UIWindowRecord.h"

namespace UserInterface {

namespace Window {

void UIWindowRecord::update()
{
    tempoEspera.processar();

    textName.setValue(record.nome);
    textScore.setValue(record.pontos);
}

//Desenha o botão de ação da janela

//Desenha o botão de ação da janela
void UIWindowRecord::desenharForeground()
{
    if (showErro){
        writeManager->escreverLocalizado(fontNotice.nome, fontNotice.posicao.x, fontNotice.posicao.y, "GBF_UIRecorde_warning");
    }
}

//Desenha o conteudo da janela

//Desenha o conteudo da janela
void UIWindowRecord::desenharConteudo()
{
    //escrevendo titulo centralizado
    writeManager->escreverLocalizado(fontTitle.nome, fontTitle.posicao.x, fontTitle.posicao.y, "GBF_UIRecorde_title");

    keyboard.execute();
    textName.execute();
    textScore.execute();
}

//Efetua as ações de acordo com a posição do cursor

//Efetua as ações de acordo com a posição do cursor
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

        tempoEspera.setResetar();
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

//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindowRecord::inicializar()
{
    UIWindow::inicializar();

    GBF::Dimensao d = keyboard.getDimension();

    int pX = (position.x + dimension.w) / 2 - (d.w / 2);
    int pY = (position.y + dimension.h) / 2;

    keyboard.setPosition(pX, pY);


    pY = pY + keyboard.getDimension().h;
    fontNotice.posicao.x = pX;
    fontNotice.posicao.y = pY;

    pX = position.x + fontTitle.dimensao.h;
    pY = position.y + (fontTitle.dimensao.h * 1.5);

    textName.setPosition(pX, pY);

    pX = position.x + dimension.w - textScore.getDimension().w - fontTitle.dimensao.h;

    textScore.setPosition(pX, pY);
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
    position.x = 0;
    position.y = 0;

    tempoEspera.setTempoOriginal(1);
    tempoEspera.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    tempoEspera.setResetar();

    showErro = false;
}

//Destrutor
UIWindowRecord::~UIWindowRecord(){
    delete(uiVisualComponentes);
}

//Estilo Visual a ser Aplicado no Componente

//Estilo Visual a ser Aplicado no Componente
void UIWindowRecord::setVisualComponentes(UserInterface::Visual::UIVisualSolido * visual)
{
    uiVisualComponentes = visual;

    textName.setVisual(uiVisualComponentes);
    textScore.setVisual(uiVisualComponentes);
    keyboard.setVisual(uiVisualComponentes);

    keyboard.setColorCursor(255, 255, 0);
}

//Define a fonte a ser usada pelo Titulo
void UIWindowRecord::setFontTitle(std::string font)
{
    fontTitle.nome = font;
    fontTitle.dimensao = writeManager->getFonte(fontTitle.nome)->getDimensao();

    int tamanho = writeManager->getLarguraLinha(fontTitle.nome, "GBF_UIRecorde_title");
    fontTitle.posicao.x = position.x + (dimension.w / 2) - (tamanho / 2);
    fontTitle.posicao.y = position.y;
}

void UIWindowRecord::setFontKeyboard(std::string keyFont, std::string controlFont)
{
    keyboard.setFontKey(keyFont);
    keyboard.setFontControl(controlFont);
}

void UIWindowRecord::setFontEdition(std::string fontLabel, std::string fontValue)
{
    textName.setFonteLabel(fontLabel);
    textName.setFonteCampo(fontValue);

    textScore.setFonteLabel(fontLabel);
    textScore.setFonteCampo(fontValue);

    textScore.showCursor(false);

    fontNotice.nome = fontLabel;
}

//Retorna o TopSystemRecorde
RankingSystem::RSRecorde UIWindowRecord::getRecord()
{
    return record;
}

//Atribui um TopSystemRecorde para complementar os dados

//Atribui um RSRecorde para complementar os dados
void UIWindowRecord::setRecord(RankingSystem::RSRecorde record)
{
    this->record  = record;
    nameIndex    = 0;
    tempoEspera.setResetar();
}

//Gerencia o controle do cursor (navegação) e as opções selecionadas

//Gerencia o controle do cursor (navegação) e as opções selecionadas
bool UIWindowRecord::isAction(int action)
{
    bool salva = false;

    if (tempoEspera.isTerminou()){
        if (confirmSelection() == action)
        {
            salva = true;
        }
    }

    return salva;
}

} // namespace UserInterface::Window

} // namespace UserInterface
