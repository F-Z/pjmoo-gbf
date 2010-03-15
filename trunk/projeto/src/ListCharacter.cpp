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

#include "ListCharacter.h"

namespace Character {

//Construtor
ListCharacter::ListCharacter()
{

}
//Destrutor
ListCharacter::~ListCharacter()
{

    limpar();
}
//Desenha objetos que estao no container
void ListCharacter::desenhar()
{
    if (!list.empty()){
        for (unsigned int t=0; t<list.size(); t++){
            if (list[t]){
                list[t]->desenhar();
            }
        }
    }
}
//Retorna a quantidade de elementos
int ListCharacter::size()
{
    return list.size();
}
//Limpa o container, removendo todos os elementos
void ListCharacter::limpar()
{
    for (unsigned int i=0; i<list.size(); i++){
        try {
            if (list[i]){
                delete list[i];
                list[i]=NULL;
            }
        } catch (...){
        }
    }
    list.clear();
}
//Executa as ações de cada elemento
void ListCharacter::acao(GBF::Kernel::Input::InputSystem * input)
{
    if (!list.empty()){
        for (unsigned int t=0; t<list.size(); t++){
            if (list[t]!=NULL){
                list[t]->acao(input);
            }
        }
    }
}
void ListCharacter::add(Character * character)
{
    list.push_back(character);
}
void ListCharacter::remove(Character * character)
{
    for (int i=list.size()-1; i>=0; i--){
        if (list[i]==character){
            delete list[i];
            list[i]=NULL;
            list.erase(list.begin()+i);
        }
    }
}
void ListCharacter::collision(ListCharacter * listCharacter)
{
    Character *l=NULL;
    Character *o=NULL;

    for (int i=0; i<size(); i++){
        if (((l=getCharacter(i))!=NULL)&&(l->isLife())){
            for (int ob=0; ob<listCharacter->size(); ob++){
                if (((o=listCharacter->getCharacter(ob))!=NULL)&&(o->isActive())){
                    if (l->isCollision(o)){
                        l->setLife(false);
                        o->setLife(false);
                        break;
                    }
                }
            }
        }
    }
}
void ListCharacter::collision(Character * character)
{
    Character *l=NULL;

    for (int i=0; i<size(); i++){
        if((l=getCharacter(i))!=NULL){
            if ((l->isActive())&&(character!=NULL)){
                if ((character->isActive())&&(l->isCollision(character))){
                    l->setLife(false);
                    character->setLife(false);
                    break;
                }
            }
        }
    }
}
Character * ListCharacter::getCharacter(int index)
{
    return list[index];
}
void ListCharacter::ordenar()
{
    Character *buffer;

    for (unsigned int t=0; t<list.size()-1; t++){
        if ((list[t]!=NULL) && (list[t+1]!=NULL)){
            if (list[t]->point.y>list[t+1]->point.y){
                buffer=list[t+1];
                list.erase(list.begin()+(t+1));
                list.insert(list.begin(),buffer);
            }
        }
    }
}

} // namespace Character
