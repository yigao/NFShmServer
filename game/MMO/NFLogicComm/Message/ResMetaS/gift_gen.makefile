include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_gift_bin

${PROTOCGEN_FILE_PATH}/module_gift_bin:${PROTOCGEN_FILE_PATH}/gift.proto.ds ${RESDB_EXCELMMO_PATH}/gift.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_gift_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/gift.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/gift.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/GiftDescEx.h ${PROTOCGEN_FILE_PATH}/GiftDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GiftFree.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GiftFreeDesc.h ${PROTOCGEN_FILE_PATH}/GiftFreeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GiftCondition.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GiftConditionDesc.h ${PROTOCGEN_FILE_PATH}/GiftConditionDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GiftMust.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GiftMustDesc.h ${PROTOCGEN_FILE_PATH}/GiftMustDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_gift_bin
