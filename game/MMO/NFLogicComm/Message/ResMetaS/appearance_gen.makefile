include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_appearance_bin

${PROTOCGEN_FILE_PATH}/module_appearance_bin:${PROTOCGEN_FILE_PATH}/appearance.proto.ds ${RESDB_EXCELMMO_PATH}/appearance.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_appearance_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/appearance.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/appearance.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/AppearanceDescEx.h ${PROTOCGEN_FILE_PATH}/AppearanceDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_appearance_bin
