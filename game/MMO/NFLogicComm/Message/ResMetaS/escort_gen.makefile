include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_escort_bin

${PROTOCGEN_FILE_PATH}/module_escort_bin:${PROTOCGEN_FILE_PATH}/escort.proto.ds ${RESDB_EXCELMMO_PATH}/escort.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_escort_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/escort.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/escort.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/EscortDescEx.h ${PROTOCGEN_FILE_PATH}/EscortDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EscortEscort.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EscortEscortDesc.h ${PROTOCGEN_FILE_PATH}/EscortEscortDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EscortChance.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EscortChanceDesc.h ${PROTOCGEN_FILE_PATH}/EscortChanceDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EscortReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EscortRewardDesc.h ${PROTOCGEN_FILE_PATH}/EscortRewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_EscortConst.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/EscortConstDesc.h ${PROTOCGEN_FILE_PATH}/EscortConstDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_escort_bin
