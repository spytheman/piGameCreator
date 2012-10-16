@echo off
setlocal

:: Set these variabled to the cmake exe and the mingW path
set mingw=P:\CPP\piGameCreator\baseide\release\targets\cpp\mingw
set cm=../../baseide/release/targets/cpp/cmake/bin/cmake.exe


:: Now the program follows
cls
set path=%mingw%\bin
del /q /f cppengine-cmake.exe
if exist CMakeCache.txt goto MAKE
del /q /f CMakeFiles
del CMakeCache.txt
rmdir CMakeFiles
"%cm%" .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM:string=%mingw%\bin\mingw32-make.exe
:MAKE
"%mingw%\bin\mingw32-make.exe"
if errorlevel 0 cppengine-cmake
pause
endlocal
%0