include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_button_bin

${PROTOCGEN_FILE_PATH}/module_button_bin:${PROTOCGEN_FILE_PATH}/button.proto.ds ${RESDB_EXCELMMO_PATH}/button.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_button_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/button.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/button.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/ButtonDescEx.h ${PROTOCGEN_FILE_PATH}/ButtonDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ButtonButton.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ButtonButtonDesc.h ${PROTOCGEN_FILE_PATH}/ButtonButtonDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_button_bin
