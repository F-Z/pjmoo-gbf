@echo off
@cls
set DISTRO=X:\Desenvolvimento\Cpp\PJMOO\distro

echo Copiando Headers (.h)
@copy /Y src\*.h "%DISTRO%"\include\GBF\*.h

echo Copiando Biblioteca libGBF.a
@copy /Y bin\win32\release\libGBF.a "%DISTRO%"\lib\win32\release\libGBF.a


