include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_Fish_bin

${PROTOCGEN_FILE_PATH}/module_Fish_bin:${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_Fish_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FishDescEx.h ${PROTOCGEN_FILE_PATH}/FishDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FishRoom.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FishRoomDesc.h ${PROTOCGEN_FILE_PATH}/FishRoomDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FishGunvalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.h ${PROTOCGEN_FILE_PATH}/FishGunvalueDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FishCtrllevel.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.h ${PROTOCGEN_FILE_PATH}/FishCtrllevelDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FishConfig.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FishConfigDesc.h ${PROTOCGEN_FILE_PATH}/FishConfigDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_Fish_bin
