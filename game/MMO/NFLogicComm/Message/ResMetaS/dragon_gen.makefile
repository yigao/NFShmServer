include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_dragon_bin

${PROTOCGEN_FILE_PATH}/module_dragon_bin:${PROTOCGEN_FILE_PATH}/dragon.proto.ds ${RESDB_EXCELMMO_PATH}/dragon.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_dragon_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/dragon.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/dragon.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/DragonDescEx.h ${PROTOCGEN_FILE_PATH}/DragonDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonFragment.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonFragmentDesc.h ${PROTOCGEN_FILE_PATH}/DragonFragmentDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonDisplayDesc.h ${PROTOCGEN_FILE_PATH}/DragonDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonChange.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonChangeDesc.h ${PROTOCGEN_FILE_PATH}/DragonChangeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonLvvalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonLvvalueDesc.h ${PROTOCGEN_FILE_PATH}/DragonLvvalueDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_DragonStarvalue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/DragonStarvalueDesc.h ${PROTOCGEN_FILE_PATH}/DragonStarvalueDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_dragon_bin
