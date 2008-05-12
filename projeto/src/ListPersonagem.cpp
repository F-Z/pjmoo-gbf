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

#include "ListPersonagem.h"

namespace Personagem {

//Construtor 
ListPersonagem::ListPersonagem() 
{

}
//Destrutor 
ListPersonagem::~ListPersonagem() 
{

    limpar();
}
//Desenha objetos que estao no container
void ListPersonagem::desenhar() 
{
    if (!lista.empty()){
        for (unsigned int t=0; t<lista.size(); t++){
            if (lista[t]){
                lista[t]->desenhar();
            }
        }
    }
}
//Retorna a quantidade de elementos 
int ListPersonagem::size() 
{
    return lista.size();
}
//Limpa o container, removendo todos os elementos
void ListPersonagem::limpar() 
{
    for (unsigned int i=0; i<lista.size(); i++){
        try {
            if (lista[i]){
                delete lista[i];
                lista[i]=NULL;
            }
        } catch (...){
        }
    }
    lista.clear();
}
//Executa as ações de cada elemento 
void ListPersonagem::acao(GBF::Kernel::Input::InputSystem * input) 
{
    if (!lista.empty()){
        for (unsigned int t=0; t<lista.size(); t++){
            if (lista[t]!=NULL){
                lista[t]->acao(input);
            }
        }
    }
}
void ListPersonagem::adicionar(Personagem * personagem) 
{
    lista.push_back(personagem);
}
void ListPersonagem::remover(Personagem * personagem) 
{
    for (int i=lista.size()-1; i>=0; i--){
        if (lista[i]==personagem){
            delete lista[i];
            lista[i]=NULL;
            lista.erase(lista.begin()+i);
        }
    }
}
void ListPersonagem::colisao(ListPersonagem * objeto) 
{
    Personagem *l=NULL;
    Personagem *o=NULL;

    for (int i=0; i<size(); i++){
        if (((l=getPersonagem(i))!=NULL)&&(l->isVivo())){
            for (int ob=0; ob<objeto->size(); ob++){
                if (((o=objeto->getPersonagem(ob))!=NULL)&&(o->isVivo())){
                    if (l->isColisao(o)){
                        l->setVivo(false);
                        o->setVivo(false);
                        break;
                    }
                }
            }
        }
    }
}
void ListPersonagem::colisao(Personagem * objeto) 
{
    Personagem *l=NULL;

    for (int i=0; i<size(); i++){
        if((l=getPersonagem(i))!=NULL){
            if ((l->isVivo())&&(objeto!=NULL)){
                if ((objeto->isVivo())&&(l->isColisao(objeto))){
                    l->setVivo(false);
                    objeto->setVivo(false);
                    break;
                }
            }
        }
    }
}
Personagem * ListPersonagem::getPersonagem(int indice) 
{
    return lista[indice];
}
void ListPersonagem::ordenar() 
{
    Personagem *buffer;

    for (unsigned int t=0; t<lista.size()-1; t++){
        if ((lista[t]!=NULL) && (lista[t+1]!=NULL)){
            if (lista[t]->posicao.y>lista[t+1]->posicao.y){
                buffer=lista[t+1];
                lista.erase(lista.begin()+(t+1));
                lista.insert(lista.begin(),buffer);
            }
        }
    }
}

} // namespace Personagem
