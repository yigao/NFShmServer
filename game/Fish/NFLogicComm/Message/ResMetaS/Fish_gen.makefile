include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_FishRoom.bin ${PROTOCGEN_FILE_PATH}/FishRoomDesc.h ${PROTOCGEN_FILE_PATH}/FishRoomDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishGunvalue.bin ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.h ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishCtrllevel.bin ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.h ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishConfig.bin ${PROTOCGEN_FILE_PATH}/FishConfigDesc.h ${PROTOCGEN_FILE_PATH}/FishConfigDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_FishRoom.bin ${PROTOCGEN_FILE_PATH}/FishRoomDesc.h ${PROTOCGEN_FILE_PATH}/FishRoomDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishGunvalue.bin ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.h ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishCtrllevel.bin ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.h ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.cpp ${PROTOCGEN_FILE_PATH}/E_FishConfig.bin ${PROTOCGEN_FILE_PATH}/FishConfigDesc.h ${PROTOCGEN_FILE_PATH}/FishConfigDesc.cpp :${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
