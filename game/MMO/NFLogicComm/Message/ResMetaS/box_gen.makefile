include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_box_bin

${PROTOCGEN_FILE_PATH}/module_box_bin:${PROTOCGEN_FILE_PATH}/box.proto.ds ${RESDB_EXCELMMO_PATH}/box.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_box_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/box.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/box.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/BoxDescEx.h ${PROTOCGEN_FILE_PATH}/BoxDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BoxBox.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BoxBoxDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BoxBoxdata.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BoxBoxdataDesc.h ${PROTOCGEN_FILE_PATH}/BoxBoxdataDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_box_bin
