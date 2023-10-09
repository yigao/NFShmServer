include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_title_bin

${PROTOCGEN_FILE_PATH}/module_title_bin:${PROTOCGEN_FILE_PATH}/title.proto.ds ${RESDB_EXCELMMO_PATH}/title.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_title_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/title.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/title.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TitleDescEx.h ${PROTOCGEN_FILE_PATH}/TitleDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TitleType.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TitleTypeDesc.h ${PROTOCGEN_FILE_PATH}/TitleTypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TitleTitle.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TitleTitleDesc.h ${PROTOCGEN_FILE_PATH}/TitleTitleDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_title_bin
