include ./define.makefile

.PHONY:all

all:module

module:${PROTOCGEN_FILE_PATH}/Fish.proto.ds ${RESDB_EXCELMMO_PATH}/Fish.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/Fish.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Fish.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
