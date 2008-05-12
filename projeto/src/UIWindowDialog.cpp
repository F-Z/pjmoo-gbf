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

namespace UserInterface {

namespace Window {

const int UIWindowDialog::BOTAO_OK=100;

UIWindowDialog::UIWindowDialog() 
{
    botao = NULL;
}
UIWindowDialog::~UIWindowDialog() 
{
    if (botao){
        delete(botao);
    }
}
void UIWindowDialog::adicionarBotao(UserInterface::Componente::UIBotao * novoBotao) 
{
    botao=novoBotao;
}
//Retorna se a ação informada foi acionado
bool UIWindowDialog::isAcao(int tipoAcao) 
{
    if (confirmarSelecao()==tipoAcao){
        return true;
    } else {
        return false;
    }
}
int UIWindowDialog::confirmarSelecao() 
{
    int selecionado = -1;

    if (((botao==NULL)
        ||(((inputSystem->teclado->isKey(botao->getTecla()))||(inputSystem->joystick->isButtonA()))))
        &&(tempoEspera.isTerminou())){
        tempoEspera.setResetar();
        selecionado=BOTAO_OK;
    }

    return selecionado;
}
//Inicializa as configurações da caixa de texto

//Inicializa as configurações da caixa de texto
void UIWindowDialog::inicializar() 
{
    UIWindow::inicializar();
    texto.setDimensaoLetra(wsManager->getFonte(texto.getFonte())->getDimensao());
}
//Desenha o conteudo da janela

//Desenha o conteudo da janela
void UIWindowDialog::desenharConteudo() 
{
    int numeroLinha=1;
    bool continuar = false;
    char textoChave[30];

    int posicaoTextoVertical   = posicao.y+espacoAntesTexto;
    int posicaoTextoHorizontal = 0;
    int auxiliar=0;

    do {
        sprintf(textoChave,texto.getChaveTexto().c_str(),numeroLinha);

        continuar=uiTexto->isChaveTexto(textoChave);

        if (continuar){

            if (texto.getAlinhamento()==Texto::TEXTO_CENTRALIZADO){
                auxiliar = wsManager->getLarguraLinha(texto.getFonte(),textoChave);
                posicaoTextoHorizontal=int (posicao.x+(dimensao.w/2)-(auxiliar/2));
            } else {
                posicaoTextoHorizontal = posicao.x+texto.getDimensaoLetra().w;
            }

            wsManager->escreverLocalizado(texto.getFonte(),posicaoTextoHorizontal,posicaoTextoVertical,textoChave);
            posicaoTextoVertical=posicao.y+espacoAntesTexto+(texto.getEspacoEntreLinhas()*numeroLinha);
            numeroLinha++;

        } else {
            break;
        }

    } while(true);
}
//Desenha a camada de decoração da janela (botões)
void UIWindowDialog::desenharForeground() 
{
    if ((botao!=NULL)&&(tempoEspera.isTerminou())){
        botao->executar();
    }
}
//atualiza as informações do componente (posicao, dimensao, estado)
void UIWindowDialog::atualizar() 
{
    tempoEspera.processar();

    if (botao!=NULL){
        Ponto pontoAux = posicao;
        Dimensao d= botao->getDimensao();
        pontoAux.x = (posicao.x+dimensao.w)-d.w;
        pontoAux.y = (posicao.y+dimensao.h)-d.h;
        botao->setPosicao(pontoAux.x,pontoAux.y);
    }
}

} // namespace UserInterface::Window

} // namespace UserInterface
