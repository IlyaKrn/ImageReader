@echo off
call cmake -G "MinGW Makefiles" -B ./build
cd build/
call mingw32-make
rmdir /s /q run
mkdir run
echo f | xcopy /s viewer\viewer.exe run\viewer.exe
echo f | xcopy /s libs\sdl\build\SDL2.dll run\SDL2.dll
cd run
call viewer c:/users/ilyakrn/desktop/test.txt