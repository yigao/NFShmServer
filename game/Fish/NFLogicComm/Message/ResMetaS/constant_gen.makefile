include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_constant_bin

${PROTOCGEN_FILE_PATH}/module_constant_bin:${PROTOCGEN_FILE_PATH}/constant.proto.ds ${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_constant_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/constant.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ConstantConstant.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.h ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_constant_bin
