mkdir Build
cd Build
mkdir Lib

mkdir build64_release
cd build64_release
rm * -rf

cmake -Wno-dev -DCMAKE_BUILD_TYPE=Release ../
make -j4

cd ..
