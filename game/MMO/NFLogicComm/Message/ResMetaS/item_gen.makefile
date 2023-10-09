include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_item_bin

${PROTOCGEN_FILE_PATH}/module_item_bin:${PROTOCGEN_FILE_PATH}/item.proto.ds ${RESDB_EXCELMMO_PATH}/item.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_item_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/item.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/item.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/ItemDescEx.h ${PROTOCGEN_FILE_PATH}/ItemDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ItemItem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ItemItemDesc.h ${PROTOCGEN_FILE_PATH}/ItemItemDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_item_bin
