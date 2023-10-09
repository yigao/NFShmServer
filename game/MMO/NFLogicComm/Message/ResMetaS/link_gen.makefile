include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_link_bin

${PROTOCGEN_FILE_PATH}/module_link_bin:${PROTOCGEN_FILE_PATH}/link.proto.ds ${RESDB_EXCELMMO_PATH}/link.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_link_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/link.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/link.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/LinkDescEx.h ${PROTOCGEN_FILE_PATH}/LinkDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_LinkLink.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/LinkLinkDesc.h ${PROTOCGEN_FILE_PATH}/LinkLinkDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_link_bin
