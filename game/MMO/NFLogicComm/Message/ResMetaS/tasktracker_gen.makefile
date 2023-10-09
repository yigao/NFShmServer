include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_tasktracker_bin

${PROTOCGEN_FILE_PATH}/module_tasktracker_bin:${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds ${RESDB_EXCELMMO_PATH}/tasktracker.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_tasktracker_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/tasktracker.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/tasktracker.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TasktrackerDescEx.h ${PROTOCGEN_FILE_PATH}/TasktrackerDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TasktrackerTasktracker.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TasktrackerTasktrackerDesc.h ${PROTOCGEN_FILE_PATH}/TasktrackerTasktrackerDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_tasktracker_bin
