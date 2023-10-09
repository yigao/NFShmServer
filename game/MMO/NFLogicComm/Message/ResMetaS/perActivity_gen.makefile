include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_perActivity_bin

${PROTOCGEN_FILE_PATH}/module_perActivity_bin:${PROTOCGEN_FILE_PATH}/perActivity.proto.ds ${RESDB_EXCELMMO_PATH}/perActivity.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_perActivity_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/perActivity.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/perActivity.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/PeractivityDescEx.h ${PROTOCGEN_FILE_PATH}/PeractivityDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PeractivityPeractivity.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityPeractivityDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PeractivityWeek.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.h ${PROTOCGEN_FILE_PATH}/PeractivityWeekDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_perActivity_bin
