include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_Godvalley_bin

${PROTOCGEN_FILE_PATH}/module_Godvalley_bin:${PROTOCGEN_FILE_PATH}/Godvalley.proto.ds ${RESDB_EXCELMMO_PATH}/Godvalley.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_Godvalley_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/Godvalley.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/Godvalley.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/GodvalleyDescEx.h ${PROTOCGEN_FILE_PATH}/GodvalleyDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GodvalleyBattle.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GodvalleyBattleDesc.h ${PROTOCGEN_FILE_PATH}/GodvalleyBattleDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GodvalleyRewards.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GodvalleyRewardsDesc.h ${PROTOCGEN_FILE_PATH}/GodvalleyRewardsDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_GodvalleyAttribute.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/GodvalleyAttributeDesc.h ${PROTOCGEN_FILE_PATH}/GodvalleyAttributeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_Godvalley_bin
