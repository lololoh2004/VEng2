@echo off

git clone --depth 1 https://github.com/lololoh2004/LolohUtilsPack "lib/LoUtils"
git clone --depth 1 https://github.com/lololoh2004/MSWLua "lib/MSWLua"
git clone --depth 1 https://github.com/icculus/physfs "lib/physfs"

@REM git clone --depth 1 https://github.com/lololoh2004/raysdl3 "lib/rsdl"
@REM
@REM git clone --depth 1 https://github.com/libsdl-org/SDL "lib/SDL3"
@REM git clone --depth 1 https://github.com/libsdl-org/SDL_shadercross "lib/SDL3_shadercross"
@REM
@REM powershell -ExecutionPolicy Bypass -File lib\SDL3_shadercross\external\Get-GitModules.ps1

git clone --depth 1 https://github.com/lololoh2004/VEngBinary "lib/VEngBinary"

pause