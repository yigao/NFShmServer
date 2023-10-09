include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_sensitiveword_bin

${PROTOCGEN_FILE_PATH}/module_sensitiveword_bin:${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds ${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_sensitiveword_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/sensitiveword.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/sensitiveword.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/SensitivewordDescEx.h ${PROTOCGEN_FILE_PATH}/SensitivewordDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SensitivewordWord1.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SensitivewordWord1Desc.h ${PROTOCGEN_FILE_PATH}/SensitivewordWord1Desc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SensitivewordWord2.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SensitivewordWord2Desc.h ${PROTOCGEN_FILE_PATH}/SensitivewordWord2Desc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_SensitivewordWord3.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/SensitivewordWord3Desc.h ${PROTOCGEN_FILE_PATH}/SensitivewordWord3Desc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_sensitiveword_bin
