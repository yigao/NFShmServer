include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_login_bin

${PROTOCGEN_FILE_PATH}/module_login_bin:${PROTOCGEN_FILE_PATH}/login.proto.ds ${RESDB_EXCELMMO_PATH}/login.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_login_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/login.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/login.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/LoginDescEx.h ${PROTOCGEN_FILE_PATH}/LoginDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_login_bin
