include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_taskdynamic_bin

${PROTOCGEN_FILE_PATH}/module_taskdynamic_bin:${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds ${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_taskdynamic_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/taskdynamic.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/taskdynamic.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TaskdynamicDescEx.h ${PROTOCGEN_FILE_PATH}/TaskdynamicDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskdynamic.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskdynamicDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TaskdynamicTaskcomcond.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTaskcomcondDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TaskdynamicTasktext.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.h ${PROTOCGEN_FILE_PATH}/TaskdynamicTasktextDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_taskdynamic_bin
