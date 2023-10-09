include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_collect_bin

${PROTOCGEN_FILE_PATH}/module_collect_bin:${PROTOCGEN_FILE_PATH}/collect.proto.ds ${RESDB_EXCELMMO_PATH}/collect.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_collect_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/collect.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/collect.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/CollectDescEx.h ${PROTOCGEN_FILE_PATH}/CollectDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_CollectCollect.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/CollectCollectDesc.h ${PROTOCGEN_FILE_PATH}/CollectCollectDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_CollectAttributetpye.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/CollectAttributetpyeDesc.h ${PROTOCGEN_FILE_PATH}/CollectAttributetpyeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_collect_bin
