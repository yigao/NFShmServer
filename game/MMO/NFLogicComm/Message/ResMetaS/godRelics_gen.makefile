include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_godRelics_bin

${PROTOCGEN_FILE_PATH}/module_godRelics_bin:${PROTOCGEN_FILE_PATH}/godRelics.proto.ds ${RESDB_EXCELMMO_PATH}/godRelics.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_godRelics_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/godRelics.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/godRelics.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/GodrelicsDescEx.h ${PROTOCGEN_FILE_PATH}/GodrelicsDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GodrelicsGodrelics.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GodrelicsGodrelicsDesc.h ${PROTOCGEN_FILE_PATH}/GodrelicsGodrelicsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GodrelicsCondition.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GodrelicsConditionDesc.h ${PROTOCGEN_FILE_PATH}/GodrelicsConditionDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_godRelics_bin
