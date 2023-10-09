include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_taskreward_bin

${PROTOCGEN_FILE_PATH}/module_taskreward_bin:${PROTOCGEN_FILE_PATH}/taskreward.proto.ds ${RESDB_EXCELMMO_PATH}/taskreward.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_taskreward_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/taskreward.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskreward.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TaskrewardDescEx.h ${PROTOCGEN_FILE_PATH}/TaskrewardDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TaskrewardTaskreward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TaskrewardTaskrewardDesc.h ${PROTOCGEN_FILE_PATH}/TaskrewardTaskrewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TaskrewardTasktype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TaskrewardTasktypeDesc.h ${PROTOCGEN_FILE_PATH}/TaskrewardTasktypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_taskreward_bin
