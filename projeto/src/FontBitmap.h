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
#ifndef _FONTBITMAP_H
#define _FONTBITMAP_H

#include "ImageBase.h"
#include <string>

#include "GBF.h"

namespace GBF {

namespace Kernel {

namespace Write {

/**
 * Classe que representa fontes originadas de imagens (Font Bitmap).
 * Permitir a personaliza��o dos textos na tela por meio de fontes contidas em imagens
 */
class FontBitmap : public GBF::Kernel::Graphic::ImageBase {
    public:
        /**
         * Destrutor
         */
        virtual ~FontBitmap();

        /**
         * Carrega arquivo de imagem contendo o desenho das letras.
         * Se a imagem tiver arquivo de dimens�o das letras este ser� carregado,
         * caso contrario ser� utilizado um valor default tanto para largura como altura
         */
        virtual bool loadFromFile(std::string fileName);

        /** Configura altura e largura padr�o para todas as letras.
         * A altura e largura devem ser suficientes para evitar que a letra seja desenhada
         * cortada
         */
        void setDimension(int width, int height);

        /**
         * Retorna a largura padr�o
         */
        int getWidth();

        /**
         * Retorna a altura padr�o
         */
        int getHeight();

        /**
         * Retorna a dimens�o (altura e largura) padr�o
         */
        GBF::Dimension getDimension();


    protected:
        /**
         * Desenha o texto na tela
         */
        void write(const char * words, int x, int y);

        /**
         * Retorna em pixel o tamanho da linha
         */
        int getLineWidth(const char * words);

        /**
         * Converte Surface para formato na inicializa��o do GraphicSystem
         */
        virtual void convertSurface();

        friend class WriteManager;

    private:
        char largura[256];

        GBF::Dimension dimensaoPadrao;

        GBF::Dimension dimensaoQuadro;

        /**
         * Construtor
         */
        FontBitmap();

        /**
         * Define altura e largura padr�o baseada na maior altura e largura utilizada.
         */
        void calculateSize();

};

} // namespace GBF::Kernel::Write

} // namespace GBF::Kernel

} // namespace GBF

#endif
