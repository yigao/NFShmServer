include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_battlePass_bin

${PROTOCGEN_FILE_PATH}/module_battlePass_bin:${PROTOCGEN_FILE_PATH}/battlePass.proto.ds ${RESDB_EXCELMMO_PATH}/battlePass.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_battlePass_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/battlePass.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/battlePass.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/BattlepassDescEx.h ${PROTOCGEN_FILE_PATH}/BattlepassDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BattlepassBattlepass.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BattlepassBattlepassDesc.h ${PROTOCGEN_FILE_PATH}/BattlepassBattlepassDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BattlepassReward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BattlepassRewardDesc.h ${PROTOCGEN_FILE_PATH}/BattlepassRewardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BattlepassTask.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BattlepassTaskDesc.h ${PROTOCGEN_FILE_PATH}/BattlepassTaskDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_BattlepassShop.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/BattlepassShopDesc.h ${PROTOCGEN_FILE_PATH}/BattlepassShopDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_battlePass_bin
