include ./define.makefile

.PHONY:all

all:${PROTOCGEN_FILE_PATH}/arenarobot.bin ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.cpp ${PROTOCGEN_FILE_PATH}/arenarankaward.bin ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.cpp ${PROTOCGEN_FILE_PATH}/arenaarenAward.bin ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.cpp ${PROTOCGEN_FILE_PATH}/arenafirstrank.bin ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.h ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.cpp ${PROTOCGEN_FILE_PATH}/arenabuychallenge.bin ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.cpp 

${PROTOCGEN_FILE_PATH}/arenarobot.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenarobot  --excel_sheetname=robot  --proto_msgname=arenarobot  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arenarobot.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.cpp:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRobotDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/arenarankaward.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenarankaward  --excel_sheetname=rankaward  --proto_msgname=arenarankaward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arenarankaward.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.cpp:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaRankawardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/arenaarenAward.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenaarenAward  --excel_sheetname=arenAward  --proto_msgname=arenaarenAward  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arenaarenAward.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.cpp:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.h ${PROTOCGEN_FILE_PATH}/ArenaArenawardDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/arenafirstrank.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenafirstrank  --excel_sheetname=firstrank  --proto_msgname=arenafirstrank  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arenafirstrank.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.h ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.cpp:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.h ${PROTOCGEN_FILE_PATH}/ArenaFirstrankDesc.cpp" --dst=${DESC_STORE_PATH}/

${PROTOCGEN_FILE_PATH}/arenabuychallenge.bin:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/arena.xlsx  --proto_ds=${PROTOCGEN_FILE_PATH}/arena.proto.ds --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_arenabuychallenge  --excel_sheetname=buychallenge  --proto_msgname=arenabuychallenge  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/arenabuychallenge.bin" --dst=${GAME_DATA_PATH}/

${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.cpp:${PROTOCGEN_FILE_PATH}/arena.proto.ds ${RESDB_EXCELMMO_PATH}/arena.xlsx
	mkdir -p ${PROTOCGEN_FILE_PATH}
	${FILE_COPY_EXE} --src="${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.h ${PROTOCGEN_FILE_PATH}/ArenaBuychallengeDesc.cpp" --dst=${DESC_STORE_PATH}/

