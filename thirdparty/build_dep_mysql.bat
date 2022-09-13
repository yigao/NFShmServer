@echo off
echo Building dependencies...

cd mysql
md build
cd build
cmake -G "Visual Studio 15 2017 Win64" ..

cd ..
cd ..


pause