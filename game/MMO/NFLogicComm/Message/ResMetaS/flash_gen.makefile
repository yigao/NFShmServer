include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_flash_bin

${PROTOCGEN_FILE_PATH}/module_flash_bin:${PROTOCGEN_FILE_PATH}/flash.proto.ds ${RESDB_EXCELMMO_PATH}/flash.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_flash_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/flash.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/flash.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FlashDescEx.h ${PROTOCGEN_FILE_PATH}/FlashDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FlashFlash.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FlashFlashDesc.h ${PROTOCGEN_FILE_PATH}/FlashFlashDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FlashItemflash.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FlashItemflashDesc.h ${PROTOCGEN_FILE_PATH}/FlashItemflashDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_flash_bin
