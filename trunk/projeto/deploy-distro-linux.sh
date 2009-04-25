#!/bin/bash
export VERSION=0.9.1
export GBF=/home/desenvolvimento/pjmoo-gbf/
export WORKSPACE=$GBF/trunk/projeto/
export WORKVERSION=$GBF/tags/$VERSION

clear
echo "Criando estrutura de Arquivos..."
mkdir $WORKVERSION
mkdir $WORKVERSION/include
mkdir $WORKVERSION/include/GBF
mkdir $WORKVERSION/linux
mkdir $WORKVERSION/linux/lib

echo "Copiando: Headers (.h)"
cp -f $WORKSPACE/src/*.h $WORKVERSION/include/GBF

echo "Copiando: Biblioteca libGBF.a"
cp -f $WORKSPACE/bin/linux/release/libGBF.a $WORKVERSION/linux/lib/libGBF.a

cd $WORKVERSION
echo "Empacotando: Para distribuição Zip"
zip -rq7 $WORKVERSION/GBF.include.$VERSION.zip include/* -x *SVN* *svnignore* *.svn*
cd $WORKVERSION/linux
zip -rq7 $WORKVERSION/GBF.library.$VERSION.linux.zip lib/* -x *SVN* *svnignore* *.svn*

echo "Removendo arquivos temporarios..."
rm -r $WORKVERSION/include
rm -r $WORKVERSION/linux

echo "Finalizado"