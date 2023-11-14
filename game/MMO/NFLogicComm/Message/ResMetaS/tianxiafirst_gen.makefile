include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin

${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin:${PROTOCGEN_FILE_PATH}/tianxiafirst.proto.ds ${RESDB_EXCELMMO_PATH}/tianxiafirst.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/tianxiafirst.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/tianxiafirst.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstDescEx.h ${PROTOCGEN_FILE_PATH}/TianxiafirstDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstActivate.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstActivateDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstActivateDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstStrong.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstStrongDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstStrongDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstStrongitem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstStrongitemDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstStrongitemDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_TianxiafirstRefine.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/TianxiafirstRefineDesc.h ${PROTOCGEN_FILE_PATH}/TianxiafirstRefineDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_tianxiafirst_bin
