#!/bin/bash
export PROJETO=/home/desenvolvimento/pjmoo-gbf/trunk/projeto
cd $PROJETO
clear
echo "Copiando Headers (.h)"
cp -f  src/*.h /usr/include/GBF/
echo "Copiando Biblioteca libGBF.a"
#cp -f bin/linux/release/libGBF.a /usr/lib/libGBF.a
cp -f bin/linux/debug/libGBF.a /usr/lib/libGBF.a

