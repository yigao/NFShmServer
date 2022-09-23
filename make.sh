cd src/NFComm/makefiles
make
cd ../../..
cd src/NFServerComm/makefiles
make
cd ../../..
cd game/MMO/NFLogicComm/makefiles
make
cd ../../../..

cd Build/build64_debug
make -j4
