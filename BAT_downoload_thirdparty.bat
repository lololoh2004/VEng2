@echo off
chcp 65001 > nul

echo Cloning my libs
git clone --depth 1 https://github.com/lololoh2004/raysdl3 "lib/rsdl"
git clone --depth 1 https://github.com/lololoh2004/LolohUtilsPack "lib/LoUtils"
git clone --depth 1 https://github.com/lololoh2004/MSWLua "lib/MSWLua"



echo Cloning my binary builds
set "LUA_VER=1"

curl -L -O "https://github.com/lololoh2004/luajit_bin/releases/download/%LUA_VER%/win_x64.tar.gz"
curl -L -O "https://github.com/lololoh2004/luajit_bin/releases/download/%LUA_VER%/lin_x64.tar.gz"

mkdir temp_bin

tar -xf win_x64.tar.gz -C temp_bin
tar -xf lin_x64.tar.gz -C temp_bin

move /y "temp_bin\win_x64\lua51.dll" "."
move /y "temp_bin\lin_x64\lua51.so" "."

rmdir /s /q temp_bin
del win_x64.tar.gz
del lin_x64.tar.gz



echo Cloning other libs
git clone --depth 1 https://github.com/icculus/physfs "lib/physfs"

pause