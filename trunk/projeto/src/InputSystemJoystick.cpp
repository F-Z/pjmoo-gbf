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

#include "InputSystemJoystick.h"

//Destrutor
InputSystemJoystick::~InputSystemJoystick() 
{
  
      UtilLog::subSistema("Removendo InputSystemJoystick");
  	SDL_JoystickClose(joystick);
  
  	/*Finaliza o subsistema de joystick*/
  	SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
  	
  	joystick=NULL;
}

//Retorna se o direcional foi movido para o lado esquerdo
bool InputSystemJoystick::isAxeLeft() 
{
  
  	if ((joystick)&&(axe_horizontal==AXE_LEFT)){
  		return true;
  	} else {
  		return false;
  	}
}

//Retorna se o direcional foi movido para o lado direito
bool InputSystemJoystick::isAxeRight() 
{
  
  	if ((joystick)&&(axe_horizontal==AXE_RIGHT)){
  		return true;
  	} else {
  		return false;
  	}
}

//* Retorna se o direcional foi movido para cima 
bool InputSystemJoystick::isAxeUp() {

	if ((joystick)&&(axe_vertical==AXE_UP)){
		return true;
	} else {
		return false;
	}
}

//Retorna se o direcional foi movido para baixo
bool InputSystemJoystick::isAxeDown() 
{
  
  	if ((joystick)&&(axe_vertical==AXE_DOWN)){
  		return true;
  	} else {
  		return false;
  	}
}

//Retorna se o botão A foi pressionado
bool InputSystemJoystick::isButtonA() 
{
  
  	if ((joystick)&&(SDL_JoystickGetButton(joystick,JB_A))){
  		return true;
  	} else {
  		return false;
  	}
}

//Retorna se o botão B foi pressionado
bool InputSystemJoystick::isButtonB() 
{
  
  	if ((joystick)&&(SDL_JoystickGetButton(joystick,JB_B))){
  		return true;
  	} else {
  		return false;
  	}
}

//Retorna se o botão C foi pressionado (caso exista)
bool InputSystemJoystick::isButtonC() 
{
  
  	if ((joystick)&&(SDL_JoystickGetButton(joystick,JB_C))){
  		return true;
  	} else {
  		return false;
  	}
}

//Retorna se o botão D foi pressionado (caso exista)
bool InputSystemJoystick::isButtonD() 
{
  
  	if ((joystick)&&(SDL_JoystickGetButton(joystick,JB_D))){
  		return true;
  	} else {
  		return false;
  	}
}

//Construtor
InputSystemJoystick::InputSystemJoystick() 
{
  
      UtilLog::subSistema("Instanciando InputSystemJoystick");
  	joystick=NULL;
  
  	if (SDL_InitSubSystem(SDL_INIT_JOYSTICK)>=0){
  		if (SDL_JoystickEventState(SDL_ENABLE)==SDL_ENABLE){
  			if ((joystick = SDL_JoystickOpen(0))!=NULL){
  				UtilLog::comentario("Descrição=%s  ",SDL_JoystickName(0));
  			} else {
  				UtilLog::comentario("[Falhou] SDL_JoystickOpen(0)=%s",SDL_GetError());
  			}
  		} else {
  			UtilLog::comentario("[Falhou] SDL_JoystickEventState(SDL_ENABLE)=%s",SDL_GetError());
  		}
  	} else {
  		UtilLog::comentario("[Falhou] SDL_InitSubSystem(SDL_INIT_JOYSTICK)=%s",SDL_GetError());
  	}
}

//Processa os eventos do joystick
void InputSystemJoystick::processar() 
{
  
  	int x=0,y=0;
  	axe_horizontal=AXE_STOP;
  	axe_vertical  =AXE_STOP;
  
  	if (joystick){
  		x=SDL_JoystickGetAxis(joystick,0);
  		y=SDL_JoystickGetAxis(joystick,1);
  
  		if (x>20768){
  			axe_horizontal=AXE_RIGHT;
  		} else if (x<-20768){
  			axe_horizontal=AXE_LEFT;
  		}
  
  		if (y>20768){
  			axe_vertical=AXE_DOWN;
  		} else if (y<-20768){
  			axe_vertical=AXE_UP;
  		}
  	}
}

//Limpa o estado das teclas
//Obs.: Não funciona (não use)
void InputSystemJoystick::limparEstado() 
{
  
  //não funciona
}

