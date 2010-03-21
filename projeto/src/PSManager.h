/* GBFramework - Gamework's Brazilian Framework
 *  Copyright (C) 2004-2010 - David de Almeida Ferreira
 *  < http://www.dukitan.com > - < davidferreira.fz@gmail.com >
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  < http://pjmoo.sourceforge.net >  < http://pjmoo-gbf.googlecode.com >
**************************************************************************/

#ifndef _PSMANAGER_H
#define _PSMANAGER_H

#include "PSEffect.h"
#include <deque>
#include "BaseManager.h"

namespace ParticleSystem {

/** Classe para gerenciamento do sistema de  particulas.
    Gerenciar o uso de vários sistemas de particulas */
class PSManager : public GBF::BaseManager
{
    public:
        /** Destrutor */
        ~PSManager();

        /** Adiciona um Sistema de Particulas */
        void add(PSEffect * efeito);

        /** Desenha objetos que estao no container */
        void draw();

        /** Atualiza o Sistema */
        void update();

        /** Retorna a quantidade de elementos */
        int size();

        /** Limpa o gerenciador, removendo todos os elementos */
        void clear();

        /** Pega uma Instância de ParticleSystemManager */
        static PSManager * getInstance();

    protected:
        static PSManager * instance;

        std::deque<PSEffect*> lista;
        /** Remove os sistemas de particulas já finalizados */
        void remove();

    private:
        /** Construtor */
        PSManager();
};

} // namespace ParticleSystem
#endif
