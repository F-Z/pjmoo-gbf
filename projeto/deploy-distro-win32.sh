#!/bin/bash
export VERSION=0.9.1
export GBF=/home/desenvolvimento/pjmoo-gbf/
export WORKSPACE=$GBF/trunk/projeto/
export WORKVERSION=$GBF/tags/$VERSION

clear
echo "Criando estrutura de Arquivos..."
mkdir $WORKVERSION
mkdir $WORKVERSION/win32
mkdir $WORKVERSION/win32/lib


echo "Copiando: Biblioteca libGBF.a"
cp -f $WORKSPACE/bin/win32/release/libGBF.a $WORKVERSION/win32/lib/libGBF.a

cd $WORKVERSION/win32
echo "Empacotando: Para distribuição Zip"
zip -rq7 $WORKVERSION/GBF.library.$VERSION.win32.zip lib/* -x *SVN* *svnignore* *.svn*

echo "Removendo arquivos temporarios..."
rm -r $WORKVERSION/win32

echo "Finalizado"