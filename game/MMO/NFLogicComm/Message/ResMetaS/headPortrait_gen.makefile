include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_headPortrait_bin

${PROTOCGEN_FILE_PATH}/module_headPortrait_bin:${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds ${RESDB_EXCELMMO_PATH}/headPortrait.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_headPortrait_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/headPortrait.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/headPortrait.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/HeadportraitDescEx.h ${PROTOCGEN_FILE_PATH}/HeadportraitDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_HeadportraitHead.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.h ${PROTOCGEN_FILE_PATH}/HeadportraitHeadDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_headPortrait_bin
