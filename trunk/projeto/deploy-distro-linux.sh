#!/bin/bash

clear
echo "Preparando arquivos para o repositorio de distribuição..."

echo "Copiando: Biblioteca libGBF.a"
cp -f  bin/linux/release/libGBF.a /home/desenvolvimento/pjmoo/distro/lib/linux/release/libGBF.a

echo "Copiando: Headers (.h)"
cp -f  src/*.h /home/desenvolvimento/pjmoo/distro/include/GBF
