REM I Commenti si scrivono con REM
REM Per fare le deploy su una macchina virtuale con le seguenti caratteristiche
REM MSVC 2008
REM Qt4.7.3 compilato statico con MSVC2008
REM La cartella dove si trova l'eseguibile di Visual Studio è C:\Program Files (x86)\Microsoft Visual Studio 9.0\Common7\IDE
REM Per potere lanciare questo eseguibile si deve mettere nella PATH di Windows (Impostazione variabili d'ambiente)
@echo on
cd build
del /F /S /Q Debug
del /F /S /Q Release
cd..

del /F /S /Q GraphInsight* Package* ZeroCheck*  install*  PACKAGE.dir CMakeFiles _CPack_Packages*

devenv.exe GraphInsight.sln /Clean Debug
devenv.exe GraphInsight.sln /Clean Release

REM Crea l'installer per la versione TRIAL GraphInsight-TRIAL_LICENSE-1.3.0-win32.exe 
cmake -DCMAKE_BUILD_TYPE=Release -DLICENSE_TYPE=Trial .
devenv.exe GraphInsight.sln /Build Release /project package

del /F /S /Q Package* ZeroCheck*  install*  PACKAGE.dir CMakeFiles _CPack_Packages* Debug Release
devenv.exe GraphInsight.sln /Clean Debug
devenv.exe GraphInsight.sln /Clean Release


REM Crea l'installer per la versione ACADEMIC GraphInsight-ACADEMIC_LICENSE-1.3.0-win32.exe 
cmake -DCMAKE_BUILD_TYPE=Release -DLICENSE_TYPE=Academic .
devenv.exe GraphInsight.sln /Build Release /project package

del /F /S /Q Package* ZeroCheck*  install*  PACKAGE.dir CMakeFiles _CPack_Packages* Debug Release
devenv.exe GraphInsight.sln /Clean Debug
devenv.exe GraphInsight.sln /Clean Release

REM Crea l'installer per la versione PROFESSIONAL GraphInsight-PROFESSIONAL_LICENSE-1.3.0-win32.exe 
cmake -DCMAKE_BUILD_TYPE=Release -DLICENSE_TYPE=Pro .
devenv.exe GraphInsight.sln /Build Release /project package
