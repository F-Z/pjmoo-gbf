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

#ifndef _UIWINDOWRECORDE_H
#define _UIWINDOWRECORDE_H

#include "UserInterface.h"
#include "UITecladoVirtual.h"
#include "UITextField.h"
#include "UINumberField.h"
#include "RSRecorde.h"
#include "UIVisualSolido.h"
#include <string>

#include "UIWindow.h"

namespace UserInterface {

namespace Window {

class UIWindowRecorde : public UIWindow
{
  private:
    UserInterface::UIFonteExtendida fonteTitulo;

    UserInterface::UIFonteExtendida fonteAviso;

    UserInterface::Componente::UITecladoVirtual teclado;

    UserInterface::Componente::UITextField textNome;

    UserInterface::Componente::UINumberField textPonto;

    RankingSystem::RSRecorde recorde;

    UserInterface::Visual::UIVisualSolido * uiVisualComponentes;

    int nomePosicao;

    bool showErro;


  protected:
    void atualizar();

    //Desenha o botão de ação da janela
    void desenharForeground();

    //Desenha o conteudo da janela
    void desenharConteudo();

    //Efetua as ações de acordo com a posição do cursor
    int confirmarSelecao();


  public:
    static const int BOTAO_SALVAR;

    //Inicializa as configurações da caixa de texto
    virtual void inicializar();

    UIWindowRecorde();

    //Destrutor
    ~UIWindowRecorde();

    //Estilo Visual a ser Aplicado no Componente
    void setVisualComponentes(UserInterface::Visual::UIVisualSolido * visual);

    //Define a fonte a ser usada pelo Titulo
    void setFonteTitulo(std::string fonte);

    void setFonteTecladoVirtual(std::string fonteTeclado, std::string fonteControle);

    void setFonteEdit(std::string fonteLabel, std::string fonteValue);

    //Retorna o TopSystemRecorde
    RankingSystem::RSRecorde getRecorde();

    //Atribui um RSRecorde para complementar os dados
    void setRecorde(RankingSystem::RSRecorde recorde);

    //Gerencia o controle do cursor (navegação) e as opções selecionadas
    bool isAcao(int tipoAcao);

};

} // namespace UserInterface::Window

} // namespace UserInterface
#endif
