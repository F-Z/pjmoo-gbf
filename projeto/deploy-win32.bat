@echo off
@cls
set MINGW=C:\SDK\Cpp\CodeBlocks

echo Copiando Headers (.h)
@copy /Y src\*.h "%MINGW%"\include\GBF\*.h

echo Copiando Biblioteca libGBF.a
@copy /Y bin\win32\release\libGBF.a "%MINGW%"\lib\libGBF.a
REM @copy /Y bin\win32\debug\libGBF.a "%MINGW%"\lib\libGBF.a

