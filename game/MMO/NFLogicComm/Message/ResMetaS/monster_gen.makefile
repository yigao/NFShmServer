include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_monster_bin

${PROTOCGEN_FILE_PATH}/module_monster_bin:${PROTOCGEN_FILE_PATH}/monster.proto.ds ${RESDB_EXCELMMO_PATH}/monster.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_monster_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/monster.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/monster.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/MonsterDescEx.h ${PROTOCGEN_FILE_PATH}/MonsterDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MonsterMonster.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.h ${PROTOCGEN_FILE_PATH}/MonsterMonsterDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MonsterDisplay.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDisplayDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MonsterValue.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MonsterValueDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MonsterValueparam.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MonsterValueparamDesc.h ${PROTOCGEN_FILE_PATH}/MonsterValueparamDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MonsterDrop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MonsterDropDesc.h ${PROTOCGEN_FILE_PATH}/MonsterDropDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_MonsterCollect.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/MonsterCollectDesc.h ${PROTOCGEN_FILE_PATH}/MonsterCollectDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_monster_bin
