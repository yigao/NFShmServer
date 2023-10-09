include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_decorate_bin

${PROTOCGEN_FILE_PATH}/module_decorate_bin:${PROTOCGEN_FILE_PATH}/decorate.proto.ds ${RESDB_EXCELMMO_PATH}/decorate.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_decorate_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/decorate.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/decorate.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/DecorateDescEx.h ${PROTOCGEN_FILE_PATH}/DecorateDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DecorateDecorate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DecorateDecorateDesc.h ${PROTOCGEN_FILE_PATH}/DecorateDecorateDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_decorate_bin
