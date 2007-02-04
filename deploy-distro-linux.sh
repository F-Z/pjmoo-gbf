#!/bin/bash

clear
echo "Copiando Headers (.h)"
cp -f  src/*.h /opt/projeto/pjmoo/distro/include/GBF/
echo "Copiando Biblioteca libGBF.a"
cp -f  bin/linux/release/libGBF.a /opt/projeto/pjmoo/distro/lib/linux/release/libGBF.a


