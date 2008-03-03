#!/bin/bash

export GBF=/home/desenvolvimento/pjmoo-gbf/

export GBF_CURRENT=$GBF/tags/current/
export GBF_DEVELOPMENT=$GBF/trunk/projeto/

export GBF_SRC=$GBF_DEVELOPMENT/src/
export GBF_DISTRO_HEADERS=$GBF_CURRENT/include/

clear
echo "Preparando arquivos para o repositorio de distribuição..."

echo "Copiando: Biblioteca libGBF.a"
cp -f $GBF_DEVELOPMENT/bin/linux/release/libGBF.a $GBF_CURRENT/linux/libGBF.a

echo "Copiando: Headers (.h)"
cp -f  $GBF_SRC/*.h  $GBF_DISTRO_HEADERS
