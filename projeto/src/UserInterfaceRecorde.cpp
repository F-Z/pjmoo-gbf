////    GBF - Gamework's Brazilian Framework
////    Copyright (C) 2004-2007 David de Almeida Ferreira
////
////    This library is free software; you can redistribute it and/or
////    modify it under the terms of the GNU Library General Public
////    License as published by the Free Software Foundation; either
////    version 2 of the License, or (at your option) any later version.
////
////    David de Almeida Ferreira (F-Z)
////        davidferreira@uol.com.br or davidferreira.fz@gmail.com
////        http://pjmoo.codigolivre.org.br
////////////////////////////////////////////////////////////////////////

#include "UserInterfaceRecorde.h"

//Construtor
UserInterfaceRecorde::UserInterfaceRecorde()
{
    //Para não esquecer:
    //As Soluções mais simples, são as que melhor funcionam :P
    strcpy(miniTeclado,"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 _+-$%*,.:[]!=");


    tecladoControle[0]="BACK";
    tecladoControle[1]="NEXT";
    tecladoControle[2]="SAVE";


    totalTeclasTeclado  = strlen(miniTeclado);
    totalTeclasControle = 3;

    tamanhoMaiorTeclaControle  = 0;
    for (unsigned int i=0; i<totalTeclasControle;i++){
        if (tecladoControle[i].length()>tamanhoMaiorTeclaControle){
            tamanhoMaiorTeclaControle=tecladoControle[i].length();
        }
    }

    totalTeclas    = totalTeclasTeclado+totalTeclasControle;
    nomePosicao    = 0;
    tecladoSelecao = 0;
    posicao.x      = 0;
    posicao.y      = 0;

    fonteTeclado  = "";
    fonteLabel    = "";

    tempoNavegacao.setTempoOriginal(1);
    tempoNavegacao.setUnidade(TEMPO_CENTESIMO);
    tempoNavegacao.setResetar();

    tempoBlink.setTempoOriginal(0);
    tempoBlink.setUnidade(TEMPO_CENTESIMO);
    tempoBlink.setResetar();
}
//Destrutor
UserInterfaceRecorde::~UserInterfaceRecorde()
{
//não implementado
}
//Define a fonte a ser usada pelo teclado virtual
void UserInterfaceRecorde::setFonteTeclado(std::string fonte)
{
    fonteTeclado=fonte;
    dimensaoFonteTeclado=wsManager->getFonte(fonteTeclado)->getDimensao();

    caixaTeclado.w=474;
    caixaTeclado.h=(dimensaoFonteTeclado.h + int(dimensaoFonteTeclado.h/4))*int(totalTeclasTeclado/10);
}
//Define a posição da Interface de recordes
void UserInterfaceRecorde::setPosicao(int x, int y)
{
    posicao.x=x;
    posicao.y=y;
}
//Define a fonte a ser usada pelo label
void UserInterfaceRecorde::setFonteLabel(std::string fonte)
{
    fonteLabel=fonte;
    dimensaoFonteLabel=wsManager->getFonte(fonteLabel)->getDimensao();
}
//Adiciona referência para o Sistema Gráfico GFX
void UserInterfaceRecorde::setGFX(GraphicSystemGFX * gfx)
{
    gsGFX=gfx;
}
//Adiciona referência para o Sistema de Escrita
void UserInterfaceRecorde::setWriteManager(WriteSystemManager * write)
{
    this->wsManager=write;
}
//Retorna o TopSystemRecorde
TopSystemRecorde UserInterfaceRecorde::getRecorde()
{
    return recorde;
}
//Atribui um TopSystemRecorde para complementar os dados
void UserInterfaceRecorde::setRecorde(TopSystemRecorde recorde)
{
    this->recorde  = recorde;
    nomePosicao    = 0;
    tecladoSelecao = 0;
    tempoBlink.setResetar();
    tempoNavegacao.setResetar();
}
//Gerencia o controle do cursor (navegação) e as opções selecionadas
bool UserInterfaceRecorde::controle()
{
    bool salva = false;
    tempoNavegacao.processar();
    tempoBlink.processar();
    if (tempoNavegacao.isTerminou()){
        navegar();
        salva = confirmar();
    }
    return salva;
}
//Desenha a interface contendo: pontuação, dados do jogador e teclado virtual
void UserInterfaceRecorde::desenhar()
{
    desenharCaixa();
    desenharDados();
    desenharMiniTeclado();
}
//Efetua as ações de acordo com a posição do cursor
bool UserInterfaceRecorde::confirmar()
{
    bool salva = false;
    if ((inputSystem->teclado->isKey(SDLK_RETURN)) || (inputSystem->joystick->isButtonA())){
        if ((tecladoSelecao>=0)&&(tecladoSelecao<totalTeclasTeclado)){
            recorde.nome[nomePosicao]=miniTeclado[tecladoSelecao];
            nomePosicao++;
        } else if (tecladoSelecao==totalTeclasTeclado){//controle voltar
            nomePosicao--;
        } else if (tecladoSelecao==totalTeclasTeclado+1){//controle avancar
            nomePosicao++;
        } else if (tecladoSelecao==totalTeclasTeclado+2){//controle salvar
            if (recorde.nome[0]!=' '){
                salva=true;
            }
        }
        tempoNavegacao.setResetar();
    }

    if (nomePosicao<0){
        nomePosicao=0;
    } else if (nomePosicao>9){
        nomePosicao=9;
    }

    return salva;
}
//Desenha as caixas de fundo para posicionamento dos dados do jogador e do teclado virtual
void UserInterfaceRecorde::desenharCaixa()
{
    if (tempoBlink.getTempo()%2!=0){
        gsGFX->setColor(250,250,250);
        gsGFX->retanguloPreenchido(posicao.x+20+(24*nomePosicao),posicao.y-28,dimensaoFonteTeclado.w,2);
    }

    gsGFX->setColor(0,0,0);
    gsGFX->retanguloPreenchido(posicao.x,posicao.y,caixaTeclado.w,caixaTeclado.h);
    gsGFX->setColor(206,101,99);
    gsGFX->retangulo(posicao.x,posicao.y,caixaTeclado.w,caixaTeclado.h);
}
//Desenha o teclado virtual
void UserInterfaceRecorde::desenharMiniTeclado()
{
    gsGFX->setColor(255,255,0);
    int letra=0;
    int espacoHorizontal = dimensaoFonteTeclado.w + int(dimensaoFonteTeclado.w / 4);
    int espacoVertical   = dimensaoFonteTeclado.h + int(dimensaoFonteTeclado.h / 4);

    //Painel do teclado
    for (int l=0;l<5;l++){
        for (int c=0;c<10;c++){
            wsManager->escrever(fonteTeclado, posicao.x+(10)+(espacoHorizontal*c),posicao.y+(espacoVertical*l),"%c",miniTeclado[letra]);
            //Desenhando cursor da selecao de tecla
            if ((tecladoSelecao==letra)&&(tempoBlink.getTempo()%2==0)){                 gsGFX->retangulo(posicao.x+8+(espacoHorizontal*c),posicao.y+3+(espacoVertical*l),dimensaoFonteTeclado.w,dimensaoFonteTeclado.h);
            }
            letra++;
        }
    }
    //variaveis temporarias, usadas para calcular a posicao dos itens de controle
    int ajuste      = 10;
    int aux = (posicao.y+caixaTeclado.h)-(totalTeclasControle * dimensaoFonteLabel.w) - ajuste;
    int compensando = 0;
    //Painel das teclas de controles
    for (int ic=totalTeclasControle-1;ic>=0;ic--){
        compensando = int(((tamanhoMaiorTeclaControle-tecladoControle[ic].length())*dimensaoFonteLabel.h)/2);
    	wsManager->escrever(fonteLabel, posicao.x+340+compensando,(aux)+(dimensaoFonteLabel.w*ic),tecladoControle[ic].c_str());
    }
    //Desenhando cursor das teclas de controle
    if (tempoBlink.getTempo()%2==0){
        if (tecladoSelecao>=totalTeclasTeclado){
            int t=tecladoSelecao-totalTeclasTeclado;
            compensando=int(dimensaoFonteLabel.w/2);
            gsGFX->retangulo(posicao.x+338-compensando,(aux+6)+(dimensaoFonteLabel.w*t),(tamanhoMaiorTeclaControle+1)*dimensaoFonteLabel.w,dimensaoFonteLabel.h);
        }
    }
}
//Desenha o nome do jogador e sua pontuação
void UserInterfaceRecorde::desenharDados()
{
    wsManager->escrever(fonteTeclado, posicao.x+20 , posicao.y-50,"%s"  ,recorde.nome);
    wsManager->escrever(fonteTeclado, posicao.x+270, posicao.y-50,"%08d",recorde.pontos);
}
//Efetua o controle sobre a navegação do cursor
void UserInterfaceRecorde::navegar()
{
    if ((inputSystem->teclado->isKey(SDLK_LEFT))||(inputSystem->joystick->isAxeLeft())){
            tecladoSelecao--;
            tempoNavegacao.setResetar();
    } else if ((inputSystem->teclado->isKey(SDLK_RIGHT))||(inputSystem->joystick->isAxeRight())){
            tecladoSelecao++;
            tempoNavegacao.setResetar();
    } else if ((inputSystem->teclado->isKey(SDLK_DOWN))||(inputSystem->joystick->isAxeDown())){
            if (tecladoSelecao<40){
                tecladoSelecao+=10;
            } else {//if (tecladoSelecao>=totalTeclasTeclado){
                tecladoSelecao++;
            }
            tempoNavegacao.setResetar();
    } else if ((inputSystem->teclado->isKey(SDLK_UP))||(inputSystem->joystick->isAxeUp())){
            if ((tecladoSelecao>=10)&&(tecladoSelecao<totalTeclasTeclado)){
                tecladoSelecao-=10;
            } else {
                tecladoSelecao--;
            }
            tempoNavegacao.setResetar();
    }

    if (tecladoSelecao<0){
        tecladoSelecao=0;
    } else if (tecladoSelecao>totalTeclas-1){
        tecladoSelecao=totalTeclas-1;
    }
}
