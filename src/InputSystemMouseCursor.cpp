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

#include "InputSystemMouseCursor.h"

//Destrutor
InputSystemMouseCursor::~InputSystemMouseCursor() 
{
  
      UtilLog::subSistema("Removendo InputSystemMouseCursor");
}

//Carregar arquivo contendo a imagem do ponteiro
bool InputSystemMouseCursor::carregarArquivo(std::string arquivo) 
{
  
  	if (imagem){
  		SDL_FreeSurface(imagem);
  	}
  	imagem = IMG_Load(arquivo.c_str());
  	
  	if (imagem){
  		converterSurface();
  		setColorKey(255, 0, 255);  
  		ponto.y=0;
  		ponto.x=0;
  		return true;
  	} else {
  		return false;
  	}
}

//Desenha o ponteiro na tela
void InputSystemMouseCursor::desenhar(int x, int y) 
{
  
  	posicao.x=x - ponto.x;	posicao.y=y - ponto.y;
  	if (imagem){
  		gsScreen->blitSurface(imagem,NULL,&posicao);
  	}
}

//Construtor
InputSystemMouseCursor::InputSystemMouseCursor() 
{
  
      UtilLog::subSistema("Instanciando InputSystemMouseCursor");
}

