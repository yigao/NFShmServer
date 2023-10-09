include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_task_bin

${PROTOCGEN_FILE_PATH}/module_task_bin:${PROTOCGEN_FILE_PATH}/task.proto.ds ${RESDB_EXCELMMO_PATH}/task.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_task_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/task.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/task.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TaskDescEx.h ${PROTOCGEN_FILE_PATH}/TaskDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TaskTask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TaskTaskDesc.h ${PROTOCGEN_FILE_PATH}/TaskTaskDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_task_bin
