include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_jinglian_bin

${PROTOCGEN_FILE_PATH}/module_jinglian_bin:${PROTOCGEN_FILE_PATH}/jinglian.proto.ds ${RESDB_EXCELMMO_PATH}/jinglian.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_jinglian_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/jinglian.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/jinglian.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/JinglianDescEx.h ${PROTOCGEN_FILE_PATH}/JinglianDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_JinglianSimple.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/JinglianSimpleDesc.h ${PROTOCGEN_FILE_PATH}/JinglianSimpleDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_JinglianLv.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/JinglianLvDesc.h ${PROTOCGEN_FILE_PATH}/JinglianLvDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_JinglianRace.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/JinglianRaceDesc.h ${PROTOCGEN_FILE_PATH}/JinglianRaceDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_JinglianCost.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/JinglianCostDesc.h ${PROTOCGEN_FILE_PATH}/JinglianCostDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_JinglianGm.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/JinglianGmDesc.h ${PROTOCGEN_FILE_PATH}/JinglianGmDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_jinglian_bin
