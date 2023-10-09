include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_area_bin

${PROTOCGEN_FILE_PATH}/module_area_bin:${PROTOCGEN_FILE_PATH}/area.proto.ds ${RESDB_EXCELMMO_PATH}/area.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_area_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/area.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/area.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AreaDescEx.h ${PROTOCGEN_FILE_PATH}/AreaDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_AreaArea.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/AreaAreaDesc.h ${PROTOCGEN_FILE_PATH}/AreaAreaDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_area_bin
