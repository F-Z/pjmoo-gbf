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

#include "Cursor.h"

namespace GBF {

namespace Kernel {

namespace Input {

//Destrutor
Cursor::~Cursor() 
{
      //UtilLog::subSistema("Removendo InputSystemMouseCursor");
}

//Carregar arquivo contendo a imagem do ponteiro
bool Cursor::carregarArquivo(std::string arquivo) 
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
void Cursor::desenhar(int x, int y) 
{
  
  	posicao.x=x - ponto.x;	posicao.y=y - ponto.y;
  	if (imagem){
  		gsScreen->blitSurface(imagem,NULL,&posicao);
  	}
}

//Construtor
Cursor::Cursor() 
{
  //UtilLog::subSistema("Instanciando InputSystemMouseCursor");
}


} // namespace GBF::Kernel::Input

} // namespace GBF::Kernel

} // namespace GBF
