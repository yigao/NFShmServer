include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_boss_bin

${PROTOCGEN_FILE_PATH}/module_boss_bin:${PROTOCGEN_FILE_PATH}/boss.proto.ds ${RESDB_EXCELMMO_PATH}/boss.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_boss_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/boss.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/boss.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/BossDescEx.h ${PROTOCGEN_FILE_PATH}/BossDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BossRareitem.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BossRareitemDesc.h ${PROTOCGEN_FILE_PATH}/BossRareitemDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BossBosstype.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.h ${PROTOCGEN_FILE_PATH}/BossBosstypeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BossBoss.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BossBossDesc.h ${PROTOCGEN_FILE_PATH}/BossBossDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BossLayer.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BossLayerDesc.h ${PROTOCGEN_FILE_PATH}/BossLayerDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_boss_bin
