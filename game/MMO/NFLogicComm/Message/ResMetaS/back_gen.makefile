include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_back_bin

${PROTOCGEN_FILE_PATH}/module_back_bin:${PROTOCGEN_FILE_PATH}/back.proto.ds ${RESDB_EXCELMMO_PATH}/back.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_back_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/back.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/back.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/BackDescEx.h ${PROTOCGEN_FILE_PATH}/BackDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BackBack.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BackBackDesc.h ${PROTOCGEN_FILE_PATH}/BackBackDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_back_bin
