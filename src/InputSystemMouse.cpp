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

#include "InputSystemMouse.h"

//Destrutor
InputSystemMouse::~InputSystemMouse() 
{
    UtilLog::subSistema("Removendo InputSystemMouse");
    try {
        if (cursor){
        //delete (cursor);
        //Comentado por causar falha em ambiente Linux
        //motivo ainda desconhecido
        }
    } catch (...){
        //UtilLog::getInstance()->status("[Falhou]");
    }
    SDL_ShowCursor(SDL_ENABLE);
}
//Retorna a posição do mouse no eixo X
int InputSystemMouse::getX() 
{

	return ponto.x;
}
//Retorna a posição do mouse no eixo Y
int InputSystemMouse::getY() 
{
    return ponto.y;
}
//Retorna a posição do mouse
Ponto InputSystemMouse::getPosicao() 
{
    return ponto;
}
//Carrega o curso do mouse do arquivo
void InputSystemMouse::carregarArquivo(std::string arquivo) 
{
    //UtilLog::getInstance()->inicializando("\tCarregando Cursor");
    if (cursor->carregarArquivo(arquivo)){
        //UtilLog::getInstance()->status("[Ok]");
        setMouse(true);
    } else {
        //UtilLog::getInstance()->status("[Falhou]");
        setMouse(false);
    }
}
//Retorna o InputSystemMouseCursor para manipulação
InputSystemMouseCursor * InputSystemMouse::getMouseCursor() 
{
    return cursor;
}
//Configura se exibe ou não o cursor do mouse
void InputSystemMouse::setMouse(bool show) 
{
    mouse=show;
}
//Retorna se o ponteiro está ativo na tela
bool InputSystemMouse::isMouse() 
{
    return mouse;
}
//Verifica se o botão esquerdo foi pressionado
bool InputSystemMouse::isButtonLeft() 
{
    if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(MS_LEFT)){
        return true;
    } else {
        return false;
    }
}
//Verifica se o botão do meio foi pressionado
bool InputSystemMouse::isButtonMiddle() 
{
    if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(MS_MIDDLE)){
        return true;
    } else {
        return false;
    }
}
//Verifica se o botão direito foi pressionado
bool InputSystemMouse::isButtonRight() 
{
    if (SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(MS_RIGHT)){
        return true;
    } else {
        return false;
    }
}
//Verifica se a combinação de botões foi pressionada
bool InputSystemMouse::isButton(bool left, bool middle, bool right) 
{
    bool e,m,d;

    e=isButtonLeft();

    if (left==e){
        e=true;
    } else {
        e=false;
    }

    m=isButtonMiddle();

    if (middle==m){
        m=true;
    } else {
        m=false;
    }

    d=isButtonRight();

    if (right==d){
        d=true;
    } else {
        d=false;
    }

    return (e&&m&&d);
}
//Construtor
InputSystemMouse::InputSystemMouse() 
{
    UtilLog::subSistema("Instanciando InputSystemMouse");
    SDL_ShowCursor(SDL_DISABLE);
    setMouse(false);
    cursor = new InputSystemMouseCursor();
}
//Processa os eventos do mouse
void InputSystemMouse::processar() 
{
    SDL_GetMouseState(&ponto.x, &ponto.y);

    if ((isMouse())&&(cursor!=NULL)){
        cursor->desenhar(ponto.x,ponto.y);
    }
}
