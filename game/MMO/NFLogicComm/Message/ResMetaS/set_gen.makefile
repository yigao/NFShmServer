include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_set_bin

${PROTOCGEN_FILE_PATH}/module_set_bin:${PROTOCGEN_FILE_PATH}/set.proto.ds ${RESDB_EXCELMMO_PATH}/set.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_set_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/set.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/set.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/SetDescEx.h ${PROTOCGEN_FILE_PATH}/SetDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_set_bin
