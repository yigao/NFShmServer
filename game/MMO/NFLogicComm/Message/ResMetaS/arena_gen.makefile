include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/module_arena_bin

${PROTOCGEN_FILE_PATH}/module_arena_bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	rm -rf ${PROTOCGEN_FILE_PATH}/module_arena_bin
	${NFEXCELPROCESS} --work="exceltobin" --src=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --dst=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --work="filecopy_notexist" --src="${PROTOCGEN_FILE_PATH}/ArenaDescEx.h ${PROTOCGEN_FILE_PATH}/ArenaDescEx.cpp" --dst=${DESC_STORE_EX_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ArenaRobot.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ArenaRobotfacade.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ArenaRobotfacadeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotfacadeDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ArenaArenaward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ArenaRankaward.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ArenaFirstrank.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.h ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.cpp" --dst=${DESC_STORE_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/E_ArenaBuychallenge.bin" --dst=${GAME_DATA_PATH}/
	${FILE_COPY_EXE} --work="filecopy" --src="${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.cpp" --dst=${DESC_STORE_PATH}/
	touch ${PROTOCGEN_FILE_PATH}/module_arena_bin
