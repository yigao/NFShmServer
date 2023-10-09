include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_fashion_bin

${PROTOCGEN_FILE_PATH}/module_fashion_bin:${PROTOCGEN_FILE_PATH}/fashion.proto.ds ${RESDB_EXCELMMO_PATH}/fashion.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_fashion_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/fashion.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/fashion.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/FashionDescEx.h ${PROTOCGEN_FILE_PATH}/FashionDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_FashionFashion.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/FashionFashionDesc.h ${PROTOCGEN_FILE_PATH}/FashionFashionDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_fashion_bin
