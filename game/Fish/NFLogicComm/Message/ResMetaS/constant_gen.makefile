include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/E_ConstantConstant.bin ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.h ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.cpp 

${PROTOCGEN_FILE_PATH}/E_ConstantConstant.bin ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.h ${PROTOCGEN_FILE_PATH}/ConstantConstantDesc.cpp :${PROTOCGEN_FILE_PATH}/constant.proto.ds ${RESDB_EXCELMMO_PATH}/constant.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/constant.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/constant.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
