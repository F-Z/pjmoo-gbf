@echo off
@cls
set DISTRO=C:\Projeto\pjmoo\distro

echo Preparando arquivos para o repositorio de distribuição...

echo Copiando: Biblioteca libGBF.a
@copy /Y bin\win32\release\libGBF.a "%DISTRO%"\lib\win32\release\libGBF.a

echo Copiando: Headers (.h)
@copy /Y src\*.h "%DISTRO%"\include\GBF\*.h
