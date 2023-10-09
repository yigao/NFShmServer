include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_intimacy_bin

${PROTOCGEN_FILE_PATH}/module_intimacy_bin:${PROTOCGEN_FILE_PATH}/intimacy.proto.ds ${RESDB_EXCELMMO_PATH}/intimacy.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_intimacy_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/intimacy.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/intimacy.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/IntimacyDescEx.h ${PROTOCGEN_FILE_PATH}/IntimacyDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_IntimacyIntimacy.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/IntimacyIntimacyDesc.h ${PROTOCGEN_FILE_PATH}/IntimacyIntimacyDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_IntimacyGift.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/IntimacyGiftDesc.h ${PROTOCGEN_FILE_PATH}/IntimacyGiftDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_intimacy_bin
