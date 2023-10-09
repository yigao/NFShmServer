include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_path_bin

${PROTOCGEN_FILE_PATH}/module_path_bin:${PROTOCGEN_FILE_PATH}/path.proto.ds ${RESDB_EXCELMMO_PATH}/path.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_path_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/path.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/path.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/PathDescEx.h ${PROTOCGEN_FILE_PATH}/PathDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_PathPath.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/PathPathDesc.h ${PROTOCGEN_FILE_PATH}/PathPathDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_path_bin
