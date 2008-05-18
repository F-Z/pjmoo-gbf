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

#include "UIWindowRecorde.h"

namespace UserInterface {

namespace Window {

void UIWindowRecorde::atualizar() 
{
    tempoEspera.processar();

    textNome.setValue(recorde.nome);
    textPonto.setValue(recorde.pontos);
}
//Desenha o botão de ação da janela

//Desenha o botão de ação da janela
void UIWindowRecorde::desenharForeground() 
{
    if (showErro){
        wsManager->escreverLocalizado(fonteAviso.nome, fonteAviso.posicao.x,fonteAviso.posicao.y,"GBF_UIRecorde_warning");
    }
}
//Desenha o conteudo da janela

//Desenha o conteudo da janela
void UIWindowRecorde::desenharConteudo() 
{
    //escrevendo titulo centralizado
    wsManager->escreverLocalizado(fonteTitulo.nome,fonteTitulo.posicao.x,fonteTitulo.posicao.y,"GBF_UIRecorde_title");

    teclado.executar();
    textNome.executar();
    textPonto.executar();
}
//Efetua as ações de acordo com a posição do cursor

//Efetua as ações de acordo com a posição do cursor
int UIWindowRecorde::confirmarSelecao() 
{
    int opcao = false;
    if ((inputSystem->teclado->isKey(SDLK_RETURN)) || (inputSystem->joystick->isButtonA())){

        showErro=false;

        int selecao = teclado.getIndex();

        if ((selecao>=0)&&(selecao<teclado.getTotalCaracter())){
            recorde.nome[nomePosicao]=teclado.getCaracter();
            nomePosicao++;
        } else if (selecao==teclado.getTotalCaracter()){//controle voltar
            nomePosicao--;
        } else if (selecao==teclado.getTotalCaracter()+1){//controle avancar
            nomePosicao++;
        } else if (selecao==teclado.getTotalCaracter()+2){//controle salvar
            //if (recorde.nome[0]!=' '){
            if (strlen(recorde.nome)>1){
                opcao=BOTAO_SALVAR;
            } else {
                showErro=true;
            }
        }
        tempoEspera.setResetar();
    }

    if (nomePosicao<0){
        nomePosicao=0;
    } else if (nomePosicao>9){
        nomePosicao=9;
    }

    textNome.setCursorPosicao(nomePosicao);

    return opcao;
}
const int UIWindowRecorde::BOTAO_SALVAR=200;

//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindowRecorde::inicializar() 
{
    UIWindow::inicializar();

    GBF::Dimensao d = teclado.getDimensao();

    int pX=(posicao.x+dimensao.w)/2-(d.w/2);
    int pY=(posicao.y+dimensao.h)/2;

    teclado.setPosicao(pX,pY);


    pY=pY+teclado.getDimensao().h;
    fonteAviso.posicao.x=pX;
    fonteAviso.posicao.y=pY;

    pX=posicao.x+fonteTitulo.dimensao.h;
    pY=posicao.y+(fonteTitulo.dimensao.h*1.5);

    textNome.setPosicao(pX,pY);

    pX=posicao.x+dimensao.w - textPonto.getDimensao().w - fonteTitulo.dimensao.h;

    textPonto.setPosicao(pX,pY);
}
UIWindowRecorde::UIWindowRecorde() 
{
    teclado.setCaracter("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _+-$%*,.:[]!=");
    teclado.setControle(0,"GBF_UIRecorde_button_back");
    teclado.setControle(1,"GBF_UIRecorde_button_next");
    teclado.setControle(2,"GBF_UIRecorde_button_save");

    textNome.setLabel("GBF_UIRecorde_title_player");
    textNome.maxLength(10);
    textNome.showCursor(true);

    textPonto.setLabel("GBF_UIRecorde_title_points");
    textPonto.maxLength(8);

    nomePosicao     = 0;
    posicao.x       = 0;
    posicao.y       = 0;

    tempoEspera.setTempoOriginal(1);
    tempoEspera.setUnidade(GBF::Kernel::Timer::TEMPO_DECIMO);
    tempoEspera.setResetar();

    showErro = false;
}
//Destrutor
UIWindowRecorde::~UIWindowRecorde(){
    delete(uiVisualComponentes);
}

//Estilo Visual a ser Aplicado no Componente

//Estilo Visual a ser Aplicado no Componente
void UIWindowRecorde::setVisualComponentes(UserInterface::Visual::UIVisualSolido * visual) 
{
    uiVisualComponentes=visual;

    textNome.setVisual(uiVisualComponentes);
    textPonto.setVisual(uiVisualComponentes);
    teclado.setVisual(uiVisualComponentes);

    teclado.setCorCursor(255,255,0);
}
//Define a fonte a ser usada pelo Titulo
void UIWindowRecorde::setFonteTitulo(std::string fonte) 
{
    fonteTitulo.nome=fonte;
    fonteTitulo.dimensao=wsManager->getFonte(fonteTitulo.nome)->getDimensao();

    int tamanho = wsManager->getLarguraLinha(fonteTitulo.nome,"GBF_UIRecorde_title");
    fonteTitulo.posicao.x=posicao.x+(dimensao.w/2)-(tamanho/2);
    fonteTitulo.posicao.y=posicao.y;
}
void UIWindowRecorde::setFonteTecladoVirtual(std::string fonteTeclado, std::string fonteControle) 
{
    teclado.setFonteTeclado(fonteTeclado);
    teclado.setFonteControle(fonteControle);
}
void UIWindowRecorde::setFonteEdit(std::string fonteLabel, std::string fonteValue) 
{
    textNome.setFonteLabel(fonteLabel);
    textNome.setFonteCampo(fonteValue);

    textPonto.setFonteLabel(fonteLabel);
    textPonto.setFonteCampo(fonteValue);

    textPonto.showCursor(false);

    fonteAviso.nome=fonteLabel;
}
//Retorna o TopSystemRecorde
RankingSystem::RSRecorde UIWindowRecorde::getRecorde() 
{
    return recorde;
}
//Atribui um TopSystemRecorde para complementar os dados

//Atribui um RSRecorde para complementar os dados
void UIWindowRecorde::setRecorde(RankingSystem::RSRecorde recorde) 
{
    this->recorde  = recorde;
    nomePosicao    = 0;
    tempoEspera.setResetar();
}
//Gerencia o controle do cursor (navegação) e as opções selecionadas

//Gerencia o controle do cursor (navegação) e as opções selecionadas
bool UIWindowRecorde::isAcao(int tipoAcao) 
{
    bool salva = false;

    if (tempoEspera.isTerminou()){
        if(confirmarSelecao()==tipoAcao)
        {
            salva=true;
        }
    }

    return salva;
}

} // namespace UserInterface::Window

} // namespace UserInterface
