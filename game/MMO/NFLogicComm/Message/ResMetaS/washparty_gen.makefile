include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_washparty_bin

${PROTOCGEN_FILE_PATH}/module_washparty_bin:${PROTOCGEN_FILE_PATH}/washparty.proto.ds ${RESDB_EXCELMMO_PATH}/washparty.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_washparty_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/washparty.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/washparty.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/WashpartyDescEx.h ${PROTOCGEN_FILE_PATH}/WashpartyDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_WashpartyWashparty.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/WashpartyWashpartyDesc.h ${PROTOCGEN_FILE_PATH}/WashpartyWashpartyDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_WashpartyExp.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/WashpartyExpDesc.h ${PROTOCGEN_FILE_PATH}/WashpartyExpDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_washparty_bin
