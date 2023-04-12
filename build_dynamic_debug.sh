cd src/NFComm/makefiles
make
cd ../../..
cd src/NFServerComm/makefiles
make
cd ../../..

mkdir Build
cd Build
mkdir Lib

mkdir build64_debug
cd build64_debug
rm * -rf

cmake -Wno-dev -DCMAKE_BUILD_TYPE=DynamicDebug  ../..
make -j16
